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
	cout << "�� ���� �� ū ���� " << k << "�Դϴ�." << endl;
	float x = 250.0f;
	float y = 250.57f;
	float z = max(x, y);
	cout << "�� �Ǽ� �� ū ���� " << z << "�Դϴ�." << endl;

	int m = max(i, x); //(int, float) - �� ���� ���ø� �Ķ���͸� ����ϴ� max ���ø� �Լ��� ����ؾ� ��
	cout << "�� �Ǽ� �� ū ���� " << m << "�Դϴ�." << endl;

	return 0;
}