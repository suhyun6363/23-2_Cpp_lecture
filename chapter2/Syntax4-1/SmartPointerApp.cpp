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
	// 스마트 포인터 sp1 -> 매니저 객체 -> doohun필드로 가진 string 객체

	shared_ptr<string> sp2 = sp1;
	weak_ptr<string> wp1 = sp2;
	
	// 중간 스코프
	{
		// wp1을 통해 sp2를 sp3으로 복사
		shared_ptr<string> sp3 = wp1.lock();
		if (sp3) {
			cout << "wp1을 통해 sp3 복사 완료" << std::endl;
		}
		shared_ptr<int> sp4 = make_shared<int>(10);
		weak_ptr<string> wp2(sp1);
	} // sp3, sp4, wp2 자동 소멸
	// sp4가 가리키는 정수 방과 매니저 객체 모두 자동 소멸

	cout << "sp1이 가리키는 문자열 출력: " << *sp1 << std::endl;
	sp1.reset();		// 연결 끊김 -> sp1 변수에 nullptr 배정
	sp2 = nullptr; 
	// 전체 scope을 벗어나지 않아 포인터 변수 sp1, sp2의 메모리 방은 존재(소멸 x, nullptr로 배정)
	// 문자열 객체에 접근할 방법이 없어 문자열 객체 자동 소멸
	// wp1이 매니저 객체를 아직 가리키고 있어 매니저 객체는 소멸 x
	shared_ptr<string> sp5 = wp1.lock();
	// sp5 생성은 되나 참조할 문자열 객체가 소멸하여 nullptr 배정됨
	// wp1 변수는 대상 객체가 존재하는지를 조사하는 목적으로 사용됨
	if (sp5) {
		std::cout << "이 문장은 실행되지 않음!" << std::endl;
	}
	wp1.reset();			// wp1과 연결 끊겨 매니저 객체 소멸

	return 0;
}