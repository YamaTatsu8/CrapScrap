////////////////
// 野獣の眼光 //
////////////////

// フロアクラス
#pragma once
#include "cocos2d.h"

#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

//床の最大数
const int FLOOR_MAX = (2000);
//プレスの最大数
const int PRESS_MAX = (40);
//チップの最大数
const int CHIP_MAX = (3600);
//電池の最大数
const int BATTERY_MAX = (4);
//幅と高さのチップ数
const int WIDTH = (120);
const int HEIGHT = (30);
// チップのサイズ
const float CHIP_SIZE = (32.0f);

class Floor :public cocos2d::Layer
{
private:

	//チップ
	int m_Chip[HEIGHT][WIDTH];

	//
	cocos2d::Node* m_pFloorNode;
	//
	cocos2d::Node* m_pPressNode[PRESS_MAX];

	//床
	cocos2d::Sprite* m_pFloor[FLOOR_MAX];
	//プレス
	cocos2d::Sprite* m_pPress[PRESS_MAX * 3];
	//ドア
	cocos2d::Sprite* m_pDoor;
	//電池
	cocos2d::Sprite* m_pBattery[BATTERY_MAX];
	//コンベア
	cocos2d::Sprite* m_pLeftConveyor;
	cocos2d::Sprite* m_pRightConveyor;
	//エレベーター
	cocos2d::Sprite* m_pElevator;
	//ゴール
	cocos2d::Sprite* m_pGoal;
	//テスト
	cocos2d::Sprite* test[32][32];

public:

	CREATE_FUNC(Floor);

	//初期化処理
	bool init();

	// 毎フレームの更新処理
	void update(float delta) override;
	
	//プレスが当たったら崩れる
	void Collapse();

	//マップの読み込み
	void importData(std::string fileName);

	//エレベーターの上昇
	void rising();

	//床の消失
	void FloorCollapse();

	//
	bool isCollision(cocos2d::Rect rect);
};