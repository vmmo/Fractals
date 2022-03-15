#include "FractalMode.h"
#include <cmath>

class FractalMode4 : public FractalMode
{
    protected:
    int x;
    int y;
    int size;
public:
    FractalMode4(int x, int y, int size, int level) {
        this->x = x;
        this->y = y;
        this->size = size;
        this->level = level;
    };
    void draw() { if(activate) draw4(x, y, size, level); };
    void draw4(int x, int y, int size, int level)
    {
        if (level != 0)
        {
            ofSetLineWidth(6);
            ofSetColor(colorList[level%5][0], colorList[level%5][1], colorList[level%5][2]);
            ofDrawRectangle(x, y, size, size);
            ofSetColor(255,255,255);
            ofSetLineWidth(1);
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    int sum = abs(i) + abs(j);
                    if (sum != 0)
                    {
                        draw4(x - i * (size / 3) + size / 3, y + j * (size / 3) + size / 3, size / 3, level - 1);
                    }
                }
            }
        }
    };
};
