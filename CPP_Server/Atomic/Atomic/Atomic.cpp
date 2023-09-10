#include "CorePch.h"
#include <thread>
#include <iostream>
#include <atomic>

// atomic atom(원자) : All - Or Nothing

// DB
// A라는 유저 인벤에서 집행검 빼고
// B라는 유저 인벤에 집행검을 추가

// 공유 데이터의 경우 쓰레드에서는 정보처리의 우선순위에 문제가 생겨 일정한 값이 안생길수도 있음
// 그런 경우 atomic을 사용하여 해결 가능
atomic<int32> sum = 0;

void Add()
{
	// int sum = 0; // Stack 메모리
	for (int32 i = 0; i < 1'000'000; i++)
	{
		sum.fetch_add(1);

	}
}

void Sub()
{
	for (int32 i = 0; i < 1'000'000; i++)
	{
		sum.fetch_add(-1);
	}
}

int main()
{
	Add();
	Sub();
	cout << sum << endl;

	thread t1(Add);
	thread t2(Sub);

	t1.join();
	t2.join();

	cout << sum << endl;

}
