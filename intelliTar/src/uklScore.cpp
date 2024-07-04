#include <uklScore.h>

enum class NoteType
{
    // 0~12 normal note
    Pause = 13,
    DownArray = 14,
    UpArray = 15,
    Continue = 16,
    x = 17,
    None=255
};

enum class chord
{
    C = 0,
    D = 1,
    Dm = 2,
    Em = 3,
    F = 4,
    G = 5,
    Am = 6,
    G7 = 7,
    Bm = 8
};

const bool chordIndex[9][4][4] = {
    {{0, 0, 0, 0},
     {0, 0, 0, 0},
     {0, 0, 0, 1},
     {0, 0, 0, 0}},
    {{0, 0, 0, 0},
     {1, 1, 1, 0},
     {0, 0, 0, 0},
     {0, 0, 0, 0}},
    {{0, 0, 1, 0},
     {1, 1, 0, 0},
     {0, 0, 0, 0},
     {0, 0, 0, 0}},
    {{0, 0, 0, 0},
     {0, 0, 0, 1},
     {0, 0, 1, 0},
     {0, 1, 0, 0}},
    {{0, 0, 1, 0},
     {1, 0, 0, 0},
     {0, 0, 0, 0},
     {0, 0, 0, 0}},
    {{0, 0, 0, 0},
     {0, 1, 0, 1},
     {0, 0, 1, 0},
     {0, 0, 0, 0}},
    {{0, 0, 0, 0},
     {1, 0, 0, 0},
     {0, 0, 0, 0},
     {0, 0, 0, 0}},
    {{0, 0, 1, 0},
     {0, 1, 0, 1},
     {0, 0, 0, 0},
     {0, 0, 0, 0}},
     {{0, 0, 0, 0},
     {0, 1, 1, 1},
     {0, 0, 0, 0},
     {1, 0, 0, 0}}};

String chordNameIndex[9] = {"C","D","Dm", "Em", "F", "G", "Am", "G7","Bm"};

UklScore::UklScore() {}

void UklScore::UklScoreSetUp(int notePerSection, std::vector<section<4>> sections, TFT_eSPI *tftp)
{
    this->tftp = tftp;
    this->notePerSection = notePerSection;
    this->sections = sections;

    int screenWidth = 480;
    int screenHeight = 320;
    int strigSpacing = 30;
    int stringOffset = 160;
    int fretSpacing = 30;
    int fretOffset = 20;
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->stringSpacing = strigSpacing;
    this->stringOffset = stringOffset;
    this->fretSpacing = fretSpacing;
    this->fretOffset = fretOffset;
    pos[0] = 0;
    pos[1] = 0;
}
UklScore::~UklScore() {}

void UklScore::drawMusic()
{

    TFT_eSPI tft = *tftp;
    // 绘制指弹谱
    drawStrings();

    if (pos[0] >= sections.size() || pos[1] >= notePerSection)
    {
        return;
    }

    int secMax = sections.size() - pos[0];
    secMax = secMax > 4 ? 4 : secMax;
    for (int i = 0; i < secMax; i++)
    {
        if (sections[pos[0] + i].musicScore[0][0] != 255)
        {
            drawChord(4 * i, sections[pos[0] + i].musicScore[0][0]);
        }

        for (int j = 0; j < notePerSection; j++)
        {
            if (sections[pos[0] + i].musicScore[j + 1][0] == 13)
            {
                drawPause(4 * i + j);
            }
            else if (sections[pos[0] + i].musicScore[j + 1][0] == 14)
            {
                drawDownArray(4 * i + j);
            }
            else if (sections[pos[0] + i].musicScore[j + 1][0] == 15)
            {
                drawUpArray(4 * i + j);
            }
            else if (sections[pos[0] + i].musicScore[j + 1][0] == 16)
            {
                for (int k = 0; k < 4; k++)
                {
                    int k1 = 3 - k;
                    drawNumber(k1, 4 * i + j, sections[pos[0] + i].musicScore[j + 1][k + 1]);
                }
                if (4 * i + j - 1 >= 0)
                {
                    drawParallelLine(4 * i + j - 1, 4 * i + j, 0);
                    drawVerticalLine(4 * i + j - 1, 0);
                    drawVerticalLine(4 * i + j, 0);
                }
            }
            else
            {
                for (int k = 0; k < 4; k++)
                {
                    int k1 = 3 - k;
                    if (sections[pos[0] + i].musicScore[j + 1][k + 1] == 17)
                    {
                        drawX(k1, 4 * i + j);
                    }
                    else if(sections[pos[0] + i].musicScore[j + 1][k + 1] == 255)
                    {
                        
                    }
                    else
                    {
                        drawNumber(k1, 4 * i + j, sections[pos[0] + i].musicScore[j + 1][k + 1]);
                    }
                }
            }
        }
    }
    drawHighLight(pos[1]);
}

