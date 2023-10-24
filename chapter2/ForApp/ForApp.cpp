#include <iostream>
#include <string>

int main()
{
	int arr[5] = { 0, 1, 2, 3, 4 };
	std::cout << "일반 for문" << std::endl;
	for (auto i = 0; i < 5; ++i) // i: 배열의 인덱스
		std::cout << arr[i];
	std::cout << std::endl;

	std::cout << "범위 기반 for문" << std::endl;
	for (auto& i : arr)  // 각각의 원소에 1을 더해야 함
		i = i + 1; 
	for (auto i : arr)  // i: 배열의 원소
		std::cout << i;
	//12345
	for (auto i : arr) 
		i = i + 1; 
	for (auto& i : arr)  
		std::cout << i;
	// 01234
	std::cout << std::endl;
	std::string strArr[3] = { "eum", "doo", "hun" };
	for (auto s : strArr) // s: 각 원소
		std::cout << s;
	std::cout << std::endl;

	return 0;
}