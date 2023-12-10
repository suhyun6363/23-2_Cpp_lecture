// CARD CLASS
#pragma once
#include "Rect.h"
#include <memory>

class Card : public Rect
{
public:
	// constructor
	Card(int, int, int, int);
	// operations
	virtual void draw(Application&);
	void flip();
	// static data fields	
	static const int CardWidth = 75;		// static 멤버 변수 → 객체 생성 없이도 접근 가능  Card::CardWidth
	static const int CardHeight = 100;
	// data fields
	int suit;
	int rank;
	bool faceUp;
};

typedef std::shared_ptr<Card> CardPtr;