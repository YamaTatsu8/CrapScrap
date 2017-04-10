// ���d�C���N���[�h�̖h�~
#pragma once

// == �w�b�_�t�@�C���̓ǂݍ��� ========
#include "cocos2d.h"
#include "HelloWorldScene.h"

//���U���g�̎��
enum ResultType
{
	GameClear,
	GameOver
};

// == �N���X�̐錾 ====================
class ResultScene : public cocos2d::Scene
{
public:
	// �����o�֐� ///////////
	// create�֐��̐錾�ƒ�`
	static ResultScene* create(ResultType type);

	// ������
	bool init(ResultType type);

	// ���t���[���X�V

	// ���t���[���̍X�V����
	void update(float delta) override;
	// �V�[���J�ڏ���
	void TransScene();

	// �^�b�`���̏���
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
};