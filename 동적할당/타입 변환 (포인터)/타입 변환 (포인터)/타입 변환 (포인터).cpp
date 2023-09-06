#include <iostream>
using namespace std;

// 프로젝트 주제 : 타입 변환 (포인터)

class Knight
{


public:
    int _hp = 0;
};

class Item
{
public:
    Item() 
    {
        cout << "Item()" << endl;
    }

    Item(int itemType) : _itemType(itemType)
    {

    }

    Item(const Item& item)
    {
        cout << "Item(const item&)" << endl;
    }

    virtual ~Item()
    {
        cout << "~Item()" << endl;
    }


public:
    int _itemType = 0;
    int _itemDbId = 0;

    char _dummy[4096] = {}; // 이런 저런 정보들로 인해 비대해진 아이템 클래스
};

enum ItemType
{
    IT_WEAPON = 1,
    IT_ARMOR = 2,
};

class Weapon : public Item
{
public:

    Weapon() : Item(IT_WEAPON)
    {
        cout << "Weapon()" << endl;
        _damage = rand() % 100;

    }
    virtual ~Weapon()
    {
        cout << "~Weapon()" << endl;

    }


public:
    int _damage = 0;
};

class Armor : public Item
{
public:
    Armor() : Item(IT_ARMOR)
    {
        _itemType = 2;
        cout << "Armor()" << endl;

    }
    virtual ~Armor()
    {
        cout << "~Armor()" << endl;
    }
public:
    int _def = 0;
};

void TestItem(Item item)
{


}

void TestItemPtr(Item* item)
{

}

int main()
{
    // 복습
    {
        // Stack 메모리에 올라감
        // [ type(4) dbid(4) dummy(4096) ]
        Item item;

        // Stack [ item*(4 ~ 8) ] -> Heap 영역에 저장되어 있음 [ type(4) dbid(4) dummy(4096) ]
        Item* item2 = new Item();

        TestItem(item);
        TestItem(*item2);

        TestItemPtr(&item);
        TestItemPtr(item2);

        // 메모리 누수(Memory Leak) -> 점점 가용 메모리가 줄어들어서 Crash
        delete item2;
    }

    // 배열
    {

        cout << "==================================" << endl;
    
        Item item3[100] = {};

        cout << "==================================" << endl;

        // 아이템이 100개 있을까요?
        // 아이템을 가르키는 바구니가 100개, 실제 아이템은 1개도 없을수도 있음
        Item* item4[100] = {};
    }

    // 연관성이 없는 클래스 사이의 포인터 변환 테스트
    {
        // Stack [ 주소 ] => Heap [ _hp(4) ]
        Knight* knight = new Knight();

        // 암시적으로는 No
        // 명시적으로는 Ok
        /*Item* item = (Item*)knight;
        item->_itemType = 2;
        item->_itemDbId = 1;*/

        delete knight;
    }

    // 부모 -> 자식 변환 테스트
    {
        Item* item = new Item();

        //Weapon* weapon = (Weapon*)item;

        delete item;
        
    }

    // 자식 -> 부모 변환 테스트
    {
        Weapon* weapon = new Weapon();

        Item* item = weapon;

        delete weapon;


    }

    // 명시적으로 타입 변환할 때는 항상 항상 조심해야 한다!
    // 암시적으로 될 때는 안전하다?
    // -> 평생 명시적으로 타입 변환(캐스팅)은 안하면 되는거 아닌가?

    Item* inventory[20] = {};

    srand((unsigned int)time(nullptr));
    for (int i = 0; i < 20; i++) 
    {
        int randval = rand() % 2;
        switch (randval)
        {
        case 0:
            inventory[i] = new Weapon();
            break;
        case 1:
            inventory[i] = new Armor();
            break;

        default:
            break;
        }
    }

    for (int i = 0; i < 20; i++)
    {
        Item* item = inventory[i];
        if (item == nullptr)
            continue;

        if (item->_itemType == IT_WEAPON)
        {
            Weapon* weapon = (Weapon*)item;
            cout << "Weapon Damage : " << weapon->_damage << endl;

        }
    }


    // ************************************** 매우 매우 매우 중요 ********************************************
    for (int i = 0; i < 20; i++)
    {
        Item* item = inventory[i];
        if (item == nullptr)
            continue;

        delete item;
    }

    // [결론]
    // - 포인터 vs 일반 타입 : 차이를 이해하자
    // - 포인터 사이의 타입 변환(캐스팅)을 할때는 매우매우 조심해야 한다
    // - 부모-자식 관계에서 부모 클래스의 소멸자에는 까먹지 말고 virtual을 붙이자


    return 0;
}
