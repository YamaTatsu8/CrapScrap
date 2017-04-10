/* 関数のテンプレート
//-----------------------------------------------
//! @brief 処理内容
//!
//! @param[in] 引数
//!
//! @return 戻り値
//-----------------------------------------------
*/
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

// == ヘッダファイルの読み込み ========
#include "cocos2d.h"
#include "Player.h"

// == 定数の宣言 ======================
// ウインドウサイズ
const int WINDOW_H = 640;
const int WINDOW_W = 960;

// == クラスの宣言 ====================
class HelloWorld : public cocos2d::Layer
{
public:
	// メンバ関数 ///////////
    // シーン作成処理
    static cocos2d::Scene* createScene();
<<<<<<< HEAD

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	Player* m_player;
=======
	// 初期化処理
	virtual bool init();
	// create関数の宣言と定義
	CREATE_FUNC(HelloWorld);
>>>>>>> cdf1002c254d50122a70be6305e9e84e68142d57
};

#endif // __HELLOWORLD_SCENE_H__
