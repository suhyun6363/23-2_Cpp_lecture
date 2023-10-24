#include "Stack.h"
#include <iostream>

void reversePrint()
{
	Stack charStack(15);
	charStack.push('a');
	charStack.push('b');
	charStack.push('c');
	int cnt = charStack.length();
	for (int k = 0; k < cnt; k++) {
		std::cout << charStack.pop() << std::endl;
	}
}
// 지역객체 charStack 소멸되면서 소멸자 자동 실행되어 stackPtr이 가리키는 배열의 메모리 공간을 환원
// Stack 클래스에서 소멸자를 정의하지 않았다면, charStack 객체의 메모리 공간만 환원되고, stackPtr이 가리키는 배열에 할당된 메모리 공간은
// 환원되지 않은 채 프로그램 종료됨

int main()
{
	reversePrint();

	return 0;
}