#include <iostream>
using namespace std;

// 프로젝트 주제 : 함수 포인터

// typedef의 진실
// typedef 왼쪽 오른값 -> 오른쪽 (커스텀 타입 정의)

// 정확히는 왼쪽/오른쪽 기준이 아니라.
// [선언 문법]에서 typedef을 앞에다 붙이는 쪽

int INTEGER;

int Test(int a, int b)
{
    cout << "Test" << endl;
    return a + b;
}

int main()
{
    // 함수 포인터
    // 1) 포인터       *
    // 2) 변수의 이름  fn
    // 3) 타입        함수(인자로 int 2개를 받고, int 1개를 반환)
    
    int (*fn)(int, int);

    fn = Test; // & 생략 가능 (C언어 호환성 때문)

    fn(1,1);

    (*fn)(1,1);

    // 위 문법으로 [전역 함수/ 정적 함수]만 담을 수 있다 (호출 규약)
    return 0;
}