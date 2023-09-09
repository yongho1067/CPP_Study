#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

// 프로젝트 주제 : 오른값(rvalue) 참조와 std::move

class Knight
{
public:

    void Printinfo()
    {

    }

public:
    int _hp = 100;
};

void Test(Knight knight)
{
    knight._hp = 200; // 원본 데이터에는 아무런 의미가 없음
}

void Test2(Knight& knight)
{
    knight._hp = 200; // 원본 데이터에 적용이 됨

}

void Test3(const Knight& knight)
{
    // const가 선언되어있어 데이터를 수정할수없음
}

void Test4(Knight&& knight) //오른값 참조
{
    knight._hp = 200; // 원본 데이터에 적용이 됨

}

int main()
{
    // 왼값 (lvalue) vs 오른값 (rvalue)
    // - lvalue : 단일식을 넘어서 계속 지속되는 개체
    // - rvalue : lvalue가 아닌 나머지 (임시 값, 열거형, 람다, i++등)

    int a = 3;
    float b = 3.14f;
    double c = 3.14;
    const char* d = "Hello";

    Knight k1;

    Test(k1);
    Test2(k1);
    Test3(Knight());

    //Test4(k1); // 일반적인 왼값참조는 불가능함
    Test4(Knight());
    Test4(static_cast<Knight&&>(k1));


    return 0;
}

