//Attributes for FractalMode
#pragma once
#include "ofMain.h"

class FractalMode
{
protected:
    int level = 0;
    bool activate = false;

public:
    virtual void draw() = 0;
    void setLevel(int level) { this->level = level; };
    void setActivate(bool activate) { this->activate = activate; };
    bool getActivate() { return activate; };
    vector<vector<int>> colorList = {
        {255, 212, 220},
        {255, 223, 193},
        {191, 234, 222},
        {182, 227, 244},
        {207, 213, 250}};
};