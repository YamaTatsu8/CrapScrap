/* �֐��̃e���v���[�g
//-----------------------------------------------
//! @brief �������e
//!
//! @param[in] ����
//!
//! @return �߂�l
//-----------------------------------------------
*/
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

// == �w�b�_�t�@�C���̓ǂݍ��� ========
#include "cocos2d.h"

// == �萔�̐錾 ======================
// �E�C���h�E�T�C�Y
const int WINDOW_H = 640;
const int WINDOW_W = 960;

// == �N���X�̐錾 ====================
class HelloWorld : public cocos2d::Layer
{
public:
	// �����o�֐� ///////////
    // �V�[���쐬����
    static cocos2d::Scene* createScene();
	// ����������
	virtual bool init();
	// create�֐��̐錾�ƒ�`
	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
