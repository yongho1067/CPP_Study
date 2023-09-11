#include "CorePch.h"
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

// [1][2][3]
vector<int32> v;

// Mutal Exclusive (상호배타적)
mutex m;

// RAII 패턴
template<typename T>
class LockGuard
{
public:
    LockGuard(T& m)
    {
        _mutex = &m;
        _mutex->lock();
    }

    ~LockGuard()
    {
        _mutex->unlock();
    }

private:
    T* _mutex;
};
void Push()
{
    for (int32 i = 0; i < 10000; i++)
    {
        // 자동 자물쇠 잠구기
        LockGuard<std::mutex> lockguard(m);
        //std::lock_guard<std::mutex> lockGuard(m);

       /* std::unique_lock < std::mutex> uniqueLock(m, std::defer_lock);
        uniqueLock.lock();*/

        // 자물쇠 잠그기
        //m.lock();

        v.push_back(i);

        // 자물쇠 풀기
        //m.unlock();

        // lock 과 unlock은 세트
        // 사실상 싱글 쓰레드
    }
}

int main()
{
    thread t1(Push);
    thread t2(Push);

    t1.join();
    t2.join();

    cout << v.size() << endl;
}
