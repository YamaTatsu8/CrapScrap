//　Tatsuya Yamada
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
const int DENTI_MAX = (4);
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
	cocos2d::Node* m_floor;
	//
	cocos2d::Node* m_press[PRESS_MAX];

	//床
	cocos2d::Sprite* floor[FLOOR_MAX];
	//プレス
	cocos2d::Sprite* press[PRESS_MAX * 3];
	//ドア
	cocos2d::Sprite* door;
	//電池
	cocos2d::Sprite* denti[DENTI_MAX];
	//コンベア
	cocos2d::Sprite* leftConbea;
	cocos2d::Sprite* rightConbea;
	//エレベーター
	cocos2d::Sprite* elevator;
	//ゴール
	cocos2d::Sprite* goal;
	//テスト
	cocos2d::Sprite* test[32][32];

public:

	CREATE_FUNC(Floor);

	//初期化処理
	bool init();

	//プレスが当たったら崩れる
	void Collapse();

	//マップの読み込み
	void importData(std::string fileName);

	//エレベーターの上昇
	void rising();

	//床の消失
	void FloorCollapse();

};