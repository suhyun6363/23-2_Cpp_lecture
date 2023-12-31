#include "Rect.h"
#include "Stack.h"
#include <memory>

int main()
{
	Stack<Rect> rectStack(10);
	Rect rect1(100, 100, 130, 150);										// 정적 생성
	Rect* rect2 = new Rect(200, 200, 250, 270);							//동적 생성
	std::shared_ptr<Rect> rect3(new Rect(300, 300, 320, 380));			// 공유 포인터 rect3
	cout << rect1 << endl;
	cout << *rect2 << endl;
	cout << *rect3 << endl;
	cout << "Stack - LIFO" << endl;
	rectStack.push(rect1);
	rectStack.push(*rect2);
	rectStack.push(*rect3);
	rectStack.push(Rect(400, 400, 430, 450));
	rectStack.push(Rect());												// Rect 디폴트 생성자 push 
	Rect r1 = rectStack.pop();
	Rect r2 = rectStack.pop();
	Rect r3 = rectStack.pop();
	Rect r4 = rectStack.pop();
	cout << r1 << endl;
	cout << r2 << endl;
	cout << r3 << endl;
	cout << r4 << endl;
	cout << rectStack.pop() << endl;									// pop과 동시에 출력

	delete rect2;
	rect2 = nullptr;
	return 0;
}