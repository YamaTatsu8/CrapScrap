///-------------------------------------------------------------------
//*
//*	@���O		Player.cpp
//*
//*	@�쐬��		2017/04/07
//*
//*	@����		���� ���n
//*
///-------------------------------------------------------------------

// �w�b�_�[�t�@�C���̃C���N���[�h
//#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "Player.h"

// cocos2d-x�̖��O���
USING_NS_CC; 
using namespace cocostudio;
using namespace ui;


const int �o�b�e�����q = 300;
const int �o�b�e������ = 1;			/* �O���t�B�b�N�̕���300�Ȃ̂ŁA���q/���ꂪ300�ɂȂ�悤�� */
const int empty = 37;


////////////////////////////
/// �v���C���N���X�̐錾 ///
////////////////////////////

////----------------------------------------------------------------------
////! @�֐����Finit
////!
////! @�����F�v���C���N���X�̏���������
////!
////! @�����F�Ȃ�
////!
////! @�߂�l�F�������ɐ����������ۂ�
////----------------------------------------------------------------------
bool Player::init()
{

	// ���t���[���X�V��L����
	scheduleUpdate();

	// �t���[�����J�E���g�̏�����
	m_cnt = 0;

	// �W�����v�ʂ̌���
	m_jumping = 100.0f;

	// �o�b�e���[�̏�����
	m_consume = �o�b�e�����q;



	////////////////////////
	///	�X�v���C�g�̐ݒ� ///
	////////////////////////

	//==========�v���C���̐ݒu�E�\��==========//

	// �v���C����ݒu
	player = Sprite::create("player.png");
	m_playerPos = Vec2(200.0f, 200.0f);
	player->setPosition(m_playerPos);
	// ���[�V�����J�ڂ̂������킩��Ȃ��ׁA�s�����̑��v���C���摜��p�ӂ��Ă���
	player2 = Sprite::create("player2.png");
	player2->setPosition(m_playerPos);
	player2->setVisible(false);
	playerJump = Sprite::create("PlayerJump.png");
	playerJump->setPosition(m_playerPos);
	playerJump->setVisible(false);
	playerAction = Sprite::create("playerAction.png");
	playerAction->setPosition(m_playerPos);
	playerAction->setVisible(false);
	playerAttack = Sprite::create("playerAttack.png");
	playerAttack->setPosition(m_playerPos);
	playerAttack->setVisible(false);
	playerOff = Sprite::create("playerOff.png");
	playerOff->setPosition(m_playerPos);
	playerOff->setVisible(false);

	// true��player.png��false��player2.png.�ŏ���true
	m_frontback = true;		

	// �v���C�����V�[���ɓ\��t����
	this->addChild(player);
	this->addChild(player2);
	this->addChild(playerJump);
	this->addChild(playerAction);
	this->addChild(playerAttack);
	this->addChild(playerOff);


	//==========�o�b�e���̐ݒu�E�\��==========//

	// �o�b�e���[�Q�[�W
	gauge = Sprite::create("Gauge.png");
	gauge->setPosition(790.0f, 600.0f);
	this->addChild(gauge);

	// �o�b�e���[�e��
	charged = Sprite::create("Charged.png");
	charged->setPosition(640.0f, 600.0f);
	this->addChild(charged);

	// �o�b�e���[�e�ʂ��A���J�[�ŃQ�[�W���[�ɌŒ�
	charged->setAnchorPoint(Vec2(0.0f, 0.5f));


	// �v���C�����m�[�h�Őe�q�t����
	players = Node::create();
	this->addChild(players);
	players->addChild(player);
	players->addChild(player2);
	players->addChild(playerJump);
	players->addChild(playerAction);
	players->addChild(playerAttack);
	players->addChild(playerOff);


	//// �o�b�e�����m�[�h�Őe�q�t����
	//battery = Node::create();
	//this->addChild(battery);
	//battery->addChild(gauge);
	//battery->addChild(charged);


	////////////////////////
	///	�e��{�^���̐ݒ� ///
	////////////////////////

	//==========�{�^���̐ݒu�E�\��==========//

	// �E�{�^��
	ui::Button* rightButton = ui::Button::create("RightButton.png");
	rightButton->setPosition(Vec2(860.0f, 75.0f));
	this->addChild(rightButton);
	// ���{�^��
	ui::Button* leftButton = ui::Button::create("LeftButton.png");
	leftButton->setPosition(Vec2(100.0f, 75.0f));
	this->addChild(leftButton);
	// �A�N�V�����{�^��
	ui::Button* actionButton = ui::Button::create("ActionButton.png");
	actionButton->setPosition(Vec2(610.0f, 75.0f));
	this->addChild(actionButton);
	// �W�����v�{�^��
	ui::Button* jumpButton = ui::Button::create("JumpButton.png");
	jumpButton->setPosition(Vec2(350.0f, 75.0f));
	this->addChild(jumpButton);


	//==========�C�x���g�R�[���o�b�N�̓o�^==========//

	// ���A�E�{�^���̓^�b�`�C�x���g���X�i�[
	rightButton->addTouchEventListener(CC_CALLBACK_2(Player::rightButtonMove, this));
	leftButton->addTouchEventListener(CC_CALLBACK_2(Player::leftButtonMove, this));
	// �W�����v�A�A�N�V�����{�^���̓N���b�N�C�x���g���X�i�[
	jumpButton->addClickEventListener(CC_CALLBACK_1(Player::buttonJump, this));
	actionButton->addTouchEventListener(CC_CALLBACK_1(Player::buttonAction, this));

	return true;
}


