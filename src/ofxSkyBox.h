//
// ofxSkyBox.cpp
//
// Created by kalwalt alias Walter Perdan on 27/12/11
// Copyright 2011 http://www.kalwaltart.it/ All rights reserved.
//




#ifndef	SKY_BOX_H
#define SKY_BOX_H

#include "ofMain.h"
#include "ofxCubeMap.h"
//#include "ofShader"

class ofxSkyBox
{


public:

ofxSkyBox();
    void loadCustom(string path, int size);
    void load();

	void draw(float posX, float posY, float posZ, float size);




    void  Draw_Skybox(float x, float y, float z, float width, float height, float length);

    ofxCubeMap cubeMap;
	ofShader cubeshader;

};

#endif
