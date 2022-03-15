#include "FractalMode.h"

class FractalMode1 : public FractalMode
{
protected:
    int x;
    int y;
    int radius;

public:
    FractalMode1(int x, int y, int level, int radius)
    {
        this->x = x;
        this->y = y;
        this->level = level;
        this->radius = radius;
    }
    void draw()
    {
        if (activate)
            draw1(x, y, level, level, radius);
    };
    void draw1(int x, int y, int level, int total, int radius)
    {
        if (level != 0)
        {
            ofSetLineWidth(6);
            ofSetColor(colorList[(total -level) % 5][0], colorList[(total -level) % 5][1], colorList[(total -level) % 5][2]);
            ofDrawRectangle(x, y, radius, radius);
            ofSetColor(255, 255, 255);
            ofSetLineWidth(1);
            draw1(x + radius, y, level - 1, total, radius);
            draw1(x - radius, y, level - 1, total, radius);
            draw1(x, y + radius, level - 1, total, radius);
            draw1(x, y - radius, level - 1, total, radius);
        }
    };
};