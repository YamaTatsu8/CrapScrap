// == �w�b�_�t�@�C���̓ǂݍ��� ========
#include "PlayScene.h"
#include "ResultScene.h"

// == ���O��Ԃ̎w�� ==================
USING_NS_CC;

// ==
cocos2d::Camera* PlayScene::m_pCamera;

//-----------------------------------------------
//! @brief ����������
//!
//! @param[in] �Ȃ�
//!
//! @return �I�����
//-----------------------------------------------
bool PlayScene::init()
{
	// ���N���X�̏�����
	if (!Scene::init())
	{
		// ���N���X�̏����������s�Ȃ�A�ُ�I��
		return false;
	}

	////	�J�����̎���
	PlayScene::m_pCamera = this->getDefaultCamera();

	// �w�i�摜
	Sprite* pBackground = Sprite::create("play.png");
	pBackground->setPosition(480, 320);
	this->addChild(pBackground);

	// ���t���[���X�V��L����
	scheduleUpdate();

	// �^�b�`�C�x���g���X�i�[���쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(PlayScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// �C���X�^���X�𐶐�
	m_pFloor = new Floor();
	m_pPlayer = new Player();

	// �V�[���ɂȂ�
	this->addChild(m_pFloor);
	this->addChild(m_pPlayer);

	// �����ݒ�
	m_pFloor->init();
	m_pPlayer->init();

	// �v���X�@�̐ݒ�
	schedule(CC_CALLBACK_0(Floor::Collapse, m_pFloor), 2.0f, "0");

	// ������������I��
	return true;
}

//-----------------------------------------------
//! @brief ���t���[���̍X�V����
//!
//! @param[in] ����
//!
//! @return �Ȃ�
//-----------------------------------------------
void PlayScene::update(float delta)
{
	//	�n�ʂɂ������Ă�����d�͂�����
	if (m_pFloor->isCollision(m_pPlayer->GetRect()))
	{
		Player::isApplyGravity = false;
	}
}

//-----------------------------------------------
//! @brief �^�b�`�J�n������
//!
//! @param[in] ����
//!
//! @return �ȍ~�̃^�b�`�������s�����ǂ���
//-----------------------------------------------
bool PlayScene::onTouchBegan(Touch* touch, Event* pEvent)
{
	return true;
}

//-----------------------------------------------
//! @brief �V�[���J�ڏ���
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//-----------------------------------------------
void PlayScene::TransScene()
{
	// ���̃V�[�����쐬����
	Scene* nextScene = ResultScene::create(GameClear);
	// ���̃V�[���Ɉڍs
	_director->replaceScene(nextScene);
}