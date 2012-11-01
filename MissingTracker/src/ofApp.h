/*
build up a background image (use nearest filtering over time)
do that in the depth-image space
analyze current image for any points that are > certain distance from background image
project these points
rotate+translate these points so they are oriented on the platform xy plane
build up a low-resolution (binned) "presence graph"
-
do blob detection and tracking
* add final translation stage for centering data
* add auto-rotation stage based on plane extraction
* farther data has fewer points (use triangles area: |ABxAC|/2)
* mask noisy areas around edges
* use an iir filter on depth image
*/

#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxAutoControlPanel.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void exit();
	
	ofxKinect kinect;
	ofxAutoControlPanel gui;
	bool calibrating, clearBackground;
	float calibrationStart;
	
	ofImage result, background;
	
	ofFloatImage presence;
	ofMesh foregroundFlat;
	ofMesh foregroundCloud;
	ofEasyCam cam;
};
