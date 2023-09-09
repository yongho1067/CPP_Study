#include <vector>
#include <map>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

// 프로젝트 주제 : 중괄호 초기화 { }


class Knight
{

public:
    Knight()
    {

    }
    Knight(int a, int b)
    {
        cout << "Knight(int,int)" << endl;
    }

    Knight(initializer_list<int> li)
    {
        cout << "Knight(initializer)" << endl;
    }

};

int main()
{
    // 중괄호 초기화 { }
    int a = 0;
    int b(0);
    int c{ 0 };

    Knight k1;
    Knight k2 = k1; // 복사 생성자 { 대입 연산자X }

    Knight k3{ k1 };
    
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    vector<int> v2(10, 1);

    int arr[] = { 1,2,3 };

    vector<int> v3{ 1,2,3,4 };

    // 중괄호 초기화
    // 1) vector 등 container와 잘 어울린다.
    // 2) 축소 변환 방지
    int x = 0;
    //double y{ x };

    // 3) 보나스
    Knight k4{ };
    Knight k5{1,2};

    // 괄호 초기화 {} 를 기본으로 간다
    // - 전통적인 C++ (거부감이 없음)
    // - vector 등 특이한 케이스에 대해서만 { } 사용

    // 중괄호 초기화 { }를 기본으로 간다
    // - 초기화 문법의 일치화
    // - 축소 변환 방지


    return 0;
}
