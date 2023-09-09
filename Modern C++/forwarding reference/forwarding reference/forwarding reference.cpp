#include <list>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

// 프로젝트 주제 : 전달 참조 (forwarding reference)

class Knight
{
public:
    Knight() { cout << "기본 생성자" << endl; }
    Knight(const Knight&) { cout << "복사 생성자" << endl; }
    Knight(Knight&&) noexcept { cout << "이동 생성자" << endl; }

public:

};

template<typename T>
void Test_ForwardingRef(T&& param) // 전달 참조
{

}

void Test_RvalueRef(Knight&& k) // 오른값 참조
{

}

int main()
{
    // 보편 참조 ( universal reference )
    // 전달 참조 ( forwarding reference) C++17

    // && &를 두번 -> 오른값 참조
    Knight k1;

    Test_RvalueRef(move(k1));

    Knight* k2 = new Knight();

    Knight k3;

    Test_ForwardingRef(k1);

    auto&& k4 = k1;
    auto&& k5 = move(k1);

    // 공통점 : 형식 연역(type deduction)이 일어날 때



    return 0;
}
