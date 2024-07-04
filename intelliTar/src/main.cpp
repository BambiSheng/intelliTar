// ————————————————————————————————————————————————头文件————————————————————————————————————————————————//
#include <intelliTar.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
#include <vector>
#include <uklScore.h>
#include "testscore.h"
#include <arduinoFFT.h>
// ————————————————————————————————————————————————变量定义————————————————————————————————————————————————//
//  定义分辨率
static const uint16_t screenWidth = 480;
static const uint16_t screenHeight = 320;

// 定义屏幕缓冲
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * 10];

// 旋转编码器输入
int lastpos = 0;
int time0 = 0;
int time1 = 0;
int click = 0;
int posState = 0;

// 节拍器变量
int MetroPointerAngle = 100; // 节拍器角度
int bpm;
int beepPin = 13;    // 蜂鸣器引脚
int switchState = 0; // 开关状态

// 调音器变量
int frequency = 0;
int TunerPointerAngle = 100; // 调音器角度
int targetFrequency = 255;   // 目标频率(默认中央C)
int currentFrequency = 90;   // 当前频率
const int bufferSize = 1024;
const float cmndfThreshold = 0.3;
int sampleRate = 11000; // 采样率
int buffer[bufferSize];
float df[bufferSize / 2];    // 差函数的数组
float cmndf[bufferSize / 2]; // 累积平方差函数的数组
int tauEstimate = 0;
float pitchEstimate = 0;

// 乐谱展示器变量
int pauseState = 0;             // 暂停状态
int continueState = 0;          // 继续状态
int displayerState = 0;         // 展示器状态
int pagehome_ddlist_index = -1; // 乐谱选择

int noteindex[10];                                     // 音符索引
int lastnoteIndex[10];                                 // 上一个音符索引
int totalindex[10] = {32, 32, 0, 0, 0, 0, 0, 0, 0, 0}; // 总音符索引

int isMusicStart = 0;      // 音乐开始
int displayerMode = 0;     // 展示器模式
int displayerbpm = 80;     // 展示器节拍
int displayert;            // 展示器间隔时间
int displayGapTime = 0;    // 展示器自动模式间隔时间
int LEDGapTime = 0;        // LED自动模式间隔时间
int LEDState = 0;          // LED状态(0:关闭 1:演奏引导模式 2:FFT模式)
int isPageHomeInit = 0;    // 乐谱选择界面初始化
int formerddlistindex = 0; // 上一个乐谱选择

int isddlistRefreshed = 0; // 乐谱选择界面刷新
int isddlistClicked = 0;   // 乐谱选择界面点击

// sr变量
String temp;
int srClick = 0;
int isDelete = 0;
String s1 = "TUNERON";
String s2 = "METROON";
String s3 = "PREON";
String s4 = "SETTINGSON";
String s5 = "TUNEROFF";
String s6 = "METROOFF";
String s7 = "PREOFF";
String s8 = "SETTINGSOFF";

u_int8_t testnote[8][5][5] = {0};
std::vector<section<4>> testSec;
UklScore test; // 测试乐谱1
// arduino FFT变量
arduinoFFT FFT = arduinoFFT();
const uint16_t samples = 1024;    // This value MUST ALWAYS be a power of 2
double samplingFrequency = 10000; // Hz, must be less than 10000 due to ADC
unsigned int sampling_period_us;
unsigned long microseconds;
double vReal[samples];
double vImag[samples];
double magnitudeSpectrum[samples];
double noteFrequencies[12];
double chromagram[12];
double lastChromagram[12];
double normalizedChromagram[12];
double targetChromagram[12];
double referenceFrequency = 262.8;

// —————————————————————————————————————————————————函数定义——————————————————————————————————————————————————//
void FFTsetup()
{
    for (int i = 0; i < 12; i++)
    {
        noteFrequencies[i] = referenceFrequency * pow(2, (((float)i) / 12));
    }
}

