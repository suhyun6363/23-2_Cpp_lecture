// ���� ���� 5�� ������Ŵ
// ���콺�� ���� ��ư Ŭ������ �մ� ���� �������� �ټ� ������ �׷���

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