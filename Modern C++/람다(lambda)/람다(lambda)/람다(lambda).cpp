#include <list>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

// 프로젝트의 주제 : 람다(lambda)
// 10분걸려서 작성할 코드를 1분컷해줌
// 함수 객체를 빠르게 만드는 문법

enum class ItemType
{
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable
};

enum class Rarity
{
	Common,
	Rare,
	Unique
};

class Item
{
public:
	Item() { }

	Item(int itemId, Rarity rarity, ItemType type) : _itemId(itemId), _rarity(rarity), _type(type)
	{

	}


public:
	int _itemId = 0;
	Rarity _rarity = Rarity::Common;
	ItemType _type = ItemType::None;
};

int main()
{
	vector<Item> v;

	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
	v.push_back(Item(2, Rarity::Common, ItemType::Armor));
	v.push_back(Item(3, Rarity::Rare,	ItemType::Jewelry));
	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));

	// 람다 = 함수 객체를 손쉽게 만드는 문법
	// 람다 자체로 C++11에 "새로운"기능이 들어간 것은 아니다!

	{
		struct  IsUniqueItem
		{
			bool operator()(Item& item) { return item._rarity == Rarity::Unique; }
		};

		auto isUniqueLambda = [](Item& item) { return item._rarity == Rarity::Unique; }; // 람다 표현식 (lambda expression)

		auto findIt = find_if(v.begin(), v.end(), [](Item& item) { return item._rarity == Rarity::Unique;}); // 바로 넣어도 되고 auto로 변수에 넣어서 사용해도 되고
		if (findIt != v.end())
		{
			cout << "아이템 ID : " << findIt->_itemId << endl;
		}

	}

	{
		struct FindItemByItemId
		{
			FindItemByItemId(int& itemId) : _itemId(itemId)
			{

			}

			bool operator()(Item& item)
			{ 
				return item._itemId == _itemId;
			}

			int& _itemId;
		};

		int itemid = 3;

		// 클로저 (closure) = 람다에 의해 만들어진 실행시점 객체
		// [ ] 캡차(capture) : 함수 객체 내부에 변수를 저장하는 개념
		// 사진을 [캡처]하는.. 일종의 스냅샷을 찍는다고 이해
		// 기본 캡처 모드 : 값(복사) 방식 (=) 참조 방식 (&)
		auto findByItemIdLambda = [&](Item& item) { return item._itemId == itemid; };// 람다 표현식 (lambda expression)

		// [&] = 참조 형태로 전달되어 이후에 itemid의 값이 변경되면 그에 따라 findByItemIdLambda의 값이 true 혹은 false로 변경됌
		// [=] = 복사 형태로 전달되어 이후에 itemid의 값이 변경되어도 처음에 복사 받은 형태를 유지하여 findByItemIdLambda의 값이 변경되지 않음

		itemid = 10;

		auto findIt = find_if(v.begin(), v.end(), findByItemIdLambda); // 바로 넣어도 되고 auto로 변수에 넣어서 사용해도 되고
		if (findIt != v.end())
		{
			cout << "아이템 ID : " << findIt->_itemId << endl;
		}

	}

	{
		struct FindItem
		{
			FindItem(int itemId, Rarity rarity, ItemType type) : _itemId(itemId), _rarity(rarity), _type(type)
			{

			}

			bool operator()(Item& item)
			{
				return item._itemId == _itemId && item._rarity == _rarity && item._type == _type;
			}

			int _itemId;
			Rarity _rarity;
			ItemType _type;
		};

		int itemId = 4;
		Rarity rarity = Rarity::Unique;
		ItemType type = ItemType::Weapon;

		// [] <- 변수마다 캡처 모드를 지정해서 사용가능 값 방식(변수이름), 참조 방식(&변수이름)
		//auto findByItemLambda = [itemId,rarity,&type](Item& item) { return item._itemId == itemId && item._rarity == rarity && item._type == type; };// 람다 표현식 (lambda expression)
		auto findByItemLambda = [=, &rarity](Item& item) { return item._itemId == itemId && item._rarity == rarity && item._type == type; };// 람다 표현식 (lambda expression)

		// [&] = 참조 형태로 전달되어 이후에 itemId의 값이 변경되면 그에 따라 findByItemIdLambda의 값이 true 혹은 false로 변경됌
		// [=] = 복사 형태로 전달되어 이후에 itemId의 값이 변경되어도 처음에 복사 받은 형태를 유지하여 findByItemIdLambda의 값이 변경되지 않음

		itemId = 10;
		type = ItemType::Armor;

		auto findIt = find_if(v.begin(), v.end(), findByItemLambda); // 바로 넣어도 되고 auto로 변수에 넣어서 사용해도 되고
		if (findIt != v.end())
		{
			cout << "아이템 ID : " << findIt->_itemId << endl;
		}

		// [캡처](인자값){구현부}

	}

	{
		class Knight
		{
		public:
			auto Reset()
			{
				auto f = [=]() 
				{
					_hp = 200;
				};

				return f;
			}

		public:
			int _hp = 100;
		};

		Knight* k = new Knight();
		auto job = k->Reset();
		delete k;
		job();
	}

	return 0;
}
