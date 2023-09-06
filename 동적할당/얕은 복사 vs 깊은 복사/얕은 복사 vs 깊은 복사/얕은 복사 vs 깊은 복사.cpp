#include <iostream>
using namespace std;

// 프로젝트 주제 : 얕은 복사 vs 깊은 복사

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}
	
	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet&)" << endl;
	}
	
	~Pet()
	{
		cout << "~Pet()" << endl;
	}
	
};


class Knight
{

public:
	Knight()
	{
		_pet = new Pet();
	}

	Knight(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet); // 깊은 복사
	}
	Knight& operator=(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*knight._pet); // 깊은 복사

		return *this;
	}

	~Knight()
	{
		delete _pet;
	}
public:

	int _hp = 100;
	Pet* _pet;

};
int main()
{
	Knight k; // 기본 생성자
	k._hp = 200;

	Knight k2 = k; // 복사 생성자
	//Knight k3(k);

	Knight k3; // 기본 생성자
	k3 = k; // 복사 대입 연산자 

	// [복사 생성자] + [복사 대입 연산자]
	// 둘다 안 만들어주면 컴파일러 ' 암시적으로 ' 만들어준다

	// 중간 결론) 컴파일러가 알아서 잘 만들어준다?

	// [ 얕은 복사 Shallow Copy]
	// 멤버 데이터를 비트열 단위로 ' 똑같이 ' 복사 ( 메모리 영역 값을 그대로 복사 )

	// [ 깊은 복사 Deep Copy]
	// 멤버 데이터가 참조(주소) 값이라면, 데이터를 새로 만들어 준다 ( 원복 객체가 참조하는 대상까지 새로 만들어서 복사)
	// 포인터는 주소값 바구니 -> 새로운 객체를 생성 -> 상이한 객체를 가리키는 상태가 됨

	// 실험)
	// - 암시적 복사 생성자 Steps 
	// 1) 부모 클래스의 복사 생성자 호출
	// 2) 멤버 클래스의 복사 생성자 호출
	// 3) 멤버가 기본 타입일 경우 -> 메모리 복사 ( 얕은 복사 Shallow Copy )
	// - 명시적 복사 생성자 Steps
	// 1) 부모 클래스의 기본 생성자 호출
	// 2) 멤버 클래스의 기본 생성자 호출

	// - 암시적 복사 대입 연산자 Steps
	// 1) 부모 클래스의 복사 대입 연산자 호출
	// 2) 멤버 클래스의 복사 대입 연산자 호출
	// 3) 멤버가 기본 타입일 경우 -> 메모리 복사 ( 얕은 복사 Shallow Copy )
	// - 명시적 복사 대입 연산자 Steps
	// 1) 알아서 해주는 거 없음 본인이 직접 해야함


	return 0;
}
