#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		vector<ofPoint> vertices;
		vector<ofColor> colors;
		int nTri;
		int nVert;

		void setup();
		void draw();
};
