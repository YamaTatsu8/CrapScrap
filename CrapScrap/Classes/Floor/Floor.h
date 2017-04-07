//　Tatsuya Yamada
// フロアクラス
#pragma once
#include "cocos2d.h"

#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

//床の最大数
const int FLOOR_MAX = 3600;
//チップの最大数
const int TIP_MAX = 3600;
//幅と高さのチップ数
const int WIGHT = 120;
const int HEIGHT = 40;

class Floor:public cocos2d::Layer
{	
private:

	//チップ
	int m_Tip[WIGHT][HEIGHT];

public:

	

	//初期化処理
	bool init();

	//床
	cocos2d::Sprite* floor[FLOOR_MAX];

	//プレスが当たったら崩れる
	void Collapse(int num);

	//マップの読み込み
	void importData(std::string fileName);

};