#include <iostream>
using namespace std;

#include "Game.h"

// <> 기본적으로 컴파일러에 딸려 오는 것
// 우리가 커스텀을 추가한 헤더파일은 ""

// 프로젝트 주제 : TextRPG


int main()
{
    srand((unsigned int)time(nullptr));
    Game game;
    game.Init();

    while (true)
    {
        game.Update();
    }

    return 0;
}
