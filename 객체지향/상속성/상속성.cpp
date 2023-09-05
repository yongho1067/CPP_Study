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

// 메모리
// [ [ Player ] ]
// [    Knight  ]

// 상속(Ingeritance) ? 부모 -> 자식에게 유산을 물려주는 것

// 생성자(N)/소멸자(1)

// 생성자는 탄생을 기념해서 호출되는 함수?
// - Knight를 생성하면 -> Player의 생성자? Knight의 생성자?
// -> 둘다 호출됨

class Player
{
public:
    // 기본 생성자
    Player()
    {
        _hp = 0;
        _attack = 0;
        _def = 0;

        cout << "Player() 기본 생성자 호출" << endl;
    }

    ~Player()
    {
        cout << "Player() 소멸자 호출" << endl;
    }

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
    Knight()

        /*
        선(먼저)처리 영역
        - 여기서 Player () 생성자 호출
        */
    {
        _stamina = 0;
        cout << "Knight() 기본 생성자 호출" << endl;
    }

    ~Knight()
    {
        cout << "Knight() 소멸자 호출" << endl;
    }
    /*
        후(나중)처리 영역
        - 여기서 Player () 소멸자 호출
        */

    // 재정의 : 상속받은 유산을 거부하고 본인만의 것을 만듬
    void Move() { cout << "Knight Move 호출 " << endl; }

public:
    int _stamina;

};

class Mage : public Player
{
public:

public:
    int _mp;
    
};

int main()
{
    Knight k;

    k._hp = 100;
    k._attack = 10;
    k._def = 10;
    k._stamina = 50;
    
    //k.Move();
    //k.Player::Move();
    
    //k.Attack();
    //k.Die();

    return 0;
}
