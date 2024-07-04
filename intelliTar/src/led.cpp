#include <led.h>
#define RCLK_Pin_x 18
#define SRCLK_Pin_x 19
#define SER_Pin_x 21
#define RCLK_Pin_y 15
#define SRCLK_Pin_y 17
#define SER_Pin_y 5

bool LEDstate[6][8];

void LEDLib_init()
{
    pinMode(RCLK_Pin_x, OUTPUT);
    pinMode(SRCLK_Pin_x, OUTPUT);
    pinMode(SER_Pin_x, OUTPUT);
    pinMode(RCLK_Pin_y, OUTPUT);
    pinMode(SRCLK_Pin_y, OUTPUT);
    pinMode(SER_Pin_y, OUTPUT);
}

void updateShiftRegisterX(unsigned int leds)
{
    digitalWrite(RCLK_Pin_x, LOW);
    shiftOut(SER_Pin_x, SRCLK_Pin_x, LSBFIRST, leds);
    digitalWrite(RCLK_Pin_x, HIGH);
}
void updateShiftRegisterY(unsigned int leds)
{
    digitalWrite(RCLK_Pin_y, LOW);
    shiftOut(SER_Pin_y, SRCLK_Pin_y, LSBFIRST, leds);
    digitalWrite(RCLK_Pin_y, HIGH);
}

void LEDclear()
{
    updateShiftRegisterX(B00000000);
    updateShiftRegisterY(B11111111);
}

byte arr2byte(bool arr[8])
{
    byte result = 0;
    for (int i = 0; i < 8; i++)
    {
        result <<= 1;
        result |= arr[i];
    }
    return result;
}

void LEDStateSet(int x, int y, bool state)
{
    if(x>12 || y>4 || x<1 || y<1)
        return;
    LEDstate[(x-1)/2][(x-1)%2*4+y-1] = state;
}

void LEDStateInv(int x, int y)
{
    if(x>12 || y>4 || x<1 || y<1)
        return;
    LEDstate[(x-1)/2][(x-1)%2*4+y-1] = !LEDstate[(x-1)/2][(x-1)%2*4+y-1];
}

bool LEDStateGet(int x, int y)
{
    if(x>12 || y>4 || x<1 || y<1)
        return false;
    return LEDstate[(x-1)/2][(x-1)%2*4+y-1];
}

void LEDStateSetAll(bool state)
{
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 8; j++)
            LEDstate[i][j] = state;
}

void LEDdisplay()
{
    byte ScanY = B10000000;
    for (int i = 0; i < 6; i++)
    {
        LEDclear();
        updateShiftRegisterY(~ScanY);
        updateShiftRegisterX(arr2byte(LEDstate[i]));
        ScanY >>= 1;
    }
}

