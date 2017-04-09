//　Tatsuya Yamada
// フロアクラス
#pragma once
#include "cocos2d.h"

#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

//床の最大数
const int FLOOR_MAX = 2000;
//プレスの最大数
const int PRESS_MAX = 3600;
//チップの最大数
const int TIP_MAX = 3600;
//ドアの最大数
const int DOOR_MAX = 3600;
//コンベアの最大数
const int CONBEA_MAX = 3600;
//電池の最大数
const int DENTI_MAX = 4;
//幅と高さのチップ数
const int WIGHT = 120;
const int HEIGHT = 30;

class Floor :public cocos2d::Layer
{
private:

	//チップ
	int m_Tip[HEIGHT][WIGHT];

public:

	CREATE_FUNC(Floor);

	//初期化処理
	bool init();

	//床
	cocos2d::CCSprite* floor[FLOOR_MAX];
	//プレス
	cocos2d::CCSprite* press[PRESS_MAX];
	//ドア
	cocos2d::CCSprite* door;
	//電池
	cocos2d::CCSprite* denti[DENTI_MAX];
	//コンベア
	cocos2d::CCSprite* leftConbea;
	cocos2d::CCSprite* rightConbea;
	//エレベーター
	cocos2d::CCSprite* elevator;
	//ゴール
	cocos2d::CCSprite* goal;

	//テスト
	cocos2d::Sprite* test[32][32];



	//プレスが当たったら崩れる
	void Collapse(int num);

	//マップの読み込み
	void importData(std::string fileName);

};