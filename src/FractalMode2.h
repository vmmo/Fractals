#include "FractalMode.h"
#include <cmath>
#include <vector>

class FractalMode2 : public FractalMode
{
private:
    int x;
    int y;
    int length;
    int d;
    // vector<int> branches;

public:
    FractalMode2(int x, int y, int level, int length, int d)
    {
        this->x = x;
        this->y = y;
        this->level = level;
        this->length = length;
        this->d = d;
    }
    void draw() { if(activate) draw2(x, y, level, length, d); };
    void draw2(int x, int y, int level, int length, int d)
    {
        if (level != 0)
        {
            // int newBranchLeft = branches[level - 1];
            // int newBranchRight = branches[branches.size() - level + 1];

            int middleX = x;
            int middleY = y - length;
            int leftBranchX = x - length * cos(PI / 180 * d);
            int leftBranchY = middleY - length * sin(PI / 180 * d);
            int rightBranchX = x + length * cos(PI / 180 * d);
            int rightBranchY = middleY - length * sin(PI / 180 * d);

            ofSetLineWidth(6);
            ofSetColor(colorList[level%5][0], colorList[level%5][1], colorList[level%5][2]);
            ofDrawLine(x, y, x, y - length);
            ofDrawLine(x, y - length, x, y - length * 2);
            ofDrawLine(x, y - length, rightBranchX, rightBranchY);
            ofDrawLine(x, y - length, leftBranchX, leftBranchY);
            ofSetColor(255,255,255);
            ofSetLineWidth(1);

            draw2(rightBranchX, rightBranchY, level - 1, length / 2, d);
            draw2(middleX, middleY, level - 1, length / 2, d);
            draw2(leftBranchX, leftBranchY, level - 1, length / 2, d);
        }
    }
    // void degBranchDraw(int level)
    // {
    //     for (int i = 0; i < level * 2; i++)
    //     {
    //         branches.push_back(ofRandom(20, 70));
    //     }
    // };
};