////----------------------------------------------------------------------
////! @�֐����Fupdate
////!
////! @�����F�v���C���N���X�̍X�V����
////!
////! @�����F�t���[����(float)
////!
////! @�߂�l�F�Ȃ�(void)
////----------------------------------------------------------------------
void Player::update(float delta)
{
	// ���t���[�������Ă����J�E���g�ϐ�
	m_cnt++;

	// ���t���[���o�b�e��������
	m_consume--;

	m_battery = m_consume / �o�b�e������;

	// �o�b�e���̏������`�����ŕ\��
	charged->setTextureRect(Rect(0, 0, m_battery, 50));

	// �o�b�e�����c���Ă��疈�t���[���v���C���̍��W�����݂̈ʒu�֍X�V
	if (m_battery > empty)
	{
		m_playerPos += Vec2(m_movement, 0.0f);			/* m_movement�̓{�^���������Ă���Ԃ̂ݒl������ */
		players->setPositionX(m_playerPos.x);
	}

	// 30�t���[���Ńv���C���摜�̐؂�ւ�
	if (m_frontback)
	{
		//	// player.png�̏ꏊ��player2.png��ݒu
		//	player->getPosition();
		player->setVisible(true);
		player2->setVisible(false);

	}
	else
	{
		player2->setVisible(true);
		player->setVisible(false);
	}

	//* 30�t���[���o������\�����f�̃u�[���^��؂�ւ���
	if (m_cnt > 30)
	{
		//* ����Ő؂�ւ��鏈����
		if (m_frontback)
		{
			m_frontback = false;
		}
		else
		{
			m_frontback = true;
		}

		// ����ɂ����ŃJ�E���g���O�ɂ���΁A�����̃u�[���̐؂�ւ���A���ōs�����Ƃ�
		m_cnt = 0;
	}
	


	//* �A�N�V�������̈ړ��l������Ă����֐���if���ɗ��p����
	actionNow = players->numberOfRunningActions();

	if (actionNow)
	{
		// �W�����v���[�V������\���E�j���[�g�������[�V�������\��
		player->setVisible(false);
		player2->setVisible(false);
		playerJump->setVisible(true);
	}
	else
	{
		// �W�����v���[�V�������\��
		playerJump->setVisible(false);
	}

	// �o�b�e���[���؂ꂽ��@�\��~�O����
	if (m_battery < empty)
	{
		player->setVisible(false);
		player2->setVisible(false);
		playerJump->setVisible(false);
		playerAction->setVisible(false);
		playerAttack->setVisible(false);
		playerOff->setVisible(true);
	}

}


