#include "ofApp.h"

static const int NUM = 1000;

float loc_x[NUM];//circle's x-coordinate
float loc_y[NUM];//circle's y-coordinate
float speed_x[NUM];//speed for  x-coordinate direction
float speed_y[NUM];//speed for  y-coordinate direction
float radius[NUM];
int red[NUM];
int green[NUM];
int blue[NUM];
bool mouse_pressed;
float gravity;
float friction;
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    mouse_pressed = false;
    gravity = 0.1;//setting for the force of gravity
    friction = 0.999;//setting for the the force of friction

    //loop until num number
    for(int i = 0; i < NUM; i++){
        loc_x[i] = ofRandom(0,ofGetWidth());
        loc_y[i] = ofRandom(0,ofGetHeight());
        speed_x[i] = ofRandom(-10,10);
        speed_y[i] = ofRandom(-10,10);
        radius[i] = ofRandom(4,40);
        red[i] = ofRandom(0,255);
        green[i] = ofRandom(0,255);
        blue [i] = ofRandom(0,255);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //loop num coordinate number
    for(int i =0; i < NUM; i++){

        //If the mouse pressed that circle gather the mouse
        if(mouse_pressed){
            //re-calculate mouse coordinate and circle speed
            //mouse x-coordinate and circle's x-coordinate distance close to 8/1
            speed_x[i] = (mouseX - loc_x[i]) / 8.0;
            //mouse y-coordinate and circle's y-coordinate distance close to 8/1
            speed_y[i] = (mouseY - loc_y[i]) / 8.0;
        }

        speed_x[i] = speed_x[i] * friction;//calculate for x-coordinate distance's gravity effect
        speed_y[i] = speed_y[i] * friction;//calculate for y-coordinate distance's gravity effect
        speed_y[i] = speed_y[i] + gravity;//calculate for gravity's effect


        loc_x[i] = loc_x[i] + speed_x[i];//Update for circle's x-coordinate
        loc_y[i] = loc_y[i]+ speed_y[i];//Update for circle's y-coordinate

        //condition 1 bounce off the left side
        if(loc_x[i] < 0){
            speed_x[i] = speed_x[i] * -1;
        }

        if(loc_x[i] > ofGetWidth()){
            speed_x[i] = speed_x[i] * -1;
        }

        if(loc_y[i] < 0){
            speed_y[i] = speed_y[i] * -1;
        }
        if(loc_y[i] > ofGetWidth()){
            speed_y[i] = speed_y[i] * -1;
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    for(int i = 0; i < NUM; i++){
        ofSetColor(red[i], green[i], blue[i], 127);
        ofDrawCircle(loc_x[i], loc_y[i], radius[i]);
    }
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
    mouse_pressed = true; //when the mouse pressed
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mouse_pressed = false; //when the mouse released

    //Initialization of the speed of the circle
    for(int i = 0; i < NUM; i++){
        speed_x[i] = ofRandom(-10,10);
        speed_y[i] = ofRandom(-10,10);
    }
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
