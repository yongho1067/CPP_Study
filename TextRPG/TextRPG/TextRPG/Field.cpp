#include <stdlib.h>
#include "Field.h"
#include "Monster.h"
#include "Player.h"



Field::Field() : _monster(nullptr)
{

}

Field::~Field()
{
	if (_monster != nullptr)
	{
		delete _monster;
	}
}

void Field::Update(Player* player)
{
	if (_monster == nullptr)
	{
		CreateMonster();
	}

	StartBattle(player);

}

void Field::CreateMonster()
{
	int randVal = 1 + rand() % 3;

	switch (randVal)
	{
	case MT_Slime:
		_monster = new Slime();
		break;
	case MT_Orc:
		_monster = new Orc();
		break;
	case MT_Skeleton:
		_monster = new Skeleton();
		break;
	default:
		break;
	}
}

void Field::StartBattle(Player* player)
{
	while (true)
	{
		player->PrintInfo();
		_monster->PrintInfo();

		// �÷��̾� -> ���� ����
		_monster->OnAttacked(player);

		if (_monster->isDead())
		{
			_monster->PrintInfo();
			delete _monster;
			_monster = nullptr;
			break;
		}

		// ���� -> �÷��̾� ����

		player->OnAttacked(_monster);

		if (player->isDead())
		{
			player->PrintInfo();
			break;
		}
	}
}