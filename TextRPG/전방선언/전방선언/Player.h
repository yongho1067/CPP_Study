#pragma once
//#include "Monster.h"

class Monster;

// class�� ���赵
class Player
{
public:
	void KillMonster();

	void KillMonster2()
	{
		_target2->_hp = 0;
	}

public:
	int _playerId;
	int _hp;
	int _attack;

	//Monster _target1;
	Monster* _target2;
};

