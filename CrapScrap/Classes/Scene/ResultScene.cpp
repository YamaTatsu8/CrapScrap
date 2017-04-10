//�w�b�_�t�@�C���̓ǂݍ���
#include "HelloWorldScene.h"
#include "ResultScene.h"
#include "TitleScene.h"
#include "TransitionClose.h"

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

// ������
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


// ���t���[���X�V
void ResultScene::update(float delta)
{

}

// �^�b�`�J�n���R�[���o�b�N
bool ResultScene::onTouchBegan(Touch* touch, Event* pEvent)
{
	// ���̃V�[�����쐬����
	Scene* nextScene = TitleScene::create();

	nextScene = TransitionClose::create(1.0f, nextScene);

	// ���̃V�[���Ɉڍs
	_director->replaceScene(nextScene);

	return true;
}
