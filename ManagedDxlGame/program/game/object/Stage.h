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

	//// �}�b�v�`�b�v�Ɏg�p����p�̒萔
	//enum class Mstage_display_size_APCHIP {
	//	AIR,			// 0�F�z�u�Ȃ�
	//	BLOCK,			// 1�F�n��
	//	MAX				// �}�b�v�`�b�v�̑���
	//};

	// �X�e�[�W�̃}�b�v���擾����p
	std::vector<std::vector<MAPCHIP>>& get_stageMap_Data_();

	std::vector<std::vector<MapChipBase*>>& get_stageMap_Obj_();

	std::list<std::vector<std::vector<MapChipBase*>>>& get_stageMap_Chunk_Obj_();


	int& get_mapchipSize_();					// �}�b�v�`�b�v�̈�ӂ̑傫�����擾����֐�
	tnl::Vector3& get_stageDisplaySize_();		// �X�e�[�W��\������͈͂��擾
	tnl::Vector3& get_stageCutNumber_();		// �X�e�[�W�̕��������擾
	int& get_stageHeightBase_();				// ����̊�{�̍������擾

	void scrollStage_(const tnl::Vector3 scrollVolume);	// �}�b�v�`�b�v�̍��W�𓮂����p�̊֐�

	void makeStageChunk_();								// �X�e�[�W�̃`�����N�̐���������֐�

	void deleteStageChunk_();							// �X�e�[�W�̃`�����N�̍폜������֐�

	// �X�p�C�N(��Q��)��z�u����֐�
	void makeSpike_(std::vector<std::vector<MAPCHIP>>& stageMapData);

private :

	std::vector<std::vector<int>> stageData_;	// csv�t�@�C������ǂݍ��ޗp

	int mapchipSize_;							// �}�b�v�`�b�v�̈�ӂ̑傫��
	tnl::Vector3 stageDisplaySize_;				// �X�e�[�W��\������͈�(�J�����͈�)�̑傫��
	tnl::Vector3 stageCutNumber_;				// �X�e�[�W�̕�����
	int stageHeightBase_;						// �X�e�[�W�̑���̊�{�̍���


	// �`�����N���쐬����t���O
	// �`�����N�̓�������̍��W��ʉ߂����ۂɃ`�����N���쐬���t���O��false�ɁA
	// �`�����N�̔��΂̒[���ʉ߂����ۂɃ`�����N�������Atrue�ɂ��邱�ƂŁA
	// �`�����N���������ꑱ����̂�h��
	bool makeChunkFlag_ = true;					

	float chunkCheckPosX_ = 0;

	int haji_x = 0;

	// �X�e�[�W�̃`�����N�̑傫��(��ʂ̃T�C�Y��1�P��)
	tnl::Vector3 chunkSize_ = { DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT, 0 };

	// �X�e�[�W�̃X�N���[�������
	tnl::Vector3 stageScrollSpeed_ = {5.0f, 0, 0};

	// �X�e�[�W�̃}�b�v(���l)
	std::vector<std::vector<MAPCHIP>> stageMap_Data_;

	// �X�e�[�W�̃}�b�v(�N���X)
	std::vector<std::vector<MapChipBase*>> stageMap_Obj_;


	// �X�e�[�W�̃}�b�v(���l)�̃`�����N(��)���i�[����p�̃��X�g
	std::list< std::vector<std::vector<MAPCHIP>>> stageMap_Chunk_Data_;

	// �X�e�[�W�̃}�b�v(�N���X)�̃`�����N(��)���i�[����p�̃��X�g
	std::list<std::vector<std::vector<MapChipBase*>>> stageMap_Chunk_Obj_;

	// ��Q���̊Ԋu�̍Œ�l
	int spikeInterval_min_;

	// ��Q���̊Ԋu�̐U�ꕝ
	int spikeInterval_width_;

	// ��Q���̍����̍Œ�l
	int spikeHeight_min_;

	// ��Q���̍����̍ő�l
	int spikeHeight_max_;


	//std::vector<std::vector<int>> s_map;


	// �摜�n���h��

	// block�̉摜�̏�����
	int block_gpc_ = 0;
	// �j(��Q��)�̉摜�̏�����
	int spike_gpc_ = 0;
};


