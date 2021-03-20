/*
 *  ofxCubeMap.cpp
 *  bubbleShaderTests
 *
 *  Created by base on 14/02/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxCubeMap.h"


void ofxCubeMap::loadFromOfImages( ofImage pos_x, ofImage pos_y, ofImage pos_z, ofImage neg_x,ofImage neg_y,ofImage neg_z)
{	

	//create a texture object
	glGenTextures(1, &textureObject);
	glBindTexture(GL_TEXTURE_CUBE_MAP_ARB, textureObject);
	
	unsigned char * data_px, * data_nx, * data_py, * data_ny, * data_pz, * data_nz;
	
	const int img_size = pos_x.getWidth();
	
	data_px = new unsigned char [img_size * img_size * 3];
	data_nx = new unsigned char [img_size * img_size * 3];
	data_py = new unsigned char [img_size * img_size * 3];
	data_ny = new unsigned char [img_size * img_size * 3];
	data_pz = new unsigned char [img_size * img_size * 3];
	data_nz = new unsigned char [img_size * img_size * 3];
	
	data_px = pos_x.getPixels().getData();
	data_nx = neg_x.getPixels().getData();
	data_py = pos_y.getPixels().getData();
	data_ny = neg_y.getPixels().getData();
	data_pz = pos_z.getPixels().getData();
	data_nz = neg_z.getPixels().getData();



	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_px); // postive x
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_nx); // negative x
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_py); // postive y
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_ny); // negative y
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_nz); // negative z
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB, 0, GL_RGB, img_size, img_size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_pz); // positive z

	glGenerateMipmap(GL_TEXTURE_CUBE_MAP_ARB);
	
	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MAG_FILTER, GL_NEAREST);		// Set far filtering mode
	glTexParameteri(GL_TEXTURE_CUBE_MAP_ARB, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);     // Set near filtering mode


}

void ofxCubeMap::loadFromImage(int size, string img_path) {
	ofImage source_image;
 	ofImage images[6];

  	source_image.loadImage(img_path);

  	images[0].cropFrom(source_image, size*2,size,size,size);
  	images[0].save("crop_1.png");
  	images[0].loadImage("crop_1.png");
 	images[1].cropFrom(source_image, 0,size,size,size);
 	images[1].save("crop_2.png");
 	images[1].loadImage("crop_2.png");
  	images[2].cropFrom(source_image, size,0,size,size);
  	images[2].save("crop_3.png");
  	images[2].loadImage("crop_3.png");
    images[3].cropFrom(source_image, size,size*2,size,size);
   	images[3].save("crop_4.png");
   	images[3].loadImage("crop_4.png");
    images[4].cropFrom(source_image, size,size,size,size);
	images[4].save("crop_5.png");
	images[4].loadImage("crop_5.png");
	images[5].cropFrom(source_image, size*3,size,size,size);
	images[5].save("crop_6.png");
	images[5].loadImage("crop_6.png");

	 	loadFromOfImages(images[0],
						 images[2],
						 images[4],
						 images[1],
						 images[3],
						 images[5]);
 
}
