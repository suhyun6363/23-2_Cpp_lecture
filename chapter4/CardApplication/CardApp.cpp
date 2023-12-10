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
	// c->draw(*this);					// draw �Ϲ��Լ�: Rect Ŭ���� draw ����, �����Լ�: Card Ŭ���� draw ����
	
	CardPtr k = std::static_pointer_cast<Card>(c);
	k->draw(*this);							// draw �Լ��� �Ϲ��Լ��� �����Լ��� Card Ŭ���� draw ���� 
	
}

// pclaf program entry point
int mainLAF()
{
	CardApp theApp(TEXT("CARDS"));
	theApp.run();

	return 0;
}