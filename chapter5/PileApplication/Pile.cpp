#include "Pile.h"
#include "pclaf.h"
#include <random>
#include <ctime>
#include <algorithm>

std::mt19937 eng(static_cast<unsigned long>(time(nullptr)));

CardPile::CardPile(int x, int y)
	: upperLeftX(x), upperLeftY(y), count(0)
{}

void CardPile::addCard(const CardPtr& newCard)
{
	if (count < MAX_CARDS) {
		theCards[count] = newCard;
		newCard->moveTo(upperLeftX, upperLeftY);
		count = count + 1;
	}
}

CardPtr CardPile::topCard()
{
	if (count > 0) {
		count = count - 1;
		return theCards[count];
	}
	return nullptr;
}

bool CardPile::includes(int x, int y)
{
	for (int k = count; k > 0; k--) {
		if (theCards[k - 1]->includes(x, y)) {
			return true;
		}
	}
	return false;
}

void CardPile::display(Application& win)
{
	if (count > 0) {
		theCards[count - 1]->draw(win);
	}
	else {
		win.setPen(green);
		win.rectangle(upperLeftX, upperLeftY,
			Card::CardWidth, Card::CardHeight);
	}
}

void CardPile::select()
{}

DeckPile::DeckPile(int a, int b)
	: CardPile(a, b)
{}

void DeckPile::addCard(const CardPtr& newCard) // CardPile addCard 재정의
{
	if (count < MAX_CARDS) {
		CardPile::addCard(newCard);
		newCard->moveTo(upperLeftX, upperLeftY);
		auto it = theCards.begin(); // array<std::shared_ptr<Card>, int>::iterator
		std::advance(it, count); // 가지고 있는 card개수만 shuffle을 하고 싶어 end를 사용할 수 없어 begin과 카드 개수(count)를 파라미터로 주어 반복자를 count만큼 증가시킴
		std::shuffle(theCards.begin(), it, eng);
	}
}