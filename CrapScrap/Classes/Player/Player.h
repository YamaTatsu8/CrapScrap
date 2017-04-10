///-------------------------------------------------------------------
//*
//*	@���O		Player.h
//*
//*	@�쐬��		2017/04/07
//*
//*	@����		���� ���n
//*
///-------------------------------------------------------------------


// ���d�C���N���[�h�̋֎~
#pragma once

// �w�b�_�[�t�@�C���̃C���N���[�h
#include "cocos2d.h"
#include "ui/CocosGUI.h"



//////////////////////////////
///�@�v���C���N���X�̒�`�@///
//////////////////////////////
class Player : public cocos2d::Layer
{
private:
	// �ړ���
	float m_movement;

	// �W�����v�̍���
	float m_jumping;

	// �o�b�e��
	float m_consume;

	// �o�b�e���c��
	float m_battery;

	// �A�N�V���������ۂ��i�A�N�V�������Ȃ�l������j
	int actionNow;

	// �t���[�����̃J�E���g�ϐ�
	int m_cnt;

	// �v���C���̉摜���ꖇ�ڂ��񖇖ڂ�
	bool m_frontback;

	// �v���C���̌��݈ʒu
	cocos2d::Vec2 m_playerPos;


public:
	// create�֐��̐錾�ƒ�`
	static Player* create();

	// ������
	bool init();

	// �X�V
	void update(float delta);

	//////////////////////////////
	/// �R�[���o�b�N�֐��̐錾 ///
	//////////////////////////////

	// �E�A���{�^���p�^�b�`�C�x���g���X�i�[
	void rightButtonMove(Ref * ref, cocos2d::ui::Widget::TouchEventType eventtype);
	void leftButtonMove(Ref * ref, cocos2d::ui::Widget::TouchEventType eventtype);
	//// �A�N�V�����A�W�����v�{�^���p�N���b�N�C�x���g���X�i�[
	bool buttonJump(Ref *ref);
	bool buttonAction(Ref *ref);



	//////////////////////////////
	/// �X�v���C�g�E�m�[�h�o�^ ///
	//////////////////////////////

	// �v���C��
	cocos2d::Sprite* player;
	// �v���C���i�j���[�g�������[�V�����p�j
	cocos2d::Sprite* player2;
	// �v���C���i�W�����v���[�V�����p�j
	cocos2d::Sprite* playerJump;
	// �v���C���i�A�N�V�������[�V�����p�j
	cocos2d::Sprite* playerAction;
	// �v���C���i�U�����[�V�����p�j
	cocos2d::Sprite* playerAttack;
	// �v���C���i�@�\��~���[�V�����p�j
	cocos2d::Sprite* playerOff;

	// �o�b�e���[�Q�[�W
	cocos2d::Sprite* gauge;
	// �o�b�e���[�e��
	cocos2d::Sprite* charged;

	// �v���C���S��
	cocos2d::Node* players;
	//// �o�b�e���S��
	//cocos2d::Node* battery;

};

