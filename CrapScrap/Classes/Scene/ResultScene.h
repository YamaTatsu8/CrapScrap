// ���d�C���N���[�h�̖h�~
#pragma once

// == �w�b�_�t�@�C���̓ǂݍ��� ========
#include "cocos2d.h"
#include "HelloWorldScene.h"

// == �N���X�̐錾 ====================
class ResultScene : public cocos2d::Scene
{
public:
	// �����o�֐� ///////////
	// create�֐��̐錾�ƒ�`
	CREATE_FUNC(ResultScene);
	// ����������
	bool init();
	// ���t���[���̍X�V����
	void update(float delta) override;
	// �V�[���J�ڏ���
	void TransScene();

	// �^�b�`���̏���
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
};