#pragma once

// 전방선언
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
	// [4 ~ 8 ] 고정크기
	Player* _player;
	Field* _field;

};