void FFTloop()
{
    if (analogRead(MIC) > 1500)
    {
        int time0 = millis();
        /*SAMPLING*/
        for (int i = 0; i < samples; i++)
        {
            vReal[i] = analogRead(MIC);
            vImag[i] = 0;
        }

        samplingFrequency = samples * 1000 / (millis() - time0);

        FFT.Windowing(vReal, samples, FFT_WIN_TYP_HAMMING, FFT_FORWARD); /* Weigh data */

        FFT.Compute(vReal, vImag, samples, FFT_FORWARD); /* Compute FFT */

        for (int i = 0; i < samples; i++)
        {
            magnitudeSpectrum[i] = sqrt(pow(vReal[i], 2) + pow(vImag[i], 2));
            magnitudeSpectrum[i] = sqrt(magnitudeSpectrum[i]);
            // Serial.println(magnitudeSpectrum[i]);
        }

        double x = FFT.MajorPeak(vReal, samples, samplingFrequency);

        double divisorRatio = (((double)samplingFrequency)) / ((double)samples);
        for (int i = 0; i < 12; i++)
        {
            lastChromagram[i] = chromagram[i];
        }

        for (int n = 0; n < 12; n++)
        {
            double chromaSum = 0.0;

            for (int octave = 1; octave <= 2; octave++)
            {
                double noteSum = 0.0;

                for (int harmonic = 1; harmonic <= 2; harmonic++)
                {
                    int centerBin = round((noteFrequencies[n] * octave * harmonic) / divisorRatio);
                    int minBin = centerBin - (octave * harmonic);
                    int maxBin = centerBin + (octave * harmonic);
                    if (centerBin > 361)
                    {
                        centerBin = round((noteFrequencies[n] * octave * harmonic) / divisorRatio * 4);
                        minBin = centerBin - (octave * harmonic) * 4;
                        maxBin = centerBin + (octave * harmonic) * 4;
                    }
                    double maxVal = 0.0;

                    for (int k = minBin; k < maxBin; k++)
                    {
                        if (magnitudeSpectrum[k] > maxVal)
                        {
                            maxVal = magnitudeSpectrum[k];
                        }
                    }

                    noteSum += (maxVal / (double)harmonic);
                }

                chromaSum += noteSum;
            }

            chromagram[n] = chromaSum;
        }

        double minValue = 1000;
        int minIndex = 0;
        for (int n = 0; n < 12; n++)
        {
            if (chromagram[n] < minValue)
            {
                minValue = chromagram[n];
                minIndex = n;
            }
        }
        for (int i = 0; i < 12; i++)
        {
            normalizedChromagram[i] = chromagram[i] / minValue;
            if (normalizedChromagram[i] > 4)
                normalizedChromagram[i] = 1;
            else
                normalizedChromagram[i] = 0;
            // Serial.print(normalizedChromagram[i]);
            // Serial.print(" ");
        }
    }
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
// 控制蜂鸣器发声

void tft_init()
{

    tft.begin();        /* TFT init TFT初始化*/
    tft.setRotation(1); /* Landscape orientation, flipped 设置方向*/
    uint16_t calData[5] = {187, 3596, 387, 3256, 5};
    tft.setTouch(calData);
}

lv_ui guider_ui; // 结构体包含所有屏幕与部件，必不可少，且不能放到setup里 。使用该指针可以找到程序里任何对象

void lvglSetUp()
{
    lv_init();

    tft.begin();        /* TFT init */
    tft.setRotation(3); /* Landscape orientation, flipped */

    /*Set the touchscreen calibration data,
     the actual data for your display can be acquired using
     the Generic -> Touch_calibrate example from the TFT_eSPI library*/
    uint16_t calData[5] = {275, 3620, 264, 3532, 1};
    tft.setTouch(calData);

    lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * 10);

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    /*Initialize the (dummy) input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);

    /*Create a GUI-Guider app */
    setup_ui(&guider_ui);
    events_init(&guider_ui); // 事件初始化
    custom_init(&guider_ui); // 运行自定义代码，例如将实际输出跟gui显示的数值关联起来
}
void lv_port_indev_init(void)
{
    // 初识化编码器
    my_encoder_init();
    // 注册输入设备
    static lv_indev_drv_t indev_drv2;
    lv_indev_drv_init(&indev_drv2);
    indev_drv2.type = LV_INDEV_TYPE_ENCODER;
    indev_drv2.read_cb = my_encoder_read;
    lv_indev_drv_register(&indev_drv2);
    lv_group_t *group = lv_group_create();
    lv_group_set_default(group);
    lv_group_remove_all_objs(group);
    lv_group_add_obj(group, guider_ui.screen_btn_1);
    lv_group_add_obj(group, guider_ui.screen_btn_2);
    lv_group_add_obj(group, guider_ui.screen_btn_3);
    lv_group_add_obj(group, guider_ui.screen_btn_4);
    lv_indev_set_group(lv_indev_drv_register(&indev_drv2), group);
}

