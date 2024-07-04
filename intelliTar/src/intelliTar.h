#include <TFT_eSPI.h>
#include <Arduino.h>
#include <WiFi.h>
#include <HardwareSerial.h>
#include <led.h>
#include <Ticker.h>
#include <lvgl.h>
#include <complex>
#include <cmath>
#include <vector>
#include <string.h>

/* WIFI */
extern const char *ssid; // Your WiFi SSID
extern const char *password; // Your WiFi Password

/* Mic */
extern const int MIC;

/* TFT */
extern TFT_eSPI tft;
/* Encoder */
extern const int ENCODER_A;
extern const int ENCODER_B;
extern const int ENCODER_BUTTON;
extern int pos;

/* SR Model */
extern HardwareSerial SR_Serial;
extern const int SR_RX;
extern const int SR_TX;

/* Beep */
extern const int BEEP;

/* LED */
extern Ticker ledDemoTicker;

/* function */
void intelliTarSetup();
void beepDemo();
void encoderDemo();
void srDemo();
void micDemo();
void ledDemoInit();
void ledDemo();
int keyDown();
void LedLoop(void *pvParameters);
uint8_t Encoder_Scan();
void my_encoder_init();
void my_encoder_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);
