#include "Player.h"
#include <iostream>
using namespace std;

void Player::PrintInfo()
{
	cout << "===============================" << endl;
	cout << " [�÷��̾� ����] " << "HP: " << _hp << " ATT: " << _attack << " DEF: " << _def << endl;
	cout << "===============================" << endl;
}
