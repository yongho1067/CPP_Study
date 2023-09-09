#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <set>
using namespace std;

// 프로젝트 주제 : 연습 문제

int main()
{
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


	return 0;
}
