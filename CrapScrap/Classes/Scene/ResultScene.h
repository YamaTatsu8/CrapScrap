#pragma once

// ヘッダファイルの読み込み
#include "cocos2d.h"

// リザルトシーン
class ResultScene : public cocos2d::Scene
{
public:
	// create関数の宣言と定義
	CREATE_FUNC(ResultScene);

	// 初期化
	bool init();

	// 毎フレーム更新
	void update(float delta) override;

	// タッチ開始時コールバック
	bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * pEvent);
};