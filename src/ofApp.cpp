#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	nTri = 2500;
	nVert = nTri * 3;

	float Rad = 250;
	float rad = 25;

	vertices.resize(nVert);

	for(int i = 0; i < nTri; i++) {
		ofPoint center(
				ofRandom(-1, 1),
				ofRandom(-1, 1),
				ofRandom(-1, 1));
		center.normalize();
		center *= Rad;

		for(int j = 0; j < 3; j++) {
			vertices[i*3 + j] = center + ofPoint(
					ofRandom(-rad, rad),
					ofRandom(-rad, rad),
					ofRandom(-rad, rad));
		}
	}

	colors.resize(nTri);

	for(int i = 0; i<nTri; i++) {
		colors[i] = ofColor(ofRandom(0, 255), 0, 0);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableDepthTest();

	ofBackgroundGradient(ofColor(128), ofColor(28));

	ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);

	float time = ofGetElapsedTimef();
	float angle = time * 10;

	ofRotate(angle, 0, 1, 0);

	for(int i = 0; i < nTri; i++) {
		ofSetColor(colors[i]);
		ofTriangle(
				vertices[i*3],
				vertices[i*3 + 1],
				vertices[i*3 + 2]
				);
	}
	ofPopMatrix();
}
