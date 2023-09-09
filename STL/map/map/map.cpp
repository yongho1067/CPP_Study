#include <list>
#include <deque>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 프로젝트 주제 : map

class Player
{
public:
	Player() : _playerId(0) { }
	Player(int playerId) : _playerId(playerId) { }

public:
	int _playerId;

};


int main()
{
	// 연관 컨테이너

	// 10만명 입장
	// Q) ID - 1만인 Player를 찾아주세요

	// vector, list의 치명적인 단점
	// -> 원하는 조건에 해당하는 데이터를 빠르게 찾을 수 없다

	// map : 군형 이진 트리 (AVL)
	// - 노드 기반 

	class Node
	{
	public:
		Node* _left;
		Node* _right;

		// DATA
		// int _key;
		// Player* _value;
		pair<int, Player*> _data;

	};

	srand(static_cast<unsigned int>(time(nullptr)));
	// (Key, Value)
	map<int, int> m;

	m.insert(make_pair(1, 100));
	m.insert(make_pair(1, 200)); // 같은 키값에 이미 벨류가있다면 들어가지 않음

	// 10만명
	for (int i = 0; i < 100000; i++)
	{
		m.insert(pair<int, int>(i, i * 100));
	}

	// 5만명 퇴장
	for (int i = 0; i < 50000; i++)
	{
		int randomVal = rand() % 50000;

		// Erase By Key
		m.erase(randomVal);
	}
	unsigned int count = 0;
	count = m.erase(10000);
	count = m.erase(10000);

	// Q) ID = 1만인 Player 찾고 싶다!
	// A) 매우 빠르게 찾을 수 있음

	

	// map 순회
	
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) 
	{
		pair<const int, int>& p = (*it);
		int key = it->first;
		int value = (*it).second;

		cout << key << " " << value << endl;
	}

	// 없으면 추가, 있으면 수정

	map<int, int>::iterator findIt = m.find(10000);
	if (findIt != m.end())
	{
		findIt->second = 200;
		cout << "찾음" << endl;
	}
	else
	{
		m.insert(make_pair(10000, 10000));
		cout << "못찾음" << endl;
	}
	
	// 없으면 추가, 있으면 수정2
	m[5] = 500;

	m.clear();
	// [] 연산자 사용할 때 주의
	// 대입을 하지 않더라도 (Key/Value) 형태의 데이터가 추가된다!

	for (int i = 0; i < 10; i++)
	{
		// 데이터가 없더라도 키/벨류 형태의 데이터가 강제로 생성시킴
		cout << m[i] << endl;
	}

	return 0;
}
