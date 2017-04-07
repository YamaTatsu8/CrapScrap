// 多重インクルードの防止
#pragma once

// == ヘッダファイルの読み込み ========
#include "cocos2d.h"
#include "HelloWorldScene.h"

// == クラスの宣言 ====================
class ResultScene : public cocos2d::Scene
{
public:
	// メンバ関数 ///////////
	// create関数の宣言と定義
	CREATE_FUNC(ResultScene);
	// 初期化処理
	bool init();
	// 毎フレームの更新処理
	void update(float delta) override;
	// シーン遷移処理
	void TransScene();

	// タッチ時の処理
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
};