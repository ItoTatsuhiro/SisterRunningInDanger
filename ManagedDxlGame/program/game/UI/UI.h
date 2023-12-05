#pragma once
#include "../object/Player.h"
#include "../common/ScoreManager.h"


// UI用のクラス
// 作成しようとしたものの時間の都合で結果不使用

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