#include <iostream>
#include <string>
using namespace std;
#include "Stack.h"

template <typename T, int S>
void reversePrint(Stack<T, S>& stk)
{
	int cnt = stk.length();
	for (int i = 0; i < cnt; ++i) {
		cout << stk.pop() << endl;
	}
}

int main()
{
	{
		Stack<char> charStack;
		charStack.push('e');
		charStack.push('u');
		charStack.push('m');
	}
	// 중간 스코프라 charStack 객체 소멸됨, size 디폴트값
	Stack<string, 20> strStack; // size = 20
	strStack.push(*(new string("doo")));
	strStack.push(*(new string("hun")));
	cout << "length of string stack = " << strStack.length() << endl;
	reversePrint(strStack);
	cout << "length of string stack = " << strStack.length() << endl;

	return 0;
}