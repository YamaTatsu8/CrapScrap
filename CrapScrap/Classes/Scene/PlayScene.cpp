//�w�b�_�t�@�C���̓ǂݍ���
#include "PlayScene.h"
#include "ResultScene.h"

USING_NS_CC;

// ������
bool PlayScene::init()
{
	// ���N���X�̏�����
	if (!Scene::init())
	{
		// ���N���X�̏����������s�Ȃ�A�ُ�I��
		return false;
	}

	// �w�i�摜
	Sprite* background = Sprite::create("play.png");
	background->setPosition(480, 320);
	this->addChild(background);

	// ���t���[���X�V��L����
	scheduleUpdate();

	// �^�b�`�C�x���g���X�i�[���쐬
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(PlayScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// ������������I��
	return true;
}

// ���t���[���X�V
void PlayScene::update(float delta)
{

}

// �^�b�`�J�n���R�[���o�b�N
bool PlayScene::onTouchBegan(Touch* touch, Event* pEvent)
{
	// ���̃V�[�����쐬����
	Scene* nextScene = ResultScene::create(GameClear);
	// ���̃V�[���Ɉڍs
	_director->replaceScene(nextScene);

	return true;
}
