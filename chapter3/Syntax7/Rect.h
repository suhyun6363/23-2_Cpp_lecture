// Refined Rect Class- console version
#pragma once
//class Application;
#include <iostream>						// console version
using std::cout; using std::endl;

class Rect
{
public:
	// 생성자 함수
	Rect(int, int, int, int);
	Rect();
	// 타입 변환
	Rect(int);
	operator int();
	// 소멸자 함수
	virtual ~Rect();
	// 연산
	void moveTo(int, int);
	bool includes(const int, const int);
//	virtual void draw(Application&);		// console version
	int area() const;
	// 연산자 오버로딩(멤버 함수)
	bool operator>(const Rect&);
	Rect& operator++();
	Rect operator++(int);
	// 접근 함수
	int getUpperLeftX() const;
	int getUpperLeftY() const;
	int getLowerRightX() const;
	int getLowerRightY() const;
	// 변경 함수
	void setUpperLeftX(int);
	void setUpperLeftY(int);
	void setLowerRightX(int);
	void setLowerRightY(int);
protected:
	// 멤버 변수
	int upperLeftX;
	int upperLeftY;
	int lowerRightX;
	int lowerRightY;
};
// 전역 함수
extern bool operator<(const Rect&, const Rect&);
extern Rect& operator--(Rect&);
extern Rect operator--(Rect&, int);
// console version
extern std::ostream& operator<<(std::ostream&, const Rect&); // cout 객체로 바로 출력