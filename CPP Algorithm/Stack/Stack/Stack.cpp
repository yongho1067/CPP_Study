#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;

// 프로젝트주제 : Stack (LIFO Last-In-First-Out) 후입선출

// <- [1][2][3][4] << 밀어넣음 
// 4 3 2 1 순으로 나옴
// 되돌리기 기능(Crtl+Z)

template<typename T, typename Container = vector<T>>
class Stack
{
public:
    void push(const T& value)
    {
        _container.push_back(value);
    }

    void pop()
    {
        _container.pop_back();
    }

    T& top()
    {
        return _container.back();
    }

    bool empty() { return _container.empty(); }
    int size() { return _container.size(); }


private:
    //vector<T> _container;
    //list<T> _container;
    Container _container;
    
};

int main()
{
    Stack<int, list<int>> s;

    // 삽입
    s.push(1);
    s.push(2); 
    s.push(3);
    s.push(4);

    // 비었나?
    while (s.empty() == false)
    {
        // 최상위 원소 체크 -> 데이터를 꺼내쓴건 아님
        int data = s.top();

        // 최상위 원소 삭제
        s.pop();
        
        cout << data << endl;
    }

    int size = s.size();
   
}
