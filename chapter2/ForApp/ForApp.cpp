#include <iostream>
#include <string>

int main()
{
	int arr[5] = { 0, 1, 2, 3, 4 };
	std::cout << "�Ϲ� for��" << std::endl;
	for (auto i = 0; i < 5; ++i) // i: �迭�� �ε���
		std::cout << arr[i];
	std::cout << std::endl;

	std::cout << "���� ��� for��" << std::endl;
	for (auto& i : arr)  // ������ ���ҿ� 1�� ���ؾ� ��
		i = i + 1; 
	for (auto i : arr)  // i: �迭�� ����
		std::cout << i;
	//12345
	for (auto i : arr) 
		i = i + 1; 
	for (auto& i : arr)  
		std::cout << i;
	// 01234
	std::cout << std::endl;
	std::string strArr[3] = { "eum", "doo", "hun" };
	for (auto s : strArr) // s: �� ����
		std::cout << s;
	std::cout << std::endl;

	return 0;
}