#include "FractalMode.h"
#include <cmath>

class FractalMode3 : public FractalMode
{
protected:
    int x;
    int y;
    int size;

public:
    FractalMode3(int x, int y, int size, int level)
    {
        this->x = x;
        this->y = y;
        this->size = size;
        this->level = level;
    }
    void draw() { if(activate) draw3(x, y, size, level, level); };
    void draw3(int x, int y, int size, int level, int total)
    {
        if (level == 0)
        {
            return;
        }

        ofPoint a(x, y);
        ofPoint b(x + size, y);
        ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

        ofSetLineWidth(6);
        ofSetColor(colorList[(total -level) % 5][0], colorList[(total -level) % 5][1], colorList[(total -level) % 5][2]);
        ofDrawTriangle(a, b, c);
        ofSetColor(255,255,255);
        ofSetLineWidth(1);
        draw3(x, y, size / 2, level - 1, total);
        draw3((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, level - 1, total);
        draw3(x + size / 4, y + ((sqrt(3) * size / 2) / 2), size / 2, level - 1, total);
    };
};