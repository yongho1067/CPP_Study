#include <iostream>
using namespace std;

// 프로젝트 주제 : 상속성

// 객체지향 (OOP Object Orient Programming)
// - 상속성
// - 은닉성
// - 다형성

// 은닉성 (Data Hiding) = 캡슐화(Encapsulation)
// 몰라도 되는 것은 깔끔하게 숨긴다
// 숨기는 이유?
// - 정말 위험하고 건드리면 안되는 경우
// - 다른 경로로 접근하길 원하는 경우

// 자동차
// - 핸들
// - 페달
// - 엔진
// - 문
// - 각종 전기선

// 일반 구매자 입장에서 사용하는 것?
// - 핸들 / 페달 / 문
// 몰라도 됨 (오히려 건드리면 큰일남)
// - 엔진, 각종 전기선

// public protected private

// public (공개적) : 누구에게나 공개
// protected (보호받는) : 상속 받는 함수까지는 허용
// private (개인적인) : 나만 사용할것 << class car 내부에서만 사용가능

// 상속 접근 지정자 : 다음 세대한테 부모의 유산을 어떻게 물려주지?
// 부모에게 물려받은 함수를 꼭 나의 자식한테 똑같이 물려줘야 하진 않음
// 
// - public : 공개적 상속 -> 부모님의 유산을 설계 그대로 ( public -> public, protected -> protected)
// - protected : 보호받는 상속 -> 내 자손들에게만 물려줌 ( public -> protected )
// - private : 개인적인 상속 -> 나까지만 잘 쓰고 자손들에게 안 물려줌 ( public -> private )

class Car
{
public: // 접근 지정자
    void MoveHandle() { }
    void PushPedal() { }
    void OpenDoor() { }

    void TurnKey() 
    {
        // ...
        RunEngine();
    }

private:
    void DisassembleCar() { } // 차를 분해한다
    void ConnectCircuit() { } // 전기선 연결

protected:
    void RunEngine() { } // 엔진을 구동시킨다

public:
    // 핸들
    // 페달
    // 엔진
    // 문
    // 각종 전기선

};

class SuperCar : public Car // 상속 접근 지정자
{
public:

    void pushRemoteController()
    {
        RunEngine();
    }
};

class TestSuperCar : public SuperCar // 상속 접근 지정자를 지정하지 않는 경우 private로 자동
{
public:
    void Test()
    {
        RunEngine();
    }
};

// "캡슐화"
// 연관된 데이터와 함수를 논리적으로 묶어 놓은 것

class Berserker
{
public:

    int GetHp() { return _hp; }
    
    // 사양 : 체력이 50 이하로 떨어지면 버서커 모드 발동 (강해짐)
    void SetHp(int hp)
    {
        _hp = hp;
        if (_hp <= 50)
        {
            SetBerserkerMode();
        }
    }

private:

    void SetBerserkerMode()
    {
        cout << "버서커모드! 매우 강해짐!" << endl;
    }

private:
    int _hp = 100;
};

int main()
{
    Car car;
    SuperCar supcar;

    /*car.DisassembleCar();
    car.RunEngine();*/

    Berserker b;

    b.SetHp(20);

    TestSuperCar aCar;
    
\
    
    
    

    return 0;
}
