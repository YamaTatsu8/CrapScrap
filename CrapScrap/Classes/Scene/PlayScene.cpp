// == �w�b�_�t�@�C���̓ǂݍ��� ========
#include "PlayScene.h"
#include "ResultScene.h"

// == ���O��Ԃ̎w�� ==================
USING_NS_CC;

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

	// �w�i�摜
	Sprite* pBackground = Sprite::create("play.png");
	pBackground->setPosition(480, 320);
	this->addChild(pBackground);

	// ���t���[���X�V��L����
	scheduleUpdate();

	// �C���X�^���X�𐶐�
	m_pFloor = new Floor();

	// �V�[���ɂȂ�
	this->addChild(m_pFloor);

	schedule(CC_CALLBACK_0(Floor::Collapse, m_pFloor), 5.0f, "0");
	// �����ݒ�
	m_pFloor->init();

	// �^�b�`�C�x���g���X�i�[���쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(PlayScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

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
	TransScene();
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