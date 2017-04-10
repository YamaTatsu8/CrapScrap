//�w�b�_�t�@�C���̓ǂݍ���
#include "HelloWorldScene.h"
#include "TransitionOpen.h"

USING_NS_CC;

TransitionOpen* TransitionOpen::create(float t, Scene* scene)
{
	// �g�����W�V�����V�[���̍쐬
	TransitionOpen* newScene = new (std::nothrow) TransitionOpen();
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

void TransitionOpen::onEnter()
{
	// ���N���X�̏����i�^�b�`�������Ȃǁj
	TransitionScene::onEnter();

	Size s = Director::getInstance()->getWinSize();

	// �O�V�[�����\��
	_outScene->setVisible(false);
	
	// �^�C�g���摜 =========================================================
	Sprite* title1 = Sprite::create("Title.png");
	title1->setTextureRect(Rect(0, 0, 960, 430));
	title1->setPosition(WINDOW_W / 2, title1->getContentSize().height);
	this->addChild(title1);
	this->reorderChild(title1, 1);

	Sprite* title2 = Sprite::create("Title.png");
	title2->setTextureRect(Rect(0, 450, 960, 370));
	title2->setPosition(WINDOW_W / 2, title2->getContentSize().height / 2);
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


	// �e��A�N�V�����𐶐�

	//�㉺�ɊJ��
	title1->runAction(MoveBy::create(0.5f, Vec2(0, title1->getContentSize().height)));
	title2->runAction(MoveBy::create(0.5f, Vec2(0, -title2->getContentSize().height)));

	//���ԉ��
	gear1->runAction
	(
		Sequence::create
		(
			RotateBy::create(0.5f, 360),
			MoveBy::create(0.25f, Vec2(0, 300)),
			nullptr
		)
	);
	gear2->runAction
	(
		Sequence::create
		(
			RotateBy::create(0.5f, -360),
			MoveBy::create(0.25f, Vec2(0, - 300)),
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