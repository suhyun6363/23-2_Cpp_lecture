#include "PenApp.h"

// Exer: global variable
int lineCount = 0;

PenApp::PenApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}
// Exer
void PenApp::mouseDown(int x, int y)
{
	if (lineCount < MAX_LINES) {
		points[lineCount].x = x;
		points[lineCount].y = y;
		lineCount++;
		update();
	}
}

void PenApp::paint()
{
	for (int i = 0; i < lineCount; i++) {
		if(i == 0)
			line(0, 0, points[i].x, points[i].y);
		else
			line(points[i-1].x, points[i-1].y, points[i].x, points[i].y);
	}
}

int mainLAF()
{
	PenApp theApp(TEXT("PENS"), 500, 500, 150, 150);
	theApp.run();

	return 0;
}