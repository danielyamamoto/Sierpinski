#pragma once
#include "Pixels.h"

class Line {
private:
	Pixels pixel; // Objeto pixel 
	ofVec2f currentPoint; // Variable que ocupararemos para las funciones setPoint & moveTo
	int x1, y1, x2, y2; // Variables de la línea
	int dx, dy, a, b, d, difE, difNE, UD, dif;
	bool filtro;

public:
	void init();
	void draw();
	void update();
	void createLine(int x1, int y1, int x2, int y2, int r, int g, int b);
	void circleLine(int x, int y, int rad, int r, int g, int b);
	void setPoint(int x, int y);  
	void moveTo(int x, int y); // Nos servirá para ir de una punto a otro
};
