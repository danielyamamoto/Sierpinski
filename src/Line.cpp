#include "Line.h"

void Line::init() {
	pixel.init();
}

void Line::draw() {
	pixel.draw();
}

void Line::update() {
	pixel.getPixel();
}

void Line::createLine(int x1, int y1, int x2, int y2, int r, int g, int b) {
	if (x1 > x2) { // Invierte x
		int xNew = x1;
		int yNew = y1;

		x1 = x2;
		y1 = y2;

		x2 = xNew;
		y2 = yNew;
	}

	if (y1 > y2) { // Invierte y
		dif = -1;
		dy = y1 - y2;
	}
	else {
		dy = y2 - y1;
		dif = 1;
	}
	dx = x2 - x1;
	if (dy >= dx) { //  Base mayor 
		a = dx;
		b = -dy;
		UD = x1;
		filtro = true;
	}
	else {
		a = dy;
		b = -dx;
		UD = y1;
		filtro = false;
	}

	d = 2 * a + b;
	difE = 2 * a;
	difNE = 2 * a + 2 * b;
	pixel.putPixel(x1, y2, r, g, b);

	if (!filtro) {
		for (int x = x1 + 1; x <= x2; x++) {
			if (d < 0) {
				d += 2 * a;
			}
			else {
				d += 2 * a + 2 * b;
				UD += dif;
			}
			pixel.putPixel(x, UD, r, g, b);
		}
	}
	else {
		int decision;
		int otra = y2 *= dif;
		for (int y = y1 + dif; (decision = y*dif) <= (otra); y += dif) {
			if (d < 0) {
				d += 2 * a;
			}
			else {
				d += 2 * a + 2 * b;
				UD++;
			}
			pixel.putPixel(UD, y, r, g, b);
		}
	}
}

void Line::circleLine(int x, int y, int rad, int r, int g, int b) {
	float angulo;
	int x2 = 0;
	int y2 = 0;

	for (int angulos = 0; angulos < 360; angulos++) {
		angulo = rad*cos(angulos);
		x2 = round(angulo);
		angulo = rad*sin(angulos);
		y2 = round(angulo);
		createLine(x, y, x + x2, y + y2, r, g, b);
	}
}

void Line::setPoint(int x, int y) {
	currentPoint.set(x, y);
}

void Line::moveTo(int x, int y) {
	createLine(currentPoint.x, currentPoint.y, x, y, 0, 0, 0);
	setPoint(x, y);
}