#pragma once

// ���漱��
class Player;
class Field;

// is -A  => NO
// has -A => OK

class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();

private:
	// [4 ~ 8 ] ����ũ��
	Player* _player;
	Field* _field;

};

