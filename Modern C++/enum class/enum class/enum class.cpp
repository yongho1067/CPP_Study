#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

// 프로젝트 주제 : enum class

// unscoped enum (범위없음)
enum PlayerType : char
{
    PT_Knight,
    PT_Archer,
    PT_Mage
};

enum MonsterType
{
    MT_None,
    MT_Knight
};

enum class ObjectType
{
    Player,
    Monster,
    Projectile
};

int main()
{
    // enum class (scoped enum)
    // 1) 이름공간 관리 (scoped)
    // 2) 암묵적인 변환 금지
    // double value = ObjectType::Player;

    PlayerType t;
    cout << sizeof(t) << endl;
    


    return 0;
}
