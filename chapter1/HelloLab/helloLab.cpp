#include <iostream>

int main() {
	char name[15];
	int age;

	std::cout << "이름과 나이를 입력하세요." << std::endl;
	std::cout << "이름 : ";
	std::cin >> name;
	std::cout << "나이 : ";
	std::cin >> age;

	if (age <= 18) 
		std::cout << name << "님은 " << age << "살 미성년입니다." << std::endl;
	else 
		std::cout << name << "님은 " << age << "살 성년입니다." << std::endl;

	system("pause");
	return 0;
};