#pragma once
#include "Creature.h"

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton =3,
};

class Monster : public Creature
{
public:
	Monster(int monsterType) : Creature(CT_Monster), _monsterType(monsterType)
	{

	}
	
	virtual void PrintInfo();

protected:
	int _monsterType;
};

class Slime :public Monster
{
public:
	Slime() : Monster(MT_Slime)
	{
		_hp = 50;
		_attack = 5;
		_def = 2;
	}
};

class Orc :public Monster
{
public:
	Orc() : Monster(MT_Orc)
	{
		_hp = 80;
		_attack = 8;
		_def = 2;
	}
};

class Skeleton :public Monster
{
public:
	Skeleton() : Monster(MT_Skeleton)
	{
		_hp = 50;
		_attack = 10;
		_def = 2;
	}
};
