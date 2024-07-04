#ifndef UKLSCORE_H
#define UKLSCORE_H
#endif
#include <string>
#include <TFT_eSPI.h>
#include <vector>

template <int notePerSection>
struct section
{
    uint8_t musicScore[notePerSection+1][5];
};
class UklScore
{
    public:
    int notePerSection;
    int screenWidth;
    int screenHeight;
    int stringSpacing;
    int stringOffset;
    int fretSpacing;
    int fretOffset;
    int pos[2];
    std::vector<section<4>> sections;
    TFT_eSPI* tftp;
    UklScore();
    void UklScoreSetUp(int notePerSection, std::vector<section<4>> sections, TFT_eSPI* tftp);
    ~UklScore();
    void drawMusic();
    void drawStrings();
    void drawX(int stringIndex, int fretIndex);
    void drawNumber(int stringIndex, int fretIndex, int number);
    void drawChord(int stringIndex, int number, int w = 48, int h = 36);
    void drawDownArray(int fretIndex);
    void drawUpArray(int fretIndex);
    void drawHighLight(int highlightedNoteIndex);
    void drawVerticalLine(int fretIndex, int number);
    void drawParallelLine(int fretIndexA, int fretIndexB, int number);
    void drawPause(int fretIndex);
    int setPos(int sectionIndex, int noteIndex);
    int forwardPos();
    int backwardPos();
    std::vector<int> getPosNote();
};