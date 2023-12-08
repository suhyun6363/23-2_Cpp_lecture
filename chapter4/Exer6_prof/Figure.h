#pragma once
#include <memory>
class Application;

// Figure Class
class Figure
{
public:
	Figure(int, int);
	void moveTo(int, int);
	virtual void draw(Application&) = 0;
	// data fields
	int x;
	int y;
};

// Exer: Triangle Class
class Triangle : public Figure {
public:
	Triangle(int, int);
	virtual void draw(Application&);
	// data field
	int length;
};

// Circle Class
class Circle : public Figure
{
public:
	Circle(int, int, int);
	virtual void draw(Application&);
	// data field
	int radius;
};

// Rectangle Class
class Rect : public Figure
{
public:
	Rect(int, int, int, int);
	bool includes(int, int) const;
	virtual void draw(Application&);
	// data fields
	int width;
	int height;
};

using FigurePtr = std::shared_ptr<Figure>;