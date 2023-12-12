// Refined Pile Classes - console version
// 복사 시맨틱 활성화 클래스
#pragma once
#include "Card.h"
#include <array>

const int MAX_CARDS = 52;

// Refined CardPile Class - console version
class CardPile
{
public:
	// 생성자 함수, 파라미터는 왼쪽위 꼭짓점
	CardPile(int, int);
	// 복사 생성자 함수: 자기와 같은 타입의 파라미터를 받음
	CardPile(const CardPile&);
	// 이동 생성자 함수 - 없어도 되지만 성능을 개선하기 위함 option절
	CardPile(CardPile&&);
	// 소멸자 함수
	virtual ~CardPile();
	// 연산
	virtual CardPtr topCard();
	virtual void addCard(const CardPtr&);
	bool includes(int, int);
//	virtual void display(Application&);				// console version
	virtual void select(); // 6장에서 필요
	// 복사 배정 연산자: 자기랑 같은 타입의 CardPile 타입의 파라미터를 받음 -> 따로 정의하지 않으면 컴파일러가 디폴트로 복사 생성자와 디폴트 배정 연산자를 생성
	CardPile& operator=(const CardPile&);
	// 이동 배정 연산자
	CardPile& operator=(CardPile&&);
	void moveTo(int x, int y);
	// 접근 함수
	int getUpperLeftX() const;
	int getUpperLeftY() const;
	int getCount() const;
	// 변경 함수
	void setUpperLeftX(int);
	void setUpperLeftY(int);
	// console version
	friend std::ostream& operator<<(std::ostream&, const CardPile&);
protected:
	// 멤버 변수
	int upperLeftX;
	int upperLeftY;
	int count;
	std::array<CardPtr, MAX_CARDS> theCards;
};

// Refined DeckPile Class - console version
class DeckPile : public CardPile
{
public:
	// 생성자 함수
	DeckPile(int, int);
	// 연산
	virtual void addCard(const CardPtr&);
};

// console version
extern std::ostream& operator<<(std::ostream&, const CardPile&);
typedef std::shared_ptr<CardPile> CardPilePtr;