void generateLEDChromagramDisplay()   //FFT模式的显示
{
    LEDclear();
    LEDStateSetAll(0);
    for (int i = 0; i < 12; i++)
    {
        Serial.print(chromagram[i]);
        Serial.print(" ");
    }
    for (int i = 0; i < 12; i++)
    {
        if (chromagram[i] > 400)
        {
            LEDStateSet(i + 1, 4, true);
            LEDStateSet(i + 1, 3, true);
            LEDStateSet(i + 1, 2, true);
            LEDStateSet(i + 1, 1, true);
        }
        else if (chromagram[i] > 300 && (chromagram[i] - lastChromagram[i] >= 50))
        {
            LEDStateSet(i + 1, 4, true);
            LEDStateSet(i + 1, 3, true);
            LEDStateSet(i + 1, 2, true);
        }
        else if (chromagram[i] > 200 && (chromagram[i] - lastChromagram[i] >= 20))
        {
            LEDStateSet(i + 1, 4, true);
            LEDStateSet(i + 1, 3, true);
        }
        else if (chromagram[i] > 100)
        {
            LEDStateSet(i + 1, 4, true);
        }
    }
}
void generateLEDDisplay(int noteIndex)   //guide 模式的显示
{
    // Serial.println("generateLEDDisplay:");
    // for (int i = 0; i < 4; i++)
    // {
    //     Serial.print(testnote[noteIndex / 4][noteIndex % 4 + 1][i + 1]);
    //     Serial.print(" ");
    // }
    // Serial.println();
    LEDclear();
    LEDStateSetAll(0);
    if (testnote[noteIndex / 4][noteIndex % 4 + 1][1] != 255 && testnote[noteIndex / 4][noteIndex % 4 + 1][1] != 0)
        LEDStateSet(testnote[noteIndex / 4][noteIndex % 4 + 1][1], 1, true);
    if (testnote[noteIndex / 4][noteIndex % 4 + 1][2] != 255 && testnote[noteIndex / 4][noteIndex % 4 + 1][2] != 0)
        LEDStateSet(testnote[noteIndex / 4][noteIndex % 4 + 1][2], 2, true);
    if (testnote[noteIndex / 4][noteIndex % 4 + 1][3] != 255 && testnote[noteIndex / 4][noteIndex % 4 + 1][3] != 0)
        LEDStateSet(testnote[noteIndex / 4][noteIndex % 4 + 1][3], 3, true);
    if (testnote[noteIndex / 4][noteIndex % 4 + 1][4] != 255 && testnote[noteIndex / 4][noteIndex % 4 + 1][4] != 0)
        LEDStateSet(testnote[noteIndex / 4][noteIndex % 4 + 1][4], 4, true);
}
void generateTargetChromagram(int noteIndex)   //guide 模式的目标音符
{
    for (int i = 0; i < 12; i++)
    {
        targetChromagram[i] = 0;
    }
    for (int i = 0; i < 5; i++)
    {
        //Serial.print(testnote[noteIndex / 4][noteIndex % 4 + 1][i]);
        if (i == 1)
        {
            switch (testnote[noteIndex / 4][noteIndex % 4 + 1][i])
            {
            case 0:
                targetChromagram[7] = 1;
                break;
            case 1:
                targetChromagram[8] = 1;
                break;
            case 2:
                targetChromagram[9] = 1;
                break;
            case 3:
                targetChromagram[10] = 1;
                break;
            case 4:
                targetChromagram[11] = 1;
                break;
            case 5:
                targetChromagram[0] = 1;
                break;
            case 6:
                targetChromagram[1] = 1;
                break;
            case 7:
                targetChromagram[2] = 1;
                break;
            case 8:
                targetChromagram[3] = 1;
                break;
            case 9:
                targetChromagram[4] = 1;
                break;
            case 10:
                targetChromagram[5] = 1;
                break;
            case 11:
                targetChromagram[6] = 1;
                break;
            default:
                break;
            }
        }
        if (i == 2)
        {
            switch (testnote[noteIndex / 4][noteIndex % 4 + 1][i])
            {
            case 0:
                targetChromagram[0] = 1;
                break;
            case 1:
                targetChromagram[1] = 1;
                break;
            case 2:
                targetChromagram[2] = 1;
                break;
            case 3:
                targetChromagram[3] = 1;
                break;
            case 4:
                targetChromagram[4] = 1;
                break;
            case 5:
                targetChromagram[5] = 1;
                break;
            case 6:
                targetChromagram[6] = 1;
                break;
            case 7:
                targetChromagram[7] = 1;
                break;
            case 8:
                targetChromagram[8] = 1;
                break;
            case 9:
                targetChromagram[9] = 1;
                break;
            case 10:
                targetChromagram[10] = 1;
                break;
            case 11:
                targetChromagram[11] = 1;
                break;
            default:
                break;
            }
        }
        if (i == 3)
        {
            switch (testnote[noteIndex / 4][noteIndex % 4 + 1][i])
            {
            case 0:
                targetChromagram[4] = 1;
                break;
            case 1:
                targetChromagram[5] = 1;
                break;
            case 2:
                targetChromagram[6] = 1;
                break;
            case 3:
                targetChromagram[7] = 1;
                break;
            case 4:
                targetChromagram[8] = 1;
                break;
            case 5:
                targetChromagram[9] = 1;
                break;
            case 6:
                targetChromagram[10] = 1;
                break;
            case 7:
                targetChromagram[11] = 1;
                break;
            case 8:
                targetChromagram[0] = 1;
                break;
            case 9:
                targetChromagram[1] = 1;
                break;
            case 10:
                targetChromagram[2] = 1;
                break;
            case 11:
                targetChromagram[3] = 1;
                break;
            default:
                break;
            }
        }
        if (i == 4)
        {
            switch (testnote[noteIndex / 4][noteIndex % 4 + 1][i])
            {
            case 0:
                targetChromagram[9] = 1;
                break;
            case 1:
                targetChromagram[10] = 1;
                break;
            case 2:
                targetChromagram[11] = 1;
                break;
            case 3:
                targetChromagram[1] = 1;
                break;
            case 4:
                targetChromagram[2] = 1;
                break;
            case 5:
                targetChromagram[3] = 1;
                break;
            case 6:
                targetChromagram[4] = 1;
                break;
            case 7:
                targetChromagram[5] = 1;
                break;
            case 8:
                targetChromagram[6] = 1;
                break;
            case 9:
                targetChromagram[7] = 1;
                break;
            case 10:
                targetChromagram[8] = 1;
                break;
            case 11:
                targetChromagram[9] = 1;
                break;
            default:
                break;
            }
        }
    }
}
