// RECTANGLE CLASS
#pragma once
class Application;

class Rect
{
public:
	// constructor
	Rect(int, int, int, int);
	// operations
	void moveTo(int, int);
	bool includes(int, int);
	virtual void draw(Application&);  // virtual를 제거했을 때, 3번째 카드의 모양이 달라짐(사각형 테두리만 그려짐)
	// data fields
	int upperLeftX;
	int upperLeftY;
	int lowerRightX;
	int lowerRightY;
};