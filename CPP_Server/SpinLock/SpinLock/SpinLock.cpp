#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>

// 프로젝트 주제 : SpinLock

class SpinLock
{
public:
    void lock()
    {
        // CAS (Compare-And-Swap)
        bool expected = false;
        bool desired = true;

        while (_locked.compare_exchange_strong(expected, desired) == false)
        {
            expected = false;

            //this_thread::sleep_for(std::chrono::milliseconds(100));
            this_thread::sleep_for(100ms);
            this_thread::yield();
        }


    }

    void unlock()
    {
        //_locked = false;
        _locked.store(false);
    }

private:
    atomic<bool> _locked = false; 
};

int32 sum = 0;
mutex m;
SpinLock spinLock;

void Add()
{
    for (int32 i = 0; i < 1'000'000; i++)
    {
        lock_guard<SpinLock> guard(spinLock);
        sum++;
    }
}

void Sub()
{
    for (int32 i = 0; i < 1'000'000; i++)
    {
        lock_guard<SpinLock> guard(spinLock);
        sum--;
    }
}


int main()
{
    // 면접에 자주 나옴
    // 스핀락에 대해서는 꼭 숙지 하고 가야함


    thread t1(Add);
    thread t2(Sub);

    t1.join();
    t2.join();

    cout << sum << endl;

}
