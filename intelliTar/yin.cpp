#include <TFT_eSPI.h>
#include <Arduino.h>
#include <WiFi.h>
#include <HardwareSerial.h>

const char *ssid = "TP-LINK_3920";
const char *password = "dyyzshq815";

const int MIC = 35;
const int bufferSize = 1024;
const float cmndfThreshold = 0.2;
int sampleRate = 11000;
int buffer[bufferSize];
float df[bufferSize / 2];    // 差函数的数组
float cmndf[bufferSize / 2]; // 累积平方差函数的数组
int tauEstimate = 0;
float pitchEstimate = 0;
float yinAlgorithm();

float targetPitch = 146.83;
float currentPitch = 0;

HardwareSerial SerialPort(1);

TFT_eSPI tft; // 创建TFT_eSPI对象

void drawTuner(float targetPitch, float currentPitch);
void drawPointer(float angle, uint16_t color);
void drawUI();

void setup()
{
    Serial.begin(115200);
    tft.begin();               // 初始化显示屏
    tft.setRotation(3);        // 设置显示屏旋转角度（根据实际情况调整）
    tft.fillScreen(TFT_BLACK); // 填充黑色背景

    SerialPort.begin(9600, SERIAL_8N1, 4, 2);
    // WiFi.begin(ssid, password);
    // while (WiFi.status() != WL_CONNECTED)
    // {
    //     delay(500);
    //     Serial.print(".");
    // }
}

void loop()
{
    if (SerialPort.available() > 0)
    {
        String temp = SerialPort.readString();
        Serial.println(temp);
    }
        while (analogRead(MIC) < 2000)
        {};
    pitchEstimate = 0;
    while (pitchEstimate == 0)
    {
        int time0 = millis();
        for (int i = 0; i < bufferSize; i++)
        {
            buffer[i] = analogRead(MIC);
        }
        sampleRate = bufferSize * 1000 / (millis() - time0);
        pitchEstimate = yinAlgorithm();
    }
    Serial.println("Estimated Pitch: ");
    Serial.println(pitchEstimate);
    // 主循环代码（用于更新音高显示和指针位置）
    if (pitchEstimate > 50 && pitchEstimate < 500)
    {
        currentPitch = pitchEstimate;
    }
    drawTuner(targetPitch, currentPitch);
    // 延迟一段时间
    delay(500);
}

