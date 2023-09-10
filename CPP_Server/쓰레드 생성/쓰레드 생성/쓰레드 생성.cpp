#include <iostream>
using namespace std;
#include "CorePch.h"

#include <thread>

void HelloThread()
{
	cout << "Hello Thread" << endl;
}

void HelloThread_2(int32 num)
{
	cout << num << endl;
}

int main()
{
	// System Call (OS 커널 요청)
	cout << "Hello World" << endl;

	vector<thread> v;

	for (int32 i = 0; i < 10; i++)
	{
		v.push_back(thread(HelloThread_2, i));
	}
	
	for (int32 i = 0; i < 10; i++)
	{
		if (v[i].joinable())
			v[i].join();
	}

	thread t;
	//t = thread(HelloThread_2, 10);
	auto id1 = t.get_id(); // 쓰레드마다 부여되는 id

	int32 count = t.hardware_concurrency(); // cpu 코어 갯수?
	auto id2 = t.get_id(); // 쓰레드마다 부여되는 id

	cout << "Hello Main" << endl;


	//t.detach(); // 쓰레드 객체에서 실제 쓰레드를 분리, thread t 는 더이상 사용 불가능해짐

	if(t.joinable()) // 쓰레드가 있는지 없는지
		t.join(); // 스레드가 종료되기 전까지 main을 종료하지 말아주세요
	
} 