////----------------------------------------------------------------------
////! @�֐����FrightButtonMove
////!
////! @�����F�E�ړ��̃{�^���������ꂽ��A�v���C�����E�ֈړ�������B
////!
////! @�����F�E�{�^���̃^�b�`����(Ref)
////!
////! @�߂�l�F�v���C���̈ړ���(int)
////----------------------------------------------------------------------
void Player::rightButtonMove(Ref* ref, cocos2d::ui::Widget::TouchEventType eventtype)
{
	switch (eventtype)
	{
		// ��������
	case ui::Widget::TouchEventType::BEGAN:
		// ��������ړ��ʂɒl����
		m_movement = 5.0f;
		break;

		// ����������
	case ui::Widget::TouchEventType::MOVED:
		// ���������Ƃ��͉������Ȃ�
		break;

		// ��������
	case ui::Widget::TouchEventType::ENDED:
		// ��������ړ��ʂ��O��
		m_movement = 0.0f;
		break;

		// �L�����Z�����ꂽ���E�{�^����łȂ��Ƃ���ŗ�����邱��
	case ui::Widget::TouchEventType::CANCELED:
		// �{�^���̊O�ł���������ړ��ʂ��O��
		m_movement = 0.0f;
		break;

	default:
		m_movement = 0.0f;
		break;
	}

}



////----------------------------------------------------------------------
////! @�֐����FleftButtonMove
////!
////! @�����F���ړ��̃{�^���������ꂽ��A�v���C�������ֈړ�������B
////!
////! @�����F���{�^���̃^�b�`����(Ref)
////!
////! @�߂�l�F�v���C���̈ړ���(int)
////----------------------------------------------------------------------
void Player::leftButtonMove(Ref * ref, cocos2d::ui::Widget::TouchEventType eventtype)
{
	switch (eventtype)
	{
		// ��������
	case ui::Widget::TouchEventType::BEGAN:
		// ��������ړ��ʂɒl����
		m_movement = -5.0f;
		break;

		// ����������
	case ui::Widget::TouchEventType::MOVED:
		// ���������Ƃ��͉������Ȃ�
		break;

		// ��������
	case ui::Widget::TouchEventType::ENDED:
		// ��������ړ��ʂ��O��
		m_movement = 0.0f;
		break;

		// �L�����Z�����ꂽ���E�{�^����łȂ��Ƃ���ŗ�����邱��
	case ui::Widget::TouchEventType::CANCELED:

		// �{�^���̊O�ł���������ړ��ʂ��O��
		m_movement = 0.0f;
		break;

	default:
		m_movement = 0.0f;
		break;
	}

}


////----------------------------------------------------------------------
////! @�֐����FbuttonJump
////!
////! @�����F�W�����v�{�^���������ꂽ��A�v���C�����W�����v������B
////!
////! @�����F�W�����v�̃{�^���^�b�`����(Ref)
////!
////! @�߂�l�F�v���C���̃W�����v��(int)
////----------------------------------------------------------------------
bool Player::buttonJump(Ref * ref)
{
	if (m_battery >= empty)
	{
		if (!actionNow)
		{
			JumpBy* jumping = JumpBy::create(0.5f, Vec2(0.0f, 0.0f), m_jumping, 1);
			// �W�����v���[�V�������\��
			players->runAction(jumping);
		}
	}


	return false;
}


////----------------------------------------------------------------------
////! @�֐����FonActionButtonTouch
////!
////! @�����F���̎��ɉ������A�N�V�������s���B
////!
////! @�����F�A�N�V�����̃{�^���^�b�`����(Ref)
////!
////! @�߂�l�F
////----------------------------------------------------------------------
bool Player::buttonAction(Ref * ref)
{
	if (m_consume >= empty)
	{

	}
	return false;
}
