#include "BackGround.h"


BackGround::BackGround(int gpc_hdl) {
	gpc_hdl_ = gpc_hdl;
}

BackGround::~BackGround() {

}


void BackGround::update(float delta_time) {

	leftGpcPos_.x -= scrollSpeed_;

	if (leftGpcPos_.x + gpcWide_ / 2 < 0) {
		leftGpcPos_.x += gpcWide_;
	}
}

void BackGround::draw() {
	DrawRotaGraph(leftGpcPos_.x, leftGpcPos_.y, 2.0f, 0, gpc_hdl_, true);
	DrawRotaGraph(leftGpcPos_.x + gpcWide_, leftGpcPos_.y, 2.0f, 0, gpc_hdl_, true);
	DrawRotaGraph(leftGpcPos_.x + gpcWide_ * 2, leftGpcPos_.y, 2.0f, 0, gpc_hdl_, true);
}
