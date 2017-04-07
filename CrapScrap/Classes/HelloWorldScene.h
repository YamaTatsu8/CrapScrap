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
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
