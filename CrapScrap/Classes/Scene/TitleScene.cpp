//�w�b�_�t�@�C���̓ǂݍ���
#include "TitleScene.h"
#include "PlayScene.h"

USING_NS_CC;


// ������
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

// ���t���[���X�V
void TitleScene::update(float delta)
{
	
}

// �^�b�`�J�n���R�[���o�b�N
bool TitleScene::onTouchBegan(Touch* touch, Event* pEvent)
{
	// ���̃V�[�����쐬����
	Scene* nextScene = PlayScene::create();
	// ���̃V�[���Ɉڍs
	_director->replaceScene(nextScene);

	return true;
}
