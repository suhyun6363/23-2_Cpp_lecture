#include "Rect.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class FindAreaRect
{
public:
	bool operator()(Rect& r) {
		return (r.area() >= compareArea ? true : false);
	}

	int compareArea = 0;
};

int main()
{
	vector<Rect> rectVector;
	Rect aRect(30, 40, 70, 70);			// area = 1200
	Rect bRect(100, 90, 130, 150);		// area = 1800
	Rect cRect(20, 30, 50, 50);			// area = 600
	Rect dRect(100, 100, 150, 150);		// area = 2500
	rectVector.push_back(aRect);
	rectVector.push_back(bRect);
	rectVector.push_back(cRect);
	rectVector.push_back(dRect);
	// 면적이 1500 이상인 첫 번째 사각형 찾기
	vector<Rect>::iterator findRect;
	FindAreaRect findAreaRect;
	findAreaRect.compareArea = 1500;
	findRect = find_if(rectVector.begin(), rectVector.end(), findAreaRect);
	// vector<int>::iterator find(vector<int>::iterator first, vector<int>::iterator last, FindAreaRect pred)
	// {
	//		while(first != last) {
	//			if (*first == val)
	//				return first;
	//			++first;
	//		}
	//		return last;
	//	}
	if (findRect != rectVector.end()) {
		cout << "면적이 1500 보다 큰 첫 사각형은 " << *findRect << endl;
	}
	else {
		cout << "면적이 1500보다 큰 사각형 없음" << endl;
	}

	return 0;
}