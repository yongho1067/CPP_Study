#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
using namespace std;
#include <set>

// 프로젝트 주제 : set, multimap ,multiset

int main()
{
	// map (Key / Value)
	map<int, int> m;

	// set (Key=value)
	set<int> s;

	// 넣고
	// 빼고
	// 찾고
	// 순회하고

	// 넣기 기능
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(40);
	s.insert(50);
	s.insert(60);
	s.insert(70);
	s.insert(80);
	s.insert(90);

	// 빼기 기능
	s.erase(10);

	// 찾기 기능
	set<int>::iterator findIt = s.find(50);
	
	if (findIt == s.end())
	{
		cout << "못찾음" << endl;
	}
	else
	{
		cout << "찾음" << endl;
	}



	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << (*it) << endl;
	}

	cout << "===========================경계선===============================" << endl;

	multimap<int, int> mm;
	
	// 넣기 기능
	mm.insert(make_pair(1, 100));
	mm.insert(make_pair(1, 200));
	mm.insert(make_pair(1, 300));
	mm.insert(make_pair(2, 400));
	mm.insert(make_pair(2, 500));
	mm.insert(make_pair(2, 600));

	// mm[1] = 500;

	// 뺴기 기능
	unsigned int count = mm.erase(1);

	// 찾기 기능
	multimap<int, int>::iterator itFind = mm.find(1);
	if (itFind != mm.end())
	{
		cout << "찾음" << endl;
		mm.erase(itFind);
	}
	else
	{
		cout << "못차ㅣㅈ음" << endl;
	}

	mm.equal_range(1);

	multiset<int> ms;

	// 넣기기능
	ms.insert(100);
	ms.insert(200);
	ms.insert(300);
	ms.insert(400);
	ms.insert(500);


	return 0;
}
