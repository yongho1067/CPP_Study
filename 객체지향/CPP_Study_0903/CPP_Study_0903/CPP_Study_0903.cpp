#include <iostream>
using namespace std;

// 오늘의 주제 : 객체 지향의 시작

// 데이터 + 가공(로직, 동작)

// 객체지향 = 객체
// 객체란? 플레이어, 몬스터, GameRoom, 모든 오브젝트

// Knight를 설계해보자
// - 속성 (데이터) : hp, attack, y, x
// - 기능 (동작) : Move, Attack, Die

// class는 일종의 설계도
class Knight
{
public:
    // 멤버 함수 선언
    void Move(int y, int x);
    void Attack();

    void Die()
    {
        _hp = 0;
        cout << "Die" << endl;
    }

public:
    // 멤버 변수
    int _hp;
    int _attack;
    int _posY;
    int _posX;
};

void Knight::Move(int y, int x)
{
    _posY = y;
    _posX = x;
    cout << "Move" << endl;
}

void Knight::Attack()
{
    cout << "Attack : " << _attack << endl;
}

// Instantiate 객체를 만든다.

int main()
{
    Knight k1;
    Knight k2;

    k1._hp = 100;
    k1._attack = 10;
    k1._posY = 0;
    k1._posX = 0;

    k2._hp = 80;
    k2._attack = 5;
    k2._posY = 1;
    k2._posX = 1;

    k1.Move(2,2);
    k1.Attack();
    k1.Die();

    return 0;
}

