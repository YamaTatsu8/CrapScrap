// ���d�C���N���[�h�̖h�~
#pragma once

// == �w�b�_�t�@�C���̓ǂݍ��� ========
#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "Floor\Floor.h"

// == �N���X�̐錾 ====================
class PlayScene : public cocos2d::Scene
{
	// �C���X�^���X
	Floor* m_pFloor;

public:
	// �����o�֐� ///////////
	// create�֐��̐錾�ƒ�`
	CREATE_FUNC(PlayScene);
	// ����������
	bool init();
	// ���t���[���̍X�V����
	void update(float delta) override;
	// �V�[���J�ڏ���
	void TransScene();

	// �^�b�`���̏���
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
};