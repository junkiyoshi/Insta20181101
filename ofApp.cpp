#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	int radius_min = 100;
	int radius_max = 185;

	for (int line = 0; line < 50; line++) {

		int radius = ofRandom(radius_min, radius_max);
		int start_deg = ofGetFrameNum() * 5 + ofRandom(300);
		int len = ofRandom(60, 360);

		ofPoint point, prev_point, base_point;
		for (int deg = start_deg; deg < start_deg + len; deg += 1) {

			int position_deg = deg % 720;
			if (position_deg < 360) {
			
				point = ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)) + ofPoint((radius_min + radius_max) * -0.5, 0);
			}
			else {

				int tmp_radius = ofMap(radius, radius_min, radius_max, radius_max, radius_min);
				point = ofPoint(-1 * tmp_radius * cos(deg * DEG_TO_RAD), tmp_radius * sin(deg * DEG_TO_RAD)) + ofPoint((radius_min + radius_max) * 0.5, 0);
			}

			if (deg != start_deg) {

				ofSetColor(39, ofMap(deg, start_deg, start_deg + len, 0, 255));
				ofDrawLine(prev_point, point);
			}
			prev_point = point;
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}