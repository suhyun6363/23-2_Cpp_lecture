//================================================================
// 응용 과제 3을 발전시킴
//================================================================
#pragma once
#include "pclaf.h"
#include <array>
#include <memory>
class Line;

const auto MAX_LINES = 5;

class LineApp : public Application
{
public:
	LineApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void mouseRDown(int, int);
	void paint();
	// data fields
	std::array<std::shared_ptr<Line>, MAX_LINES> lines;
	int lineCount = 0;
};