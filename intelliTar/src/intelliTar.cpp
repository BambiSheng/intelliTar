#include <intelliTar.h>

/* WIFI */
const char *ssid = "WIFI";     // Your WiFi SSID
const char *password = "PASSWORD"; // Your WiFi Password

/* Mic */
const int MIC = 35;

/* TFT */
TFT_eSPI tft;

/* Encoder */
const int ENCODER_A = 23;
const int ENCODER_B = 22;
const int ENCODER_BUTTON = 34;
int pos = 0;
int lpos = 0;
extern int click;
extern int posState;

/* SR Model */
void encoderAISR()
{
    lpos = pos;
    if (digitalRead(ENCODER_A) == digitalRead(ENCODER_B))
    {
        pos++;
    }
    else
    {
        pos--;
    }
}

/* SR Model */
HardwareSerial SR_Serial(1);
const int SR_RX = 2;
const int SR_TX = 4;

/* Beep */
const int BEEP = 13;

/* LED */
Ticker ledDemoTicker;

void intelliTarSetup()
{
    /* Serial Setup */
    Serial.begin(115200);

    /* SR Model Setup */
    SR_Serial.begin(115200, SERIAL_8N1, SR_RX, SR_TX);

    /* WIFI Setup */
    // WiFi.begin(ssid, password);
    // while (WiFi.status() != WL_CONNECTED)
    // {
    //     delay(500);
    //     Serial.print(".");
    // }

    /* Encoder Setup */

    /* LED Setup */
    LEDLib_init();
    LEDStateSetAll(0);
    xTaskCreatePinnedToCore(LedLoop,   // 具体实现的函数
                            "ledLOOP", // 任务名称
                            8192,      // 堆栈大小
                            NULL,      // 输入参数
                            3,         // 任务优先级
                            NULL,      //
                            0          // 核心  0\1
    );
    disableCore0WDT();
    //ledDemoInit();
}

void beepDemo()
{
    tone(BEEP, 300);
    delay(500);
    noTone(BEEP);
    delay(500);
}

void encoderDemo()
{
    Serial.print("Position: ");

    Serial.print("Button: ");
    Serial.println(analogRead(ENCODER_BUTTON));
    delay(300);
}

void srDemo()
{
}

void micDemo()
{
    Serial.println(analogRead(MIC));
    delay(500);
}

void ledDemoInit()
{
    ledDemoTicker.attach_ms(500, ledDemo);
}

void ledDemo()
{
    static int i = 0;
    // Serial.println(i);
    LEDStateInv(i / 4 + 1, i % 4 + 1);
    i++;
    if (i == 48)
        i = 0;
}

int keyDown()
{
    int time0 = millis();
    if (analogRead(ENCODER_BUTTON) > 1000)
        return 0;
    while (analogRead(ENCODER_BUTTON) < 1000)
    {
    }
    int temp = millis() - time0;
    if (temp > 50)
        return temp;
    else
        return 0;
}

// 编码器扫描函数，用于判断左右及按下状态
uint8_t Encoder_Scan()
{
    if (click != 0)
    {
        Serial.println("[Navigation] click");
        posState = 2;
        click = 0;
        return 1;
    }
    if (pos > lpos)
    {
        Serial.println("[Navigation] next");
        posState = 1;
        lpos = pos;
        return 2;
    }
    if (pos < lpos)
    {
        Serial.println("[Navigation] prev");
        posState = -1;
        lpos = pos;
        return 3;
    }
    return 0; // 没按下返回0
}

// 编码器状态更新函数
void my_encoder_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
    static uint32_t last_key = 0;
    uint8_t act_enc = Encoder_Scan();

    if (act_enc != 0)
    {
        switch (act_enc)
        {
        case 1:
            act_enc = LV_KEY_ENTER;
            data->state = LV_INDEV_STATE_PRESSED;
            break;
        case 2:
            act_enc = LV_KEY_RIGHT;
            data->state = LV_INDEV_STATE_RELEASED;
            data->enc_diff++;
            break;
        case 3:
            act_enc = LV_KEY_LEFT;
            data->state = LV_INDEV_STATE_RELEASED;
            data->enc_diff--;
            break;
        }
        last_key = (uint32_t)act_enc;
    }
    data->key = last_key;
}

// 按键初识化函数
void my_encoder_init()
{
    pinMode(ENCODER_A, INPUT_PULLUP);
    pinMode(ENCODER_B, INPUT_PULLUP);
    pinMode(ENCODER_BUTTON, INPUT);
    attachInterrupt(ENCODER_A, encoderAISR, FALLING);
}
/* Display flushing 显示填充 与LCD驱动关联*/
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

/*输入设备，读取触摸板*/
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
    uint16_t touchX, touchY;

    bool touched = tft.getTouch(&touchX, &touchY, 600);

    if (!touched)
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        data->state = LV_INDEV_STATE_PR;

        /*Set the coordinates*/
        data->point.x = touchX;
        data->point.y = touchY;
    }
}