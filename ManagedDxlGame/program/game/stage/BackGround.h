#pragma once
#include "../../dxlib_ext/dxlib_ext.h"

class BackGround {
public :
	BackGround(int gpc_hdl);
	~BackGround();

	void update(float delta_time);
	void draw();

private :

	//// �\��������W
	//tnl::Vector3 pos_{DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, 0};

	// �w�i�摜�n���h��
	int gpc_hdl_ = 0;

	// �w�i�摜������list
	// 3���̉摜���g�p���邱�ƂŔw�i�摜�����[�v������
	std::shared_ptr<std::list<int>> gpcList_ = nullptr;

	// �����Ƃ������̉摜�̍��W
	tnl::Vector3 leftGpcPos_ = { DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, 0 };

	// �w�i�摜�̑傫���̔{��
	float gpcScale_ = 2.0;

	// �摜�̕�
	// �}���쐬�������ߒ��ڒl�����Ă���
	// ���Ԃ������ďC������
	float gpcWide_ = 640 * gpcScale_;

	// �w�i�摜�̃X�N���[���X�s�[�h
	float scrollSpeed_ = 1.0;


};