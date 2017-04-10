#pragma once

// ヘッダファイルの読み込み
#include "cocos2d.h"

// 独自のトランジションクラス
class TransitionClose : public cocos2d::TransitionScene
{
public:
	// 独自トランジションの生成　　　　秒数　　　　　次シーン
	static TransitionClose* create(float t, cocos2d::Scene* scene);

	virtual void onEnter() override;
};