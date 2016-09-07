#include "Sierpinski.h"

void Sierpinski::init() {
	line.init();
}

void Sierpinski::update() {
	line.update();
}

void Sierpinski::draw() {
	line.draw();
}

void Sierpinski::triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
	// Triángulo sencillo (muy rápido, sin embargo, entre más grande sea el sierpinski peores son los cálculos)
	// Entre más grande sea, algunos pixeles se van saliendo del arreglo de la línea
	line.createLine(x1, y1, x2, y2, 0, 0, 0);
	line.createLine(x2, y2, x3, y3, 0, 0, 0);
	line.createLine(x3, y3, x1, y1, 0, 0, 0);

	// Triángulo complejo (tarda un poco más porque entre más grande sea el sierpinski mayores cálculos realiza)
	// Ningun pixel se sale del arreglo de la línea
	//for (int i = 0; i < vertex.size() - 2; i += 3) {
	//	line.setPoint(vertex[i].x, vertex[i].y);
	//	for (int j = 0; j < 3; j++) {
	//		line.moveTo(vertex[i + j].x, vertex[i + j].y);
	//	}
	//	line.moveTo(vertex[i].x, vertex[i].y);
	//}
}

ofVec2f Sierpinski::midPoint(ofVec2f A, ofVec2f B) {
	ofVec2f vec; // Variable temportal para calcular el punto medio
	vec.set((A.x + B.x) / 2, (A.y + B.y) / 2);
	return vec;
}

void Sierpinski::sierpinski(ofVec2f A, ofVec2f B, ofVec2f C, int level) {
	if (level == 0) {
		vertex.push_back(A);
		vertex.push_back(B);
		vertex.push_back(C);
		return;
	}
	else{
		ofVec2f AB = midPoint(A, B);
		ofVec2f BC = midPoint(B, C);
		ofVec2f CA = midPoint(C, A);

		sierpinski(A, AB, CA, level - 1);
		sierpinski(AB, B, BC, level - 1);
		sierpinski(CA, BC, C, level - 1);
	}
	triangle(A.x, A.y, B.x, B.y, C.x, C.y);
}