void drawTuner(float targetPitch, float currentPitch)
{
    tft.fillScreen(TFT_BLACK); // 清空屏幕

    // 设置文本颜色和大小
    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(1);

    // 绘制仪表盘
    int centerX = tft.width() / 2;
    int centerY = tft.height() / 2;
    int radius = 50;
    tft.drawArc(centerX, centerY, radius, radius - 3, 90, 270, TFT_WHITE, 3, 0);
    tft.fillCircle(centerX, centerY, 3, TFT_WHITE);

    // 绘制刻度线
    int numTicks = 25;                           // 刻度线数量
    int tickLength = 3;                          // 刻度线长度
    int tickDistance = 180 / (numTicks - 1);     // 刻度线之间的角度距离
    int tickStartRadius = radius - 5;            // 刻度线起始半径
    int tickEndRadius = radius - tickLength - 2; // 刻度线终止半径

    for (int i = 0; i <= numTicks + 1; i++)
    {
        float angle = i * tickDistance;
        float rad = angle * PI / 180.0;

        int startX = centerX + tickStartRadius * sin(rad + PI / 2);
        int startY = centerY + tickStartRadius * cos(rad + PI / 2);
        int endX = centerX + tickEndRadius * sin(rad + PI / 2);
        int endY = centerY + tickEndRadius * cos(rad + PI / 2);

        tft.drawLine(startX, startY, endX, endY, TFT_LIGHTGREY);
    }

    // 显示标题
    tft.setCursor(5, 5);
    tft.println("Tuner");

    // 显示音高标签
    tft.setCursor(centerX - 8, centerY + 8);
    tft.println("Pitch:");

    // 显示音高数值
    tft.setCursor(centerX - 10, centerY + 23);
    tft.print(targetPitch);
    tft.print(" Hz");

    // 绘制当前音高指针
    float targetAngle = map(targetPitch, 0, 500, 90, 270);   // 将0-100的音高范围映射到-90到90的角度范围
    float currentAngle = map(currentPitch, 0, 500, 90, 270); // 将0-100的音高范围映射到-90到90的角度范围

    drawPointer(targetAngle, TFT_BLUE);
    drawPointer(currentAngle, TFT_RED);

    if (abs(targetPitch - currentPitch) <= 5)
    {
        tft.setCursor(30, 100);
        tft.println("Tuning finished!");
    }
    if (abs(targetPitch - currentPitch) <= 20 && abs(targetPitch - currentPitch) > 10)
    {
        tft.setCursor(45, 100);
        tft.setTextColor(TFT_ORANGE);
        if (targetPitch > currentPitch)
        {
            tft.setCursor(45, 100);
            tft.println("Tune up!");
        }
        else
        {
            tft.setCursor(45, 100);
            tft.println("Tune down!");
        }
    }
    if (abs(targetPitch - currentPitch) <= 10 && abs(targetPitch - currentPitch) > 5)
    {
        tft.setCursor(45, 100);
        tft.setTextColor(TFT_GREEN);
        if (targetPitch > currentPitch)
        {
            tft.setCursor(45, 100);
            tft.println("Tune up!");
        }
        else
        {
            tft.setCursor(45, 100);
            tft.println("Tune down!");
        }
    }
    if (abs(targetPitch - currentPitch) > 20)
    {
        tft.setCursor(50, 50);
        tft.setTextColor(TFT_RED);
        if (targetPitch > currentPitch)
        {
            tft.setCursor(45, 100);
            tft.println("Tune up!");
        }
        else
        {
            tft.setCursor(45, 100);
            tft.println("Tune down!");
        }
    }
}

void drawPointer(float angle, uint16_t color)
{
    int centerX = tft.width() / 2;
    int centerY = tft.height() / 2;
    int radius = 70;
    int pointerLength = radius - 20;

    // 计算指针的起点坐标
    int startX = centerX;
    int startY = centerY;

    // 计算指针的终点坐标
    float rad = angle * PI / 180.0;
    int endX = centerX + pointerLength * sin(rad);
    int endY = centerY + pointerLength * cos(rad);

    // 绘制指针
    tft.drawLine(startX, startY, endX, endY, color);
}

float yinAlgorithm()
{
    // 计算差函数
    for (int tau = 0; tau < bufferSize / 2; tau++)
    {
        df[tau] = 0; // 初始化差函数
        for (int i = 0; i < bufferSize / 2; i++)
        {
            int index1 = i;
            int index2 = i + tau;
            df[tau] += (buffer[index1] - buffer[index2]) * (buffer[index1] - buffer[index2]);
        }
    }
    // 计算累积平方差函数
    cmndf[0] = df[0];
    for (int tau = 1; tau < bufferSize / 2; tau++)
    {
        float cm = 0;
        for (int j = 1; j < tau; j++)
        {
            cm += df[j] / tau;
        }
        cmndf[tau] = df[tau] / cm;
    }

    int taumax = 0;

    for (int i = 2; i < bufferSize / 2; i++)
    {
        if (cmndf[i] < cmndfThreshold && cmndf[i] < cmndf[i - 1] && cmndf[i] < cmndf[i + 1])
        {
            taumax = i;
            break;
        }
    }

    if (taumax == 0)
    {
        Serial.println("No pitch detected");
        return 0;
    }

    // 插值计算精确的周期
    if (taumax != bufferSize / 2 && taumax)
    {
        float delta = df[taumax + 1] - df[taumax - 1];
        pitchEstimate = sampleRate / (taumax + (delta / (2 * delta - df[taumax])));
    }
    else
    {
        pitchEstimate = 0;
    }

    return pitchEstimate;
}