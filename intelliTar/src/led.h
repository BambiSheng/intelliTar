#ifndef LEDLIB_H
#define LEDLIB_H
#include <Arduino.h>
extern double chromagram[12];
extern double targetChromagram[12];
extern int noteindex[10];
extern uint8_t testnote[8][5][5];
extern double lastChromagram[12];
extern double magnitudeSpectrum[1024];
void LEDLib_init();
void LEDclear();
void LEDdisplay();
void LEDStateSet(int x, int y, bool state);
void LEDStateInv(int x, int y);
void LEDStateSetAll(bool state);
bool LEDStateGet(int x, int y);
void generateLEDChromagramDisplay();
void generateTargetChromagram(int noteIndex);
void generateLEDDisplay(int noteIndex);
#endif