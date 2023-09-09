#include <iostream>
#include <vector>
using namespace std;

// 프로젝트 주제 : vector

int main()
{
	// 컨테이너(Container) : 데이터를 저장하는 객체 ( 자료구조 Data Structure )

	// vector (동적 배열)
	// - vector의 동작 원리 (size/capacity)
	// - 중간 삽입/삭제
	// - 처음/끝 삽입/삭제
	// - 임의 접근

	// 반복자(Iterator) : 포인터와 유사한 개념. 컨테이너의 원소(데이터)를 가리키고, 다음/이전 원소로 이동 가능
	vector<int> v(10);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		v[i] = i;
	}

	vector<int>::iterator it;
	int* ptr;

	it = v.begin();
	ptr = &v[0];

	cout << (*it) << endl;
	cout << (*ptr) << endl;

	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();


	return 0;
}
