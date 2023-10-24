#include <iostream>
using std::cout;
using std::endl;

template <typename T>
const T& max(const T& a, const T& b)
{
	if (a > b)
		return a;
	return b;
}

template <typename T1, typename T2>
const T1& max(const T1& a, const T2& b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	int i = 300;
	int j = 400;
	int k = max(i, j);
	cout << "두 정수 중 큰 값은 " << k << "입니다." << endl;
	float x = 250.0f;
	float y = 250.57f;
	float z = max(x, y);
	cout << "두 실수 중 큰 값은 " << z << "입니다." << endl;

	int m = max(i, x); //(int, float) - 두 개의 템플릿 파라미터를 사용하는 max 템플릿 함수를 사용해야 함
	cout << "두 실수 중 큰 값은 " << m << "입니다." << endl;

	return 0;
}