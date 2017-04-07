// == �w�b�_�t�@�C���̓ǂݍ��� ========
#include "TitleScene.h"
#include "PlayScene.h"

// == ���O��Ԃ̎w�� ==================
USING_NS_CC;

//-----------------------------------------------
//! @brief ����������
//!
//! @param[in] �Ȃ�
//!
//! @return �I�����
//-----------------------------------------------
bool TitleScene::init()
{
	// ���N���X�̏�����
	if (!Scene::init())
	{
		// ���N���X�̏����������s�Ȃ�A�ُ�I��
		return false;
	}

	// �w�i�摜
	Sprite* background = Sprite::create("title.png");
	background->setPosition(480, 320);
	this->addChild(background);

	// ���t���[���X�V��L����
	scheduleUpdate();

	// �^�b�`�C�x���g���X�i�[���쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);
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
void TitleScene::update(float delta)
{
	
}

//-----------------------------------------------
//! @brief �^�b�`�J�n������
//!
//! @param[in] ����
//!
//! @return �ȍ~�̃^�b�`�������s�����ǂ���
//-----------------------------------------------
bool TitleScene::onTouchBegan(Touch* touch, Event* pEvent)
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
void TitleScene::TransScene()
{
	// ���̃V�[�����쐬����
	Scene* nextScene = PlayScene::create();
	// ���̃V�[���Ɉڍs
	_director->replaceScene(nextScene);
}