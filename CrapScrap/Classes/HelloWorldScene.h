#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

// == ヘッダファイルの読み込み ========
#include "cocos2d.h"

// == 定数の宣言 ======================
// ウインドウサイズ
const int WINDOW_H = 640;
const int WINDOW_W = 960;

// == クラスの宣言 ====================
class HelloWorld : public cocos2d::Layer
{
public:
	// メンバ関数 ///////////
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
