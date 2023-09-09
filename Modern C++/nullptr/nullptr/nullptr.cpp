#include <vector>
#include <map>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

// 프로젝트 주제 : nullptr

class Knight
{
public:
    void Test()
    {

    }
};

Knight* FindKnight()
{
    return nullptr;
}

void Test(int a)
{
    cout << "Test(int)" << endl;
}

void Test(void* ptr)
{
    cout << "Test(*)" << endl;
}

class Nullptr
{

public:
    // 그 어떤 타입의 포인터와도 치환 가능 
    template<typename T>
    operator T* () const
    {
        return 0;
    }

    // 그 어떤 타입의 멤버 포인터가 와도 치환 가능
    template<typename C, typename T>
    operator T C ::* () const
    {

        return 0;
    }

private:
    void operator&() const; // 주소값 &를 막는다
};

const Nullptr _Nullptr;

int main()
{
    // 0 NULL
    int* ptr = NULL;

    // 1) 오동작 방지
    Test(0);
    Test(NULL);
    Test(_Nullptr);

    // 2) 가독성
    auto knight = FindKnight();
    if (knight == _Nullptr)
    {

    }
    void (Knight:: * memFunc)();
    memFunc = &Knight::Test;

    if (memFunc == _Nullptr)
    {

    }

    auto whoami = _Nullptr;
    auto whoami2 = NULL;

    return 0;
}
