#pragma once
#include <list>
#include "../../dxlib_ext/dxlib_ext.h"
#include "../base/MapChipBase.h"
#include "../common/GraphicManager.h"
#include "../common/GameManager.h"
#include "../mapchip/Block.h"
#include "../mapchip/Spike.h"

class Stage {
public :

	Stage();
	~Stage() {};

	void update(float delta_time);
	void draw();

	//// マップチップに使用する用の定数
	//enum class Mstage_display_size_APCHIP {
	//	AIR,			// 0：配置なし
	//	BLOCK,			// 1：地面
	//	MAX				// マップチップの総数
	//};

	// ステージのマップを取得する用
	std::vector<std::vector<MAPCHIP>>& get_stageMap_Data_();

	std::vector<std::vector<MapChipBase*>>& get_stageMap_Obj_();

	std::list<std::vector<std::vector<MapChipBase*>>>& get_stageMap_Chunk_Obj_();


	int& get_mapchipSize_();					// マップチップの一辺の大きさを取得する関数
	tnl::Vector3& get_stageDisplaySize_();		// ステージを表示する範囲を取得
	tnl::Vector3& get_stageCutNumber_();		// ステージの分割数を取得
	int& get_stageHeightBase_();				// 足場の基本の高さを取得

	void scrollStage_(const tnl::Vector3 scrollVolume);	// マップチップの座標を動かす用の関数

	void makeStageChunk_();								// ステージのチャンクの生成をする関数

	void deleteStageChunk_();							// ステージのチャンクの削除をする関数

	// スパイク(障害物)を配置する関数
	void makeSpike_(std::vector<std::vector<MAPCHIP>>& stageMapData);

private :

	std::vector<std::vector<int>> stageData_;	// csvファイルから読み込む用

	int mapchipSize_;							// マップチップの一辺の大きさ
	tnl::Vector3 stageDisplaySize_;				// ステージを表示する範囲(カメラ範囲)の大きさ
	tnl::Vector3 stageCutNumber_;				// ステージの分割数
	int stageHeightBase_;						// ステージの足場の基本の高さ


	// チャンクを作成するフラグ
	// チャンクの頭が特定の座標を通過した際にチャンクを作成しフラグをfalseに、
	// チャンクの反対の端が通過した際にチャンクを消し、trueにすることで、
	// チャンクが生成され続けるのを防ぐ
	bool makeChunkFlag_ = true;					

	float chunkCheckPosX_ = 0;

	int haji_x = 0;

	// ステージのチャンクの大きさ(画面のサイズが1単位)
	tnl::Vector3 chunkSize_ = { DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT, 0 };

	// ステージのスクロールする量
	tnl::Vector3 stageScrollSpeed_ = {5.0f, 0, 0};

	// ステージのマップ(数値)
	std::vector<std::vector<MAPCHIP>> stageMap_Data_;

	// ステージのマップ(クラス)
	std::vector<std::vector<MapChipBase*>> stageMap_Obj_;


	// ステージのマップ(数値)のチャンク(塊)を格納する用のリスト
	std::list< std::vector<std::vector<MAPCHIP>>> stageMap_Chunk_Data_;

	// ステージのマップ(クラス)のチャンク(塊)を格納する用のリスト
	std::list<std::vector<std::vector<MapChipBase*>>> stageMap_Chunk_Obj_;

	// 障害物の間隔の最低値
	int spikeInterval_min_;

	// 障害物の間隔の振れ幅
	int spikeInterval_width_;

	// 障害物の高さの最低値
	int spikeHeight_min_;

	// 障害物の高さの最大値
	int spikeHeight_max_;


	//std::vector<std::vector<int>> s_map;


	// 画像ハンドル

	// blockの画像の初期化
	int block_gpc_ = 0;
	// 針(障害物)の画像の初期化
	int spike_gpc_ = 0;
};


