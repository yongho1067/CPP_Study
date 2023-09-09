#include <vector>
#include <map>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

// 프로젝트 주제 : using
// typedef 대신 사용 가능한 using

typedef vector<int>::iterator VecIt;
typedef int id;

using id2 = int;

// 1) 직관성
typedef void (*MyFunc)();
using MyFunc2 = void(*)();

// 2) 템플릿
template<typename T>
using List = list<T>;

int main()
{
	id playerId = 0;
	List<int> li;

	li.push_back(1);
	li.push_back(2);
	li.push_back(3);


	return 0;
}

