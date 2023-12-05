#include "AnimManager.h"

AnimManager::AnimManager() {
	anim_data_ = tnl::LoadCsv("csv/game/[000]common/AnimationData.csv");
}


// AnimManagerをインスタンス化
AnimManager* AnimManager::GetInstance_() {
	static AnimManager* instance_ = nullptr;

	if (!instance_) {
		instance_ = new AnimManager();
	}
	return instance_;
}

std::vector<int> AnimManager::loadDivGraph(ANIM_CSV_OBJ ANIM_OBJ) {


	// file_pathに対応する画像アニメーションハンドルを探す
	auto it = animation_map_.find(ANIM_OBJ);
	

	if (it != animation_map_.end()) {
		return animation_map_[ANIM_OBJ];
	}

	// 画像アニメーションの読み込み
	std::vector<int> anim_hdls(anim_data_[static_cast<int>(ANIM_OBJ)][static_cast<int>(ANIM_CSV_ARG::TOTAL_FLAME)].getInt());
	LoadDivGraph(
		anim_data_[static_cast<int>(ANIM_OBJ)][static_cast<int>(ANIM_CSV_ARG::PATH)].getString().c_str(),
		anim_data_[static_cast<int>(ANIM_OBJ)][static_cast<int>(ANIM_CSV_ARG::TOTAL_FLAME)].getInt(),
		anim_data_[static_cast<int>(ANIM_OBJ)][static_cast<int>(ANIM_CSV_ARG::HOLIZONTAL_FLAMES)].getInt(),
		anim_data_[static_cast<int>(ANIM_OBJ)][static_cast<int>(ANIM_CSV_ARG::VERTICAL_FLAMES)].getInt(),
		anim_data_[static_cast<int>(ANIM_OBJ)][static_cast<int>(ANIM_CSV_ARG::WIDTH)].getInt(),
		anim_data_[static_cast<int>(ANIM_OBJ)][static_cast<int>(ANIM_CSV_ARG::HEIGHT)].getInt(),
		anim_hdls.data());

	// 画像アニメーションをanimation_map_にパスと紐づけて保存
	animation_map_.insert(std::make_pair(ANIM_OBJ, anim_hdls));


	// アニメーションハンドルを返す
	return anim_hdls;
}
