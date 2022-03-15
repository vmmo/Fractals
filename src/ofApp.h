#pragma once
#include <cmath>
#include <vector>

#include "ofMain.h"
#include "FractalMode.h"
#include "FractalMode1.h"
#include "FractalMode2.h"
#include "FractalMode3.h"
#include "FractalMode4.h"

class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void setLevels(int levels);

private:
	int levels = 0;
	vector<FractalMode *> fms;
	bool animate = false;
	int time = 0;
};
