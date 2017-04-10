///-------------------------------------------------------------------
//*
//*	@名前		Player.h
//*
//*	@作成日		2017/04/07
//*
//*	@著者		加藤 彰馬
//*
///-------------------------------------------------------------------


// 多重インクルードの禁止
#pragma once

// ヘッダーファイルのインクルード
#include "cocos2d.h"
#include "ui/CocosGUI.h"



//////////////////////////////
///　プレイヤクラスの定義　///
//////////////////////////////
class Player : public cocos2d::Layer
{
private:
	// 移動量
	float m_movement;

	// ジャンプの高さ
	float m_jumping;

	// バッテリ
	float m_consume;

	// バッテリ残量
	float m_battery;

	// アクション中か否か（アクション中なら値が入る）
	int actionNow;

	// フレーム数のカウント変数
	int m_cnt;

	// プレイヤの画像が一枚目か二枚目か
	bool m_frontback;

	// プレイヤの現在位置
	cocos2d::Vec2 m_playerPos;


public:
	// create関数の宣言と定義
	static Player* create();

	// 初期化
	bool init();

	// 更新
	void update(float delta);

	//////////////////////////////
	/// コールバック関数の宣言 ///
	//////////////////////////////

	// 右、左ボタン用タッチイベントリスナー
	void rightButtonMove(Ref * ref, cocos2d::ui::Widget::TouchEventType eventtype);
	void leftButtonMove(Ref * ref, cocos2d::ui::Widget::TouchEventType eventtype);
	//// アクション、ジャンプボタン用クリックイベントリスナー
	bool buttonJump(Ref *ref);
	bool buttonAction(Ref *ref);



	//////////////////////////////
	/// スプライト・ノード登録 ///
	//////////////////////////////

	// プレイヤ
	cocos2d::Sprite* player;
	// プレイヤ（ニュートラルモーション用）
	cocos2d::Sprite* player2;
	// プレイヤ（ジャンプモーション用）
	cocos2d::Sprite* playerJump;
	// プレイヤ（アクションモーション用）
	cocos2d::Sprite* playerAction;
	// プレイヤ（攻撃モーション用）
	cocos2d::Sprite* playerAttack;
	// プレイヤ（機能停止モーション用）
	cocos2d::Sprite* playerOff;

	// バッテリーゲージ
	cocos2d::Sprite* gauge;
	// バッテリー容量
	cocos2d::Sprite* charged;

	// プレイヤ全部
	cocos2d::Node* players;
	//// バッテリ全体
	//cocos2d::Node* battery;

};

