#include "CardApp.h"

CardApp::CardApp(const TCHAR* apName)
	: Application(apName)
{}

CardApp::CardApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}

void CardApp::mouseDown(int x, int y)
{
	if (b.includes(x, y))
		b.flip();
	
	if (c->includes(x, y)) {
		CardPtr k = std::static_pointer_cast<Card>(c);				
		k->flip();
	}
	
	clearAndUpdate();
}

void CardApp::paint()
{
	a.draw(*this);
	b.draw(*this);
	// c->draw(*this);					// draw 일반함수: Rect 클래스 draw 실행, 가상함수: Card 클래스 draw 실행
	
	CardPtr k = std::static_pointer_cast<Card>(c);
	k->draw(*this);							// draw 함수가 일반함수든 가상함수든 Card 클래스 draw 실행 
	
}

// pclaf program entry point
int mainLAF()
{
	CardApp theApp(TEXT("CARDS"));
	theApp.run();

	return 0;
}