void musicSheetPresenterInit()
{
    for (int i = 0; i < 8; i++)
    {
        section<4> s;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                s.musicScore[j][k] = testnote[i][j][k];
            }
        }
        testSec.push_back(s);
    }
    test.UklScoreSetUp(4, testSec, &tft);
}

void srTest()
{
    temp = "";
    srClick = 1;
    while (SR_Serial.available())
    {
        char c = SR_Serial.read();
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            temp += c;
    }
    Serial.print("Received: ");
    Serial.println(temp);
    Serial.println("srClick");
}

void srSwitch()
{
    isDelete = 0;
    if ((temp == s1) && lv_scr_act() == guider_ui.screen)
    {
        lv_event_send(guider_ui.screen_btn_1, LV_EVENT_REFRESH, NULL);
        lv_event_send(guider_ui.screen_btn_1, LV_EVENT_CLICKED, NULL);
        lv_event_send(guider_ui.screen_btn_1, LV_EVENT_RELEASED, NULL);
    }
    else if ((temp == s2) && lv_scr_act() == guider_ui.screen)
    {
        lv_event_send(guider_ui.screen_btn_2, LV_EVENT_REFRESH, NULL);
        lv_event_send(guider_ui.screen_btn_2, LV_EVENT_CLICKED, NULL);
        lv_event_send(guider_ui.screen_btn_2, LV_EVENT_RELEASED, NULL);
    }
    else if ((temp == s3) && lv_scr_act() == guider_ui.screen)
    {
        lv_event_send(guider_ui.screen_btn_3, LV_EVENT_REFRESH, NULL);
        lv_event_send(guider_ui.screen_btn_3, LV_EVENT_CLICKED, NULL);
        lv_event_send(guider_ui.screen_btn_3, LV_EVENT_RELEASED, NULL);
    }
    else if (temp == s4 && lv_scr_act() == guider_ui.screen)
    {
        lv_event_send(guider_ui.screen_btn_4, LV_EVENT_REFRESH, NULL);
        lv_event_send(guider_ui.screen_btn_4, LV_EVENT_CLICKED, NULL);
        lv_event_send(guider_ui.screen_btn_4, LV_EVENT_RELEASED, NULL);
    }
    else if (temp == s5)
    {
        if (lv_scr_act() == guider_ui.Tunerhome)
        {
            lv_event_send(guider_ui.Tunerhome_btn_1, LV_EVENT_REFRESH, NULL);
            lv_event_send(guider_ui.Tunerhome_btn_1, LV_EVENT_CLICKED, NULL);
            lv_event_send(guider_ui.Tunerhome_btn_1, LV_EVENT_RELEASED, NULL);
        }
        else if (lv_scr_act() == guider_ui.TurnerAutoHome)
        {
            lv_event_send(guider_ui.TurnerAutoHome_btn_2, LV_EVENT_REFRESH, NULL);
            lv_event_send(guider_ui.TurnerAutoHome_btn_2, LV_EVENT_CLICKED, NULL);
            lv_event_send(guider_ui.TurnerAutoHome_btn_2, LV_EVENT_RELEASED, NULL);
        }
    }
    else if (temp == s6 && lv_scr_act() == guider_ui.Metronomehome)
    {
        lv_event_send(guider_ui.Metronomehome_btn_4, LV_EVENT_REFRESH, NULL);
        lv_event_send(guider_ui.screen, LV_EVENT_REFRESH, NULL);
        lv_event_send(guider_ui.Metronomehome_btn_4, LV_EVENT_CLICKED, NULL);
        lv_event_send(guider_ui.Metronomehome_btn_4, LV_EVENT_RELEASED, NULL);
    }
    else if (temp == s7)
    {
        if (lv_scr_act() == guider_ui.Pagehome)
        {
            lv_event_send(guider_ui.Pagehome_btn_4, LV_EVENT_REFRESH, NULL);
            lv_event_send(guider_ui.Pagehome_btn_4, LV_EVENT_CLICKED, NULL);
            lv_event_send(guider_ui.Pagehome_btn_4, LV_EVENT_RELEASED, NULL);
        }
        else if (lv_scr_act() == guider_ui.Musicsheetpresenter)
        {
            lv_event_send(guider_ui.Musicsheetpresenter_btn_1, LV_EVENT_REFRESH, NULL);
            lv_event_send(guider_ui.Musicsheetpresenter_btn_1, LV_EVENT_CLICKED, NULL);
            lv_event_send(guider_ui.Musicsheetpresenter_btn_1, LV_EVENT_RELEASED, NULL);
        }
    }
    else if (temp == s8 && lv_scr_act() == guider_ui.Settings)
    {
        lv_event_send(guider_ui.Settings_btn_1, LV_EVENT_REFRESH, NULL);
        lv_event_send(guider_ui.Settings_btn_1, LV_EVENT_CLICKED, NULL);
        lv_event_send(guider_ui.Settings_btn_1, LV_EVENT_RELEASED, NULL);
    }
}

