#pragma once

// �w�b�_�t�@�C���̓ǂݍ���
#include "cocos2d.h"

// �v���C�V�[��
class PlayScene : public cocos2d::Scene
{
public:
	// create�֐��̐錾�ƒ�`
	CREATE_FUNC(PlayScene);

	// ������
	bool init();

	// ���t���[���X�V
	void update(float delta) override;

	// �^�b�`�J�n���R�[���o�b�N
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
};