#include <iostream>
using namespace std;

void squareCube(int& s, int& c) //파라미터형을 reference형으로(&)
{
	s = s * s;
	int temp = c * c;
	c = temp * c;
}

int main()
{
	int number, square, cube;
	cout << "정수 입력: ";
	cin >> number;
	square = cube = number;
	squareCube(square, cube); //int& s = square; int& c = cube;
	cout << number << "의 제곱은 " << square << endl;
	cout << "세제곱은 " << cube << "입니다" << endl;

	return 0;
}