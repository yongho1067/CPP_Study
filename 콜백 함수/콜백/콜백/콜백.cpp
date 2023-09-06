#include <iostream>
using namespace std;

// 프로젝트 주제 : 콜백 (CallBack)

class Item
{
public:

public:
    int _itemId = 0;
    int _rarity = 0;
    int _ownerId = 0;

};

class FindByOwnerId
{
public:
    bool operator()(const Item* item)
    {
        return (item->_ownerId == _ownerId);
    }

public:
    int _ownerId;
};

class FindByRarity
{
public:
    bool operator()(const Item* item)
    {
        return (item->_rarity == _rarity);
    }

public:
    int _rarity;
};

Item* FindItem(Item items[], int itemCount, bool(*func)(const Item*)) 
{
    for (int i = 0; i < itemCount; i++)
    {
        Item* item = &items[i];
        return item;
    }

    return nullptr;
}

int main()
{
    // 함수 포인터 + 함수 객체 + 템플릿
    // 콜백 (CallBack) : 다시 호출하다? 역으로 호출하다?

    // 게임을 만들 때 이런 콜백의 개념이 자주 등장한다.
    // ex)MoveTask 실습 등

    // 어떤 상황이 일어나면 -> 이 기능을 호출해줘
    // ex) UI 스킬 버턴을 누르면 -> 스킬을 쓰는 함수를 호출

    Item items[10];


    return 0;
}
