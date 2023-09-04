﻿#include <iostream>
using namespace std;

// 오늘의 주제 : 생성자와 소멸자
// [생성자(Constructor)와 소멸자 (Destructor)]
// 클래스에 ' 소속'된 함수들을 멤버 함수라고 함
// 이중에서 굉장히 특별한 함수 2종이 있는데, 바로 [시작]과 [끝]을 알리는 함수들
// - 시작(탄생) -> 생성자 (여러개 존재 가능)
// -끝(소멸) -> 소멸자 ( 오직 1개만 존재가능)

// [암시적 생성자] (implicit)
// 생성자를 명시적으로 만들지 않으면,
// 아무 인자도 받지 않는 [기본 생성자]가 컴파일러에 의해 자동으로 만들어짐.
// -> 그러나 우리가 명시적으로 아무 생성자 하나 만들면
// 자동으로 만들어지던 [기본 생성자]는 더 이상 만들어지지 않음

// class는 일종의 설계도

class Knight
{
public:
    // [1] 기본 생성자 (인자가 없음)
    Knight() 
    {
        cout << "Knight() 기본 생성자 호출" << endl;

        _hp = 100;
        _attack = 10;
        _posX = 0;
        _posY = 0;
    }

    // [2] 복사 생성자 (자기 자신의 클래스 참조 타입을 인자로 받음)
    // (일반적으로 '똑같은' 데이터를 지닌 객체가 생성되길 기대한다.)
    Knight(const Knight& knight) 
    {
        _hp = knight._hp;
        _attack = knight._attack;
        _posX = knight._posX;
        _posY = knight._posY;
    }

    // [3] 기타 생성자 (인자가 있음)

    // 이 중에서 인자를 1개만 받는 [기타 생성자]를
    // [타입 변환 생성자]라고 부르기도 함

    // 명시적인 용도로만 사용할 것!
    explicit Knight(int hp)
    {
        cout << "Knight(int) 기본 생성자 호출" << endl;
        _hp = hp;
        _attack = 10;
        _posX = 0;
        _posY = 0;
    }
    
    Knight(int hp, int attack, int posX, int posY)
    {
        _hp = hp;
        _attack = attack;
        _posX = posX;
        _posY = posY;
    }

    // 소멸자
    ~Knight()
    {
        cout << "Knight() 소멸자 호출" << endl;
    }

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
    Knight k1(100, 10, 0, 0);

    //k1._hp = 100;
    /*k1._attack = 10;
    k1._posY = 0;
    k1._posX = 0;*/

    Knight k2(k1); // 복사 생성자
    Knight k3 = k1; // 복사 생성자

    Knight k4; // 생성자
    k4 = k1; // 복사 

    k1.Move(2, 2);
    k1.Attack();
    k1.Die();

    // 암시적 형변환 -> 컴파일러가 알아서 바꿔치기
    int num = 1;

    float f = (float)num; // 명시적 < 우리가 코드로 num을 float  바구니에 넣으라고 주문하고 있음
    double d = num; // 암시적 << 별말 안했는데 컴파일러가 알아서 처리하고 있음

    Knight k5;
    k5 = (Knight)1;

    return 0;
}
