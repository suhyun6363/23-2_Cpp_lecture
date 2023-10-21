// 응용 과제 5를 발전시킴
// 마우스의 왼쪽 버튼 클릭점을 잇는 선이 연속으로 다섯 개까지 그려짐

#pragma once
#include "pclaf.h"
#define MAX_LINES	5

// Exer
struct Pt
{
	int x = 0;
	int y = 0;
};

class PenApp : public Application
{
public:
	PenApp(const TCHAR*, int, int, int, int);
	void mouseDown(int, int);
	void paint();
	// Exer: data fields
	Pt points[MAX_LINES];
};