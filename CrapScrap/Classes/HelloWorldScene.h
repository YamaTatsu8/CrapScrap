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
#include "Player.h"

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
<<<<<<< HEAD

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	Player* m_player;
=======
	// ����������
	virtual bool init();
	// create�֐��̐錾�ƒ�`
	CREATE_FUNC(HelloWorld);
>>>>>>> cdf1002c254d50122a70be6305e9e84e68142d57
};

#endif // __HELLOWORLD_SCENE_H__
