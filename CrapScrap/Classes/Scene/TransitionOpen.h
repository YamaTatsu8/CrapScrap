#pragma once

// ヘッダファイルの読み込み
#include "cocos2d.h"

// 独自のトランジションクラス
class TransitionOpen : public cocos2d::TransitionScene
{
public:
	// 独自トランジションの生成　　　　秒数　　　　　次シーン
	static TransitionOpen* create(float t, cocos2d::Scene* scene);

	virtual void onEnter() override;
};