// 绘制四根线
void UklScore::drawStrings()
{
    TFT_eSPI tft = *tftp;
    for (int i = 0; i < 4; i++)
    {
        int yPos = i * stringSpacing + stringOffset;
        tft.drawLine(0, yPos, screenWidth, yPos, TFT_BLACK);
    }
}

// 在指定位置绘制叉号
void UklScore::drawX(int stringIndex, int fretIndex)
{
    TFT_eSPI tft = *tftp;
    int xPos = fretIndex * fretSpacing + fretOffset;       // 根据需要调整位置
    int yPos = stringIndex * stringSpacing + stringOffset; // 根据需要调整位置

    tft.drawLine(xPos - 5, yPos - 5, xPos + 5, yPos + 5, TFT_BLACK);
    tft.drawLine(xPos - 5, yPos + 5, xPos + 5, yPos - 5, TFT_BLACK);
}

// 在指定位置标记数字
void UklScore::drawNumber(int stringIndex, int fretIndex, int number)
{
    TFT_eSPI tft = *tftp;
    int xPos = fretIndex * fretSpacing + fretOffset;       // 根据需要调整位置
    int yPos = stringIndex * stringSpacing + stringOffset; // 根据需要调整位置

    tft.setCursor(xPos - 5, yPos - 5);
    tft.setTextSize(2);
    tft.setTextColor(TFT_BLACK);
    tft.print(number);
}
void UklScore::drawDownArray(int fretIndex)
{
    TFT_eSPI tft = *tftp;
    int xPos = fretIndex * fretSpacing + fretOffset;    // 根据需要调整位置
    int yPos = 0 * stringSpacing + stringOffset;        // 根据需要调整位置
    int endxPos = fretIndex * fretSpacing + fretOffset; // 根据需要调整位置
    int endyPos = 3 * stringSpacing + stringOffset;     // 根据需要调整位置
    tft.drawLine(xPos, yPos - 1, endxPos, endyPos + 1, TFT_BLACK);
    tft.drawLine(endxPos - 7, endyPos - 7, endxPos, endyPos + 3, TFT_BLACK);
    tft.drawLine(endxPos + 7, endyPos - 7, endxPos, endyPos + 3, TFT_BLACK);
}
void UklScore::drawUpArray(int fretIndex)
{
    TFT_eSPI tft = *tftp;
    int xPos = fretIndex * fretSpacing + fretOffset;    // 根据需要调整位置
    int yPos = 3 * stringSpacing + stringOffset;        // 根据需要调整位置
    int endxPos = fretIndex * fretSpacing + fretOffset; // 根据需要调整位置
    int endyPos = 0 * stringSpacing + stringOffset;     // 根据需要调整位置
    tft.drawLine(xPos, yPos + 1, endxPos, endyPos - 1, TFT_BLACK);
    tft.drawLine(endxPos - 7, endyPos + 7, endxPos, endyPos - 3, TFT_BLACK);
    tft.drawLine(endxPos + 7, endyPos + 7, endxPos, endyPos - 3, TFT_BLACK);
}
void UklScore::drawChord(int fretIndex, int chordNum, int w, int h)
{
    TFT_eSPI tft = *tftp;
    int xPos = fretIndex * fretSpacing + fretOffset; // 根据需要调整位置
    int yPos = 100;                                  // 根据需要调整位置
    tft.setCursor(xPos, yPos - 18);
    tft.setTextSize(2);
    tft.setTextColor(TFT_BLACK);
    tft.print(chordNameIndex[chordNum]);
    tft.drawRect(xPos, yPos, w + 2, h + 2, TFT_BLACK);
    // 画出4x3的矩形
    for (int i = 1; i < 4; i++)
    {
        tft.drawLine(xPos + i * w / 4, yPos, xPos + i * w / 4, yPos + h, TFT_BLACK);
    }
    for (int i = 1; i < 3; i++)
    {
        tft.drawLine(xPos, yPos + i * h / 3, xPos + w, yPos + i * h / 3, TFT_BLACK);
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (chordIndex[chordNum][i][j])
            {
                int j1 = 3 - j;
                tft.drawCircle(xPos + i * w / 4 + w / 8, yPos + j1 * h / 3, 4, TFT_BLACK);
                tft.drawCircle(xPos + i * w / 4 + w / 8, yPos + j1 * h / 3, 3, TFT_BLACK);
                tft.drawCircle(xPos + i * w / 4 + w / 8, yPos + j1 * h / 3, 2, TFT_BLACK);
                tft.drawCircle(xPos + i * w / 4 + w / 8, yPos + j1 * h / 3, 1, TFT_BLACK);
            }
        }
    }
}

