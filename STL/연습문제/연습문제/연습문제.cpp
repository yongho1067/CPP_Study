#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <set>
using namespace std;

#include <algorithm>

// 프로젝트 주제 : 연습 문제 / 알고리즘

int main()
{

	// 자료구조 (데이터를 저장하는 구조)
	// 알고리즘 (데이터를 어떻게 사용할 것인가?)

	// find
	// find_if
	
	// count
	// count_if
	// all_of
	// any_of
	// none_of
	// for_each
	// remove
	// remove_if

	srand(static_cast<unsigned int>(time(nullptr)));

	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		int num = rand() % 100;

		v.push_back(num);
	}

	// Q1) num이라는 숫자가 벡터에 체크하는 기능 ( bool, 첫 등장 iterator)
	{
		int num = 50;

		bool found = false;
		vector<int>::iterator it = v.end();

	
		for (int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			if (data == num)
			{
				found = true;
				it = v.begin() + i;
				break;
			}
		}

		// 찾을 데이터의 범위 지정
		// begin을 포함하여 시작하여
		// end 이전까지의 데이터 범위 중에서
		// num이라는 데이터를 찾아라

		vector<int>::iterator itfind = find(v.begin(), v.end(), num);

		if (itfind == v.end())
		{
			cout << "못찾았음" << endl;
		}
		else
		{
			cout << "찾았음" << endl;
		}

	}

	// Q2) 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능 (bool, 첫 등장 iterartor)
	{
		bool found = false;
		vector<int>::iterator it = v.end();

		for (int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			if ((data % 11) == 0)
			{
				found = true;
				it = v.begin() + i;
				break;
			}
		}
		
		struct CanDivideBy11
		{
			bool operator()(int n) 
			{
				return (n % 11) == 0;
			}
		};

		vector<int>::iterator itFind =find_if(v.begin(), v.end(), CanDivideBy11());
		if (itFind == v.end())
		{
			cout << "못찾았음" << endl;
		}
		else
		{
			cout << "찾았음" << endl;
		}
	}

	// Q3) 홀수인 숫자의 개수는? (count)
	{
		int count = 0;

		for (int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			if (data% 2 != 0)
			{
				count++;
			}
		}


	}

	// Q4) 벡터에 들어가 있는 모든 숫자들에 3을 곱해주세요
	{
		for (int i = 0; i < v.size(); i++)
		{
			v[i] *= 3;
		}

	}

	// Q5) 홀수인 데이터를 일괄 삭제하고 싶어요
	{
		/*for (vector<int>::iterator it = v.begin(); it != v.end();)
		{
			if ((*it % 2) != 0)
			{
				it = v.erase(it);
			}
			else
			{
				++it;
			}
		}*/
	}


	return 0;
}
