#pragma once
#include "ofMain.h"
#include "ofMath.h"

class Pixels {
	ofPixels pix;
	ofTexture tex;

public:
	void putPixel(int x, int y, int r, int g, int b);
	void getPixel();
	void init();
	void draw();
};