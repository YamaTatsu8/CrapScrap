#pragma once

// �w�b�_�t�@�C���̓ǂݍ���
#include "cocos2d.h"

// �^�C�g���V�[��
class TitleScene : public cocos2d::Scene
{
public:
	// create�֐��̐錾�ƒ�`
	CREATE_FUNC(TitleScene);

	// ������
	bool init();

	// ���t���[���X�V
	void update(float delta) override;

	// �^�b�`�J�n���R�[���o�b�N
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
};