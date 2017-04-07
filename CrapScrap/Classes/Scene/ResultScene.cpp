// == �w�b�_�t�@�C���̓ǂݍ��� ========
#include "ResultScene.h"
#include "TitleScene.h"

// == ���O��Ԃ̎w�� ==================
USING_NS_CC;

//-----------------------------------------------
//! @brief ����������
//!
//! @param[in] �Ȃ�
//!
//! @return �I�����
//-----------------------------------------------
bool ResultScene::init()
{
	// ���N���X�̏�����
	if (!Scene::init())
	{
		// ���N���X�̏����������s�Ȃ�A�ُ�I��
		return false;
	}

	// �w�i�摜
	//Sprite* background = Sprite::create("title.png");
	//background->setPosition(480, 320);
	//this->addChild(background);

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
	// ���̃V�[���Ɉڍs
	_director->replaceScene(nextScene);
}