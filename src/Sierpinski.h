#pragma once
#include "Line.h"

class Sierpinski {
private:
	Line line;
	vector<ofVec2f> vertex;

public:
	void init();
	void update();
	void draw();
	void triangle(int x1, int y1, int x2, int y2, int x3, int y3);
	ofVec2f midPoint(ofVec2f A, ofVec2f B); // Calcula el punto medio de dos coordenas (una recta)
	void sierpinski(ofVec2f A, ofVec2f B, ofVec2f C, int level);
};