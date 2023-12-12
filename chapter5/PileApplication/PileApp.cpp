#include "PileApp.h"

PileApp::PileApp(const TCHAR* apName)
	: Application(apName)
{}

PileApp::PileApp(const TCHAR* apName, int width, int height, int x, int y)
	: Application(apName, width, height, x, y)
{}

void PileApp::mouseDown(int x, int y)
{
	if (theDeck.includes(x, y)) {
		CardPtr deckTop = theDeck.topCard();
		theDiscard.addCard(deckTop);
	}
	if (theDiscard.includes(x, y)) {
		CardPtr discardTop = theDiscard.topCard();
		discardTop->flip();
		theDiscard.addCard(discardTop);
	}
	clearAndUpdate();
}

void PileApp::paint()
{
	theDeck.display(*this); // this = theApp 按眉
	theDiscard.display(*this);
}

// pclaf program entry point
int mainLAF()
{
	PileApp theApp(TEXT("PILES"));
	// 墨靛 积己 饶 单农 颇老俊 火涝
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 13; j++)
			theApp.theDeck.addCard(std::make_shared<Card>(0, 0, i, j)); // 悼利 积己
	theApp.run();

	return 0;
}