void UklScore::drawHighLight(int highlightedNoteIndex)
{
    TFT_eSPI tft = *tftp;
    int fretIndex = highlightedNoteIndex;
    int xPos = fretIndex * fretSpacing + fretOffset; // 根据需要调整位置
    int yPos = 0 * stringSpacing + stringOffset;     // 根据需要调整位置
    tft.drawRect(xPos - 10, yPos - 10, 20, 5 * stringSpacing + 5, TFT_YELLOW);
}

void UklScore::drawVerticalLine(int fretIndex, int number)
{
    TFT_eSPI tft = *tftp;
    int xPos = fretIndex * fretSpacing + fretOffset;    // 根据需要调整位置
    int yPos = 0 * stringSpacing + stringOffset;        // 根据需要调整位置
    int endxPos = fretIndex * fretSpacing + fretOffset; // 根据需要调整位置
    int endyPos = 4 * stringSpacing + stringOffset;     // 根据需要调整位置
    tft.drawLine(xPos, yPos, endxPos, endyPos, TFT_BLACK);
}

void UklScore::drawParallelLine(int fretIndexA, int fretIndexB, int number)
{
    TFT_eSPI tft = *tftp;
    int xPos = fretIndexA * fretSpacing + fretOffset;    // 根据需要调整位置
    int yPos = 4 * stringSpacing + stringOffset;         // 根据需要调整位置
    int endxPos = fretIndexB * fretSpacing + fretOffset; // 根据需要调整位置
    int endyPos = 4 * stringSpacing + stringOffset;      // 根据需要调整位置
    tft.drawLine(xPos, yPos, endxPos, endyPos, TFT_BLACK);
    tft.drawLine(xPos, yPos + 1, endxPos, endyPos + 1, TFT_BLACK);
    tft.drawLine(xPos, yPos + 2, endxPos, endyPos + 2, TFT_BLACK);
    tft.drawLine(xPos, yPos + 3, endxPos, endyPos + 3, TFT_BLACK);
}
void UklScore::drawPause(int fretIndex)
{
    TFT_eSPI tft = *tftp;
    int xPos = fretIndex * fretSpacing + fretOffset; // 根据需要调整位置
    int yPos = 4 * stringSpacing + stringOffset;     // 根据需要调整位置
    tft.setCursor(xPos - 5, yPos - 5);
    tft.setTextSize(2);
    tft.setTextColor(TFT_BLACK);
    tft.print("*");
}

int UklScore::setPos(int sectionIndex, int noteIndex)
{
    if (sectionIndex > sections.size() || noteIndex > notePerSection || sectionIndex < 0 || noteIndex < 0)
    {
        setPos(0, 0);
        return -1;
    }
    pos[0] = sectionIndex;
    pos[1] = noteIndex;
    return 0;
}

int UklScore::forwardPos()
{
    if (pos[0] >= sections.size() || pos[1] >= notePerSection)
    {
        setPos(0, 0);
        return -1;
    }
    pos[1]++;
    if (pos[1] >= notePerSection)
    {
        pos[0]++;
        pos[1] = 0;
    }
    int sectionIndex = pos[0];
    int noteIndex = pos[1];
    if (sectionIndex > sections.size() || noteIndex > notePerSection || sectionIndex < 0 || noteIndex < 0)
    {
        setPos(0, 0);
        return -1;
    }
    return 0;
}

int UklScore::backwardPos()
{
    if (pos[0] >= sections.size() || pos[1] >= notePerSection)
    {
        setPos(0, 0);
        return -1;
    }
    pos[1]--;
    if (pos[1] < 0)
    {
        pos[0]--;
        pos[1] = notePerSection - 1;
    }
    int sectionIndex = pos[0];
    int noteIndex = pos[1];
    if (sectionIndex > sections.size() || noteIndex > notePerSection || sectionIndex < 0 || noteIndex < 0)
    {
        setPos(0, 0);
        return -1;
    }
    return 0;
}

std::vector<int> UklScore::getPosNote()
{
    std::vector<int> posNote;
    section<4> temp = sections[pos[0]];
    for(int i = 0; i < 4; i++)
    {
        posNote.push_back(temp.musicScore[pos[1]+1][i+1]);
    }
    return posNote;
}