void tunerUIHandler()
{
    FFTloop();
    if (analogRead(MIC) > 1500)
    {
        pitchEstimate = 0;
        int time0 = millis();
        for (int i = 0; i < bufferSize; i++)
        {
            buffer[i] = analogRead(MIC);
        }
        sampleRate = bufferSize * 1000 / (millis() - time0);
        pitchEstimate = yinAlgorithm(); // yin算法计算频率
        if (pitchEstimate > 200 && pitchEstimate < 500)
        {
            currentFrequency = pitchEstimate;
        }
    }
    lv_meter_set_indicator_value(guider_ui.Tunerhome_meter_1, guider_ui.Tunerhome_meter_1_scale_1_ndline_0, currentFrequency - targetFrequency);
}
void autoTunerUIHandler()
{
    FFTloop();
    if (analogRead(MIC) > 1400)
    {
        pitchEstimate = 0;
        int time0 = millis();
        for (int i = 0; i < bufferSize; i++)
        {
            buffer[i] = analogRead(MIC);
        }
        sampleRate = bufferSize * 1000 / (millis() - time0);
        pitchEstimate = yinAlgorithm();
        Serial.println("Estimated Pitch: ");
        Serial.println(pitchEstimate);
        Serial.println(sampleRate);
        // 主循环代码（用于更新音高显示和指针位置）
        if (pitchEstimate > 200 && pitchEstimate < 500)
        {
            currentFrequency = pitchEstimate;
        }
    }
    if (currentFrequency > 220 && currentFrequency < 293)
    {
        targetFrequency = 255;
        lv_label_set_text(guider_ui.TurnerAutoHome_label_3, "Now:\nC\n");
        lv_meter_set_indicator_value(guider_ui.TurnerAutoHome_meter_1, guider_ui.TurnerAutoHome_meter_1_scale_1_ndline_0, currentFrequency - targetFrequency);
    }
    else if (currentFrequency > 293 && currentFrequency < 369)
    {
        targetFrequency = 322;
        lv_label_set_text(guider_ui.TurnerAutoHome_label_3, "Now:\nE\n");
        lv_meter_set_indicator_value(guider_ui.TurnerAutoHome_meter_1, guider_ui.TurnerAutoHome_meter_1_scale_1_ndline_0, currentFrequency - targetFrequency);
    }
    else if (currentFrequency > 369 && currentFrequency < 415)
    {
        targetFrequency = 392;
        lv_label_set_text(guider_ui.TurnerAutoHome_label_3, "Now:\nG\n");
        lv_meter_set_indicator_value(guider_ui.TurnerAutoHome_meter_1, guider_ui.TurnerAutoHome_meter_1_scale_1_ndline_0, currentFrequency - targetFrequency);
    }
    else if (currentFrequency > 415 && currentFrequency < 493)
    {
        targetFrequency = 440;
        lv_label_set_text(guider_ui.TurnerAutoHome_label_3, "Now:\nA\n");
        lv_meter_set_indicator_value(guider_ui.TurnerAutoHome_meter_1, guider_ui.TurnerAutoHome_meter_1_scale_1_ndline_0, currentFrequency - targetFrequency);
    }
    else
    {
        lv_label_set_text(guider_ui.TurnerAutoHome_label_3, "Not\nrecognized\n");
    }
}

