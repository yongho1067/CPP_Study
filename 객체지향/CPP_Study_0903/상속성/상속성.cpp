#include <iostream>
using namespace std;

// 프로젝트 주제 : 상속성

// 객체지향 (OOP Object Orient Programming)
// - 상속성
// - 은닉성
// - 다형성

struct StatInfo
{
    int hp;
    int attack;
    int def;
};

// 상속(Ingeritance) ? 부모 -> 자식에게 유산을 물려주는 것

class Player
{
public:
    void Move() { cout << "Player Move 호출" << endl; }
    void Attack() { cout << "Player Attack 호출" << endl; }
    void Die() { cout << "Player Die 호출" << endl; }

public:
    int _hp;
    int _attack;
    int _def;
};

// class는 일종의 설계도
class Knight : public Player
{
public:

};

class Mage : public Player
{
public:
    
};

int main()
{
    
}
