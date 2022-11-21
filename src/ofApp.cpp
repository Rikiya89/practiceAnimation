#include "ofApp.h"

float loc_x;//circle's x-coordinate
float loc_y;//circle's y-coordinate
float speed_x;//speed for x-coordinate direction
float speed_y;//speed for y-coordinate direction

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofSetCircleResolution(64);

    loc_x = 20; //first point of circle's x-coordinate
    loc_y = 20; //first point of circle's y-coordinate
    speed_x = 4; //first point of speed for x-coordinate direction
    speed_y = 7; //first point of speed for y-coordinate direction
}

//--------------------------------------------------------------
void ofApp::update(){
    loc_x = loc_x + speed_x;//Update for circle's x-coordinate
    loc_y = loc_y + speed_y;//Update for circle's y-coordinate

    //condition 1 bounce off the left side
    if(loc_x < 0){
        speed_x = speed_x * -1;
    }

    //condition 2 bounce off the right side
    if(loc_x > ofGetWidth()){
        speed_x = speed_x * -1;
    }

    //condition 3 bounce off the upside
    if(loc_y < 0){
        speed_y = speed_y * -1;
    }

    //condition 4 bounce off the bottom side
    if(loc_y > ofGetHeight()){
        speed_y = speed_y * -1;
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 0, 255);
    ofDrawCircle(loc_x, loc_y, 60);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
