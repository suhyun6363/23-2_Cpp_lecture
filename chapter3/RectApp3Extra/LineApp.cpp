#include "LineApp.h"
#include "Line.h"


bool firstClick = true;
bool sorting = false;
int tempX, tempY;

LineApp::LineApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}
// 응용 과제 3
void LineApp::mouseDown(int x, int y)
{
	if (lineCount < MAX_LINES) {
		if (firstClick) {
			tempX = x;
			tempY = y;
			firstClick = false;
		}
		else {
			lines[lineCount] = std::make_shared<Line>(tempX, tempY, x, y);
			firstClick = true;
			lineCount++;
		}
		clearAndUpdate();
	}
}

void LineApp::mouseRDown(int x, int y)
{
	lines[lineCount - 1]->moveTo(x, y);
	clearAndUpdate();
}

void LineApp::paint()
{
	// 응용 과제 3
	for (int i = 0; i < lineCount; ++i)
		lines[i]->draw(*this);
}

int mainLAF()
{
	LineApp theApp(TEXT("LINES"), 750, 500, 150, 150);
	theApp.run();

	return 0;
}