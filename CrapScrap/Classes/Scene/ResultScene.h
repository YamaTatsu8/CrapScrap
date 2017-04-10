#pragma once

// �w�b�_�t�@�C���̓ǂݍ���
#include "cocos2d.h"

//���U���g�̎��
enum ResultType
{
	GameClear,
	GameOver
};

// ���U���g�V�[��
class ResultScene : public cocos2d::Scene
{
public:
	// create�֐��̐錾�ƒ�`
	//CREATE_FUNC(ResultScene);
	static ResultScene* create(ResultType type);

	// ������
	bool init(ResultType type);

	// ���t���[���X�V
	void update(float delta) override;

	// �^�b�`�J�n���R�[���o�b�N
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
};