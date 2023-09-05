#include <iostream>
using namespace std;

// 프로젝트 주제 : 객체지향 마무리

// 1) struct vs class

// C++에서는 struct나 class나 종이 한장차이
// struct는 기본 접근 지정자가 public이고, class는 private이다.
// 왜 이렇게 했을까? C++은 C언어에서 파생되어 발전했기 때문에, 호환성을 지키기 위함.
// -> struct는 그냥 구조체(데이터 묶음)을 표현하는 용도
// -> class는 객체 지향 프로그래밍의 특징을 나타내는 용도

struct TestStruct
{ // 아무것도 입력하지 않을 시 자동 public 
    int _a;
    int _b;
};

class TestClass
{ // 아무것도 입력하지 않을 시 자동 private
    int _a;
    int _b;
};

// 2) static 변수, static 함수 ( static = 정적 = 고정된)

class Marine
{

public:
    // 특정 마린 객체에 종속적
    int _hp;

    void TakeDamage(int damage)
    {
        _hp -= damage;
    }

    //static void Test()
    //{
    //    // 일반 멤버 변수는 건들수 없음
    //    _hp = 100;
    //}
    
    static void SetAttack()
    {
        s_attack = 100;
    }

    // 특정 마린 객체와 무관
    // 마린이라는 '클래스'자체와 연관
    static int s_attack; // 설계도상으로만 존재

};

// 외부선언
// static 변수는 어떤 메모리?
// 초기화 하면 .data
// 초기화 안하면 .bss
int Marine::s_attack = 0;

class Player
{
public:
    int _id;
};


int GenerateID()
{
    // 생명주기: 프로그램 시작/종료 (메모리에 항상 올라가 있음)
    // 가시범위: 함수 내부

    // 정적 지역 객체
    static int s_id = 1;


    return s_id++;
}


int main()
{
    TestStruct ts;
    TestClass tc;

    ts._a = 1;

    Marine m1;
    m1._hp = 40;
    m1.TakeDamage(10);

    Marine::s_attack = 6;

    //m1.s_attack = 6;

    Marine m2;
    m2._hp = 40;
    m2.TakeDamage(20);
    //m2.s_attack = 6;

    // 마린 공격력 업그레이드 완료! (아카데미)에서 업그레이드 끝
    Marine::s_attack = 7;
    Marine::SetAttack();

    /*m1.s_attack = 7;
    m2.s_attack = 7;*/

    // 스택 아님
    // .data 영역
    static int id = 10;
    int a = id;

    cout << GenerateID() << endl;
    cout << GenerateID() << endl;
    cout << GenerateID() << endl;
    cout << GenerateID() << endl;
    cout << GenerateID() << endl;


    return 0;
}
