#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

// 프로젝트 주제 : ovrride, final
class Creature
{
public:
    virtual void Attack() // 최초의 함수는 override 불가
    {
        cout << "Creature!!" << endl;
    }
};


class Player : public Creature
{
public:
    virtual void Attack() override
    {
        cout << "Player!!" << endl;
    }
};

class Knight : public Player
{
public:
    // 재정의(override)
    virtual void Attack() final
    {
        cout << "Knight!!" << endl;
        // _stamina = 200;
    }

    // 오버로딩(overloading) : 함수 이름의 재사용
    void Attack(int a)
    {

    }

private :
    int _stamina = 100;
};


int main()
{
    Creature* c = new Knight();

    c->Attack();


    return 0;
}
