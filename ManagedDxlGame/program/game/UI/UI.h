#pragma once
#include "../object/Player.h"
#include "../common/ScoreManager.h"


// UI�p�̃N���X
// �쐬���悤�Ƃ������̂̎��Ԃ̓s���Ō��ʕs�g�p

class UI {
public :
	UI();
	~UI() {};

	void update(float delta_time);
	void draw();


private :

	Player* player_;

	int player_hp_;
	int score_;

	int hp_gpc_hdl = 0;

};