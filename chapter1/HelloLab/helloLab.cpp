#include <iostream>

int main() {
	char name[15];
	int age;

	std::cout << "�̸��� ���̸� �Է��ϼ���." << std::endl;
	std::cout << "�̸� : ";
	std::cin >> name;
	std::cout << "���� : ";
	std::cin >> age;

	if (age <= 18) 
		std::cout << name << "���� " << age << "�� �̼����Դϴ�." << std::endl;
	else 
		std::cout << name << "���� " << age << "�� �����Դϴ�." << std::endl;

	system("pause");
	return 0;
};