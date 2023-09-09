#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 프로젝트 주제 : list

// vector : 동적 배열
// [            ]
// [            ]        ]

//class Node2
//{
//public:
//
//public:
//    Node2 _next;
//    int _data;
//};

class Node
{

public:

public:
    Node*   _next;
    Node*   _prev;
    int     _data;

};

// 단일 / 이중 / 원형
// list : 연결 리스트

// [1]   ->   [2] -> [3]   ->   [4]    ->     [5]
// [1]   <->   [2] <-> [3]   <->   [4]    <->     [5]

int main()
{
    // 벡터는 동적 배열 방식
    // 리스트는 노드 배열 방식

    // 면접에서도 벡터와 리스트의 차이를 자주 물어본다

    // list (연결 리스트)
    // - list의 동작 원리
    // - 중간 삽입/삭제
    // - 처음/끝 삽입/삭제
    // - 임의 접근

    list<int>li;

    for(int i = 0; i<100; i++)
        li.push_back(i);

    // li.push_front(10);
    int size = li.size();

    // 용량의 개념이 존재하지 않음
    // li.capacity();

    int first = li.front();
    int last = li.back();

    list<int>::iterator itBegin = li.begin();
    list<int>::iterator itEnd = li.end();

    for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
    {
        cout << *it << endl;
    }

    li.insert(itBegin, 100);

    li.erase(li.begin());
    li.pop_front();

    // ()안에 들어가있는 값과 동일한 데이터들을 모두 삭제함
    li.remove(10);


    return 0;
}
