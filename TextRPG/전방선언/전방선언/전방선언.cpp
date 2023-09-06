#include <iostream>
using namespace std;
#include "Player.h"

// 프로젝트 주제 : 전방선언

int main()
{
    // Player는 몇 바이트?
    // int 3개 = 3 * 4 = 12바이트

    Player p1; // 지역변수 (Stack)
    Player* p2 = new Player(); // 동적할당 (Heap)

    return 0;
}
