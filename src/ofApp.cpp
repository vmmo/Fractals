#include "ofApp.h"
//The setup for the project can be found here.
//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(20);
    FractalMode1 *fm1 = new FractalMode1(ofGetWidth() / 2, ofGetHeight() / 2, levels, 60);

    FractalMode2 *fm21 = new FractalMode2(ofGetWidth() / 2, ofGetHeight() - 50, levels, 200, 30);
    FractalMode2 *fm22 = new FractalMode2(ofGetWidth() / 4, ofGetHeight() - 50, levels, 125, 30);
    FractalMode2 *fm23 = new FractalMode2((ofGetWidth() * 3) / 4, ofGetHeight() - 50, levels, 125, 30);
    // fm2->degBranchDraw(levels);

    FractalMode3 *fm3 = new FractalMode3(ofGetWidth() / 3, 10, ofGetHeight() / 2, levels);

    FractalMode4 *fm4 = new FractalMode4(0, 0, 200, levels);

    fms.push_back(fm1);
    fms.push_back(fm21);
    fms.push_back(fm22);
    fms.push_back(fm23);
    fms.push_back(fm3);
    fms.push_back(fm4);
}

//--------------------------------------------------------------
void ofApp::update()
{
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    ofSetBackgroundColor(255, 255, 255);

    if (animate)
    {
        time++;
        if (time >= 30)
        {
            levels += 1;
            if (levels > 6)
            {
                levels = 0;
            }
            setLevels(levels);
            time = 0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    ofNoFill();

    if (fms[0]->getActivate())
    {
        fms[0]->draw();
    }
    if (fms[1]->getActivate())
    {
        fms[1]->draw();
        fms[2]->draw();
        fms[3]->draw();
    }
    if (fms[4]->getActivate())
    {
        fms[4]->draw();
    }
    if (fms[5]->getActivate())
    {
        fms[5]->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    // This method is called automatically when any key is pressed
    switch (key)
    {
    case '1':
        fms[0]->setActivate(!fms[0]->getActivate());
        break;

    case '2':
        fms[1]->setActivate(!fms[1]->getActivate());
        fms[2]->setActivate(!fms[2]->getActivate());
        fms[3]->setActivate(!fms[3]->getActivate());
        break;

    case '3':
        fms[4]->setActivate(!fms[4]->getActivate());
        break;

    case '4':
        fms[5]->setActivate(!fms[5]->getActivate());
        break;

    case '-':
        if (levels > 0)
        {
            levels--;
            setLevels(levels);
        }
        break;

    case '=':
        levels++;
        setLevels(levels);
        break;
        
     case ' ':
        animate = !animate;
        break;
    }
   
}

void ofApp::setLevels(int levels)
{
    this->levels = levels;
    for (FractalMode *f : fms)
    {
        f->setLevel(levels);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}