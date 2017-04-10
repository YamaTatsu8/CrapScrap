//�w�b�_�t�@�C���̓ǂݍ���
#include "HelloWorldScene.h"
#include "TransitionClose.h"

USING_NS_CC;

TransitionClose* TransitionClose::create(float t, Scene* scene)
{
	// �g�����W�V�����V�[���̍쐬
	TransitionClose* newScene = new (std::nothrow) TransitionClose();
	// �g�����W�V�����V�[���̏�����
	if (newScene && newScene->initWithDuration(t, scene))
	{
		// ��������}�l�[�W���ɓo�^
		newScene->autorelease();
		return newScene;
	}
	// �������Ɏ��s�����ꍇ�A�������NULL�|�C���^��Ԃ�
	CC_SAFE_DELETE(newScene);
	return nullptr;
}

void TransitionClose::onEnter()
{
	// ���N���X�̏����i�^�b�`�������Ȃǁj
	TransitionScene::onEnter();

	Size s = Director::getInstance()->getWinSize();

	// ���V�[�����\��
	_inScene->setVisible(false);

	// �^�C�g���摜 =========================================================
	Sprite* title1 = Sprite::create("Title.png");
	title1->setTextureRect(Rect(0, 0, 960, 430));
	title1->setPosition(WINDOW_W / 2, WINDOW_H + title1->getContentSize().height/2);
	this->addChild(title1);
	this->reorderChild(title1, 1);

	Sprite* title2 = Sprite::create("Title.png");
	title2->setTextureRect(Rect(0, 450, 960, 370));
	title2->setPosition(WINDOW_W / 2, 0 - title2->getContentSize().height / 2);
	this->addChild(title2);

	// ���� =================================================================
	Sprite* gear1 = Sprite::create("Title.png");
	gear1->setTextureRect(Rect(0, 832, 128, 128));
	gear1->setScale(2.0f);
	gear1->setPosition(0, 900);
	this->addChild(gear1, 2);

	Sprite* gear2 = Sprite::create("Title.png");
	gear2->setTextureRect(Rect(0, 832, 128, 128));
	gear2->setScale(3.5f);
	gear2->setPosition(800, -270);
	this->addChild(gear2, 2);


	// �e��A�N�V�����𐶐�

	//�㉺�������
	title1->runAction
	(
		Sequence::create
		(
			DelayTime::create(0.25f),
			MoveBy::create(0.5f, Vec2(0, -title1->getContentSize().height)),
			nullptr
		)
	);
	title2->runAction
	(
		Sequence::create
		(
			DelayTime::create(0.25f),
			MoveBy::create(0.5f, Vec2(0, title2->getContentSize().height)),
			nullptr
		)
	);

	//���ԉ��
	gear1->runAction
	(
		Sequence::create
		(
			MoveBy::create(0.25f, Vec2(0, -300)),
			RotateBy::create(0.5f, -360),
			nullptr
		)
	);
	gear2->runAction
	(
		Sequence::create
		(
			MoveBy::create(0.25f, Vec2(0, 300)),
			RotateBy::create(0.5f, 360),
			nullptr
		)
	);

	//�ҋ@
	ActionInterval *delay = DelayTime::create(1.0f);

	// ���V�[���ւ̃A�N�V���������s
	_inScene->runAction
	(
		Sequence::create
		(
			// �ҋ@
			delay,
			// �V�[���J�ڂ̏I������
			CallFunc::create(CC_CALLBACK_0(TransitionScene::finish, this)),
			nullptr
		)
	);
}