void LEDDisplayHandler()
{
    // 控制LED显示
    if (LEDState == 0) // 不显示
    {
        LEDclear();
    }
    else if (LEDState == 1 && lv_scr_act() == guider_ui.Musicsheetpresenter) // 乐谱演示模式
    {
        // Serial.println("LEDState1");
        int flag = 0;
        for (int i = 0; i < 10; i++)
        {
            if (lastnoteIndex != noteindex)
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            // Serial.println("LEDState2");
            if (pagehome_ddlist_index == 0)
            {
                // Serial.println("LEDState3");
                generateLEDDisplay(noteindex[0]);
                lastnoteIndex[pagehome_ddlist_index] = noteindex[pagehome_ddlist_index];
            }
            else if (pagehome_ddlist_index == 1)
            {
                // Serial.println("LEDState4");
                generateLEDDisplay(noteindex[1]);
                lastnoteIndex[pagehome_ddlist_index] = noteindex[pagehome_ddlist_index];
            }
        }
    }
    else if (LEDState == 2 && lv_scr_act() == guider_ui.Musicsheetpresenter) // 频谱显示模式
    {
        if (millis() - LEDGapTime > 100)
        {
            generateLEDChromagramDisplay();
            LEDGapTime = millis();
        }
    }
}
bool isMoveForward() // 判断是否需要向后移一位
{
    int sameCnt = 0;
    int notZeroCnt = 0;
    for (int i = 0; i < 12; i++)
    {
        if (normalizedChromagram[i] == targetChromagram[i] && targetChromagram[i] != 0)
        {
            sameCnt++;
        }
        if (targetChromagram[i] != 0)
        {
            notZeroCnt++;
        }
    }
    if (((notZeroCnt == 1 && sameCnt == 1) || (notZeroCnt >= 2 && sameCnt >= 2) || notZeroCnt == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void musicSheetDisplay() // 根据ddlistIndex展示乐谱
{
    test.drawMusic();
    if (displayerState == 1) // 乐谱演示list2的开关
    {
        if (displayerMode == 0) // AUTO模式（自动播放）
        {
            int displayerTime = 60 * 1000 / displayerbpm;
            test.drawMusic();
            if (millis() - displayert > displayerTime)
            {
                test.forwardPos();
                tft.fillRect(0, 60, 480, 260, TFT_WHITE);
                displayert = millis();
                lastnoteIndex[pagehome_ddlist_index] = noteindex[pagehome_ddlist_index];
                noteindex[pagehome_ddlist_index]++;
                if (noteindex[pagehome_ddlist_index] > totalindex[pagehome_ddlist_index])
                {
                    noteindex[pagehome_ddlist_index] = 0;
                }
                generateTargetChromagram(noteindex[pagehome_ddlist_index]);
            }
        }
        if (displayerMode == 1) // TRIG模式（手动播放）
        {
            test.drawMusic();
            if (isMoveForward() == true && (millis() - displayGapTime > 1000)) // 卡了时间，防止同音连续跳动
            {
                test.forwardPos();
                tft.fillRect(0, 60, 480, 260, TFT_WHITE);
                lastnoteIndex[pagehome_ddlist_index] = noteindex[pagehome_ddlist_index];
                noteindex[pagehome_ddlist_index]++;
                if (noteindex[pagehome_ddlist_index] > totalindex[pagehome_ddlist_index])
                {
                    noteindex[pagehome_ddlist_index] = 0;
                }
                for (int i = 0; i < 12; i++)
                {
                    targetChromagram[i] = 0;
                }
                generateTargetChromagram(noteindex[pagehome_ddlist_index]);
                displayGapTime = millis();
            }
        }
    }
    if (posState == 1) // 检测到旋钮转动
    {
        displayerState = 0; // 关闭乐谱演示
        test.forwardPos();
        tft.fillRect(0, 60, 480, 260, TFT_WHITE);
        lv_label_set_text(guider_ui.Musicsheetpresenter_btn_3_label, "PAUSED");
        posState = 0;
        lastnoteIndex[pagehome_ddlist_index] = noteindex[pagehome_ddlist_index];
        noteindex[pagehome_ddlist_index]++;
        if (noteindex[pagehome_ddlist_index] > totalindex[pagehome_ddlist_index])
        {
            noteindex[pagehome_ddlist_index] = 0;
        }
        generateTargetChromagram(noteindex[pagehome_ddlist_index]);
    }
    if (posState == -1) // 检测到旋钮转动
    {
        displayerState = 0; // 关闭乐谱演示
        test.backwardPos();
        tft.fillRect(0, 60, 480, 260, TFT_WHITE);
        lv_label_set_text(guider_ui.Musicsheetpresenter_btn_3_label, "PAUSED");
        posState = 0;
        if (noteindex[pagehome_ddlist_index] > 0)
        {
            lastnoteIndex[pagehome_ddlist_index] = noteindex[pagehome_ddlist_index];
            noteindex[pagehome_ddlist_index]--;
        }
        generateTargetChromagram(noteindex[pagehome_ddlist_index]);
    }
}

//--------------------------------------------------setup--------------------------------------------------
void setup()
{
    intelliTarSetup();
    lvglSetUp();
    pinMode(beepPin, OUTPUT);
    lv_port_indev_init();
    FFTsetup();
    SR_Serial.onReceive(srTest);
    // lv_obj_clear_flag(guider_ui.Tunerhome, LV_OBJ_FLAG_SCROLLABLE);
}
void loop()
{
    if (srClick)
    {
        srClick = 0;
        srSwitch();
    }
    lv_timer_handler(); /* let the GUI do its work 让 GUI 完成它的工作 */
    int tempKey = keyDown();
    if (tempKey != 0)
    {
        Serial.println(tempKey);
        click = tempKey;
    }
    if (pos != lastpos)
    {
        Serial.println(pos);
        lastpos = pos;
    }

    // 控制屏幕显示
    if (lv_scr_act() == guider_ui.Metronomehome && switchState == 1) // 节拍器页面
    {
    }

    else if (lv_scr_act() == guider_ui.Tunerhome) // 手动调音器页面(默认)
    {
        tunerUIHandler();
    }
    if (lv_scr_act() == guider_ui.TurnerAutoHome) // 自动调音器页面
    {
        autoTunerUIHandler();
    }
    if (lv_scr_act() == guider_ui.Pagehome)
    {
        formerddlistindex = pagehome_ddlist_index;
        pagehome_ddlist_index = lv_dropdown_get_selected(guider_ui.Pagehome_ddlist_1);
        // Serial.println(pagehome_ddlist_index);
        LEDclear();
        LEDStateSetAll(0);
        if (isddlistRefreshed == 1)
        {
            for (int i = 0; i < 10; i++)
            {
                noteindex[i] = 0;
            }
            if (pagehome_ddlist_index == 0) // 乐谱演示list1
            {
                testSec.clear();
                isddlistRefreshed = 0;
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        for (int k = 0; k < 5; k++)
                        {
                            testnote[i][j][k] = twinkelStar[i][j][k];
                        }
                    }
                }
                musicSheetPresenterInit();
                generateTargetChromagram(0);
            }
            if (pagehome_ddlist_index == 1) // 乐谱演示list2
            {
                testSec.clear();
                isddlistRefreshed = 0;
                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        for (int k = 0; k < 5; k++)
                        {
                            testnote[i][j][k] = lantingOrder[i][j][k];
                        }
                    }
                }
                musicSheetPresenterInit();
                generateTargetChromagram(0);
            }
            // do something
        }
    }
    if (lv_scr_act() == guider_ui.Musicsheetpresenter)
    {
        Serial.print("noteindex:");
        Serial.println(noteindex[0]);
        Serial.println(noteindex[1]);
        Serial.println("end");

        FFTloop();
        if (pagehome_ddlist_index == 0) // 乐谱演示list1
        {
            musicSheetDisplay();
        }
        if (pagehome_ddlist_index == 1) // 乐谱演示list2
        {
            musicSheetDisplay();
        }
        if (pagehome_ddlist_index == 2)
        {
        }
        Serial.println("targetChromagram:");
        for (int i = 0; i < 12; i++)
        {
            Serial.print(targetChromagram[i]);
            Serial.print(" ");
        }
        Serial.println();
    }
    if (lv_scr_act() == guider_ui.Settings)
    {
        Serial.println(lv_textarea_get_text(guider_ui.Settings_ta_1));
        Serial.println(lv_textarea_get_text(guider_ui.Settings_ta_2));
    }

    LEDDisplayHandler(); // 控制LED显示
    delay(5);
}

void LedLoop(void *pvParameters)
{
    while (1)
    {
        LEDdisplay();
        if (lv_scr_act() == guider_ui.Metronomehome && switchState == 1)
        {
            bpm = MetroPointerAngle;
            int time = 60 * 1000 / bpm;
            if (millis() - time0 > time)
            {
                tone(beepPin, 300);
                time0 = millis();
                time1 = time0;
            }
            if (millis() - time1 > 50)
            {
                noTone(beepPin);
                time1 = millis();
            }
        }
    }
}