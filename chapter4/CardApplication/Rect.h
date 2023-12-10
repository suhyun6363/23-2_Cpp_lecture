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
	virtual void draw(Application&);  // virtual�� �������� ��, 3��° ī���� ����� �޶���(�簢�� �׵θ��� �׷���)
	// data fields
	int upperLeftX;
	int upperLeftY;
	int lowerRightX;
	int lowerRightY;
};