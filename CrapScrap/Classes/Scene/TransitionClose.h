#pragma once

// �w�b�_�t�@�C���̓ǂݍ���
#include "cocos2d.h"

// �Ǝ��̃g�����W�V�����N���X
class TransitionClose : public cocos2d::TransitionScene
{
public:
	// �Ǝ��g�����W�V�����̐����@�@�@�@�b���@�@�@�@�@���V�[��
	static TransitionClose* create(float t, cocos2d::Scene* scene);

	virtual void onEnter() override;
};