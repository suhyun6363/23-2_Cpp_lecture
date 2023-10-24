#include <iostream>
#include <string>
#include <memory>
using std::shared_ptr;
using std::weak_ptr;
using std::make_shared;
using std::cout;
using std::endl;
using std::string;

int main()
{
	// ver1
	// shared_ptr<string> sp1(new string("doohun"));
	// ver2
	string* str = new string("doohun");
	shared_ptr<string> sp1(str);
	// ����Ʈ ������ sp1 -> �Ŵ��� ��ü -> doohun�ʵ�� ���� string ��ü

	shared_ptr<string> sp2 = sp1;
	weak_ptr<string> wp1 = sp2;
	
	// �߰� ������
	{
		// wp1�� ���� sp2�� sp3���� ����
		shared_ptr<string> sp3 = wp1.lock();
		if (sp3) {
			cout << "wp1�� ���� sp3 ���� �Ϸ�" << std::endl;
		}
		shared_ptr<int> sp4 = make_shared<int>(10);
		weak_ptr<string> wp2(sp1);
	} // sp3, sp4, wp2 �ڵ� �Ҹ�
	// sp4�� ����Ű�� ���� ��� �Ŵ��� ��ü ��� �ڵ� �Ҹ�

	cout << "sp1�� ����Ű�� ���ڿ� ���: " << *sp1 << std::endl;
	sp1.reset();		// ���� ���� -> sp1 ������ nullptr ����
	sp2 = nullptr; 
	// ��ü scope�� ����� �ʾ� ������ ���� sp1, sp2�� �޸� ���� ����(�Ҹ� x, nullptr�� ����)
	// ���ڿ� ��ü�� ������ ����� ���� ���ڿ� ��ü �ڵ� �Ҹ�
	// wp1�� �Ŵ��� ��ü�� ���� ����Ű�� �־� �Ŵ��� ��ü�� �Ҹ� x
	shared_ptr<string> sp5 = wp1.lock();
	// sp5 ������ �ǳ� ������ ���ڿ� ��ü�� �Ҹ��Ͽ� nullptr ������
	// wp1 ������ ��� ��ü�� �����ϴ����� �����ϴ� �������� ����
	if (sp5) {
		std::cout << "�� ������ ������� ����!" << std::endl;
	}
	wp1.reset();			// wp1�� ���� ���� �Ŵ��� ��ü �Ҹ�

	return 0;
}