// == �w�b�_�t�@�C���̓ǂݍ��� ========
#include "TitleScene.h"
#include "PlayScene.h"
#include "TransitionOpen.h"
#include "HelloWorldScene.h"

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

	// �^�C�g���摜 =========================================================
	Sprite* title1= Sprite::create("Title.png");
	title1->setTextureRect(Rect(0, 0, 960, 430));
	title1->setPosition(WINDOW_W / 2, title1->getContentSize().height);
	this->addChild(title1);
	this->reorderChild(title1, 1);

	Sprite* title2 = Sprite::create("Title.png");
	title2->setTextureRect(Rect(0, 450, 960, 370));
	title2->setPosition(WINDOW_W / 2, title2->getContentSize().height/2);
	this->addChild(title2);

	// ���� =================================================================
	Sprite* gear1 = Sprite::create("Title.png");
	gear1->setTextureRect(Rect(0, 832, 128, 128));
	gear1->setScale(2.0f);
	gear1->setPosition(0, 600);
	this->addChild(gear1, 2);

	Sprite* gear2 = Sprite::create("Title.png");
	gear2->setTextureRect(Rect(0, 832, 128, 128));
	gear2->setScale(3.5f);
	gear2->setPosition(800, 30);
	this->addChild(gear2, 2);

	// ���� =================================================================
	Sprite* text = Sprite::create("Title.png");
	text->setTextureRect(Rect(150, 832, 416, 64));
	text->setPosition(WINDOW_W / 2, 100);
	this->addChild(text, 2);

	// �e��A�N�V�����𐶐�

	//�����̓_��
	text->runAction(RepeatForever::create(Blink::create(1.0f, 1)));

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
void TitleScene::TransScene()
{
	// ���̃V�[�����쐬����
	Scene* nextScene = PlayScene::create();
	nextScene = TransitionOpen::create(1.0f, nextScene);
	// ���̃V�[���Ɉڍs
	_director->replaceScene(nextScene);
}