// == �w�b�_�t�@�C���̓ǂݍ��� ========
#include "HelloWorldScene.h"
#include "ResultScene.h"
#include "TitleScene.h"
#include "TransitionClose.h"

// == ���O��Ԃ̎w�� ==================
USING_NS_CC;

//�V�[������
ResultScene * ResultScene::create(ResultType type)
{
	ResultScene *pRet = new(std::nothrow) ResultScene();
	if (pRet && pRet->init(type))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

//-----------------------------------------------
//! @brief ����������
//!
//! @param[in] �Ȃ�
//!
//! @return �I�����
//-----------------------------------------------
bool ResultScene::init(ResultType type)
{
	// ���N���X�̏�����
	if (!Scene::init())
	{
		// ���N���X�̏����������s�Ȃ�A�ُ�I��
		return false;
	}

	// �w�i�摜
	Sprite* background;
	if (type == GameClear)
		background = Sprite::create("GameClear.png");
	else
		background = Sprite::create("GameOver.png");

	background->setPosition(480, 320);
	this->addChild(background);

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
	listener->onTouchBegan = CC_CALLBACK_2(ResultScene::onTouchBegan, this);
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
void ResultScene::update(float delta)
{

}

//-----------------------------------------------
//! @brief �^�b�`�J�n������
//!
//! @param[in] ����
//!
//! @return �ȍ~�̃^�b�`�������s�����ǂ���
//-----------------------------------------------
bool ResultScene::onTouchBegan(Touch* touch, Event* pEvent)
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
void ResultScene::TransScene()
{
	// ���̃V�[�����쐬����
	Scene* nextScene = TitleScene::create();

	nextScene = TransitionClose::create(1.0f, nextScene);

	// ���̃V�[���Ɉڍs
	_director->replaceScene(nextScene);
}