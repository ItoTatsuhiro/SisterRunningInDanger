#pragma once
#include "../../dxlib_ext/dxlib_ext.h"

class BackGround {
public :
	BackGround(int gpc_hdl);
	~BackGround();

	void update(float delta_time);
	void draw();

private :

	//// 表示する座標
	//tnl::Vector3 pos_{DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, 0};

	// 背景画像ハンドル
	int gpc_hdl_ = 0;

	// 背景画像を入れるlist
	// 3枚の画像を使用することで背景画像をループさせる
	std::shared_ptr<std::list<int>> gpcList_ = nullptr;

	// もっとも左側の画像の座標
	tnl::Vector3 leftGpcPos_ = { DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, 0 };

	// 背景画像の大きさの倍率
	float gpcScale_ = 2.0;

	// 画像の幅
	// 急ぎ作成したため直接値を入れている
	// 時間を見つけて修正する
	float gpcWide_ = 640 * gpcScale_;

	// 背景画像のスクロールスピード
	float scrollSpeed_ = 1.0;


};