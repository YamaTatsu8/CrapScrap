///-------------------------------------------------------------------
//*
//*	@名前		Player.cpp
//*
//*	@作成日		2017/04/07
//*
//*	@著者		加藤 彰馬
//*
///-------------------------------------------------------------------

// ヘッダーファイルのインクルード
//#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "Player.h"

// cocos2d-xの名前空間
USING_NS_CC; 
using namespace cocostudio;
using namespace ui;


const int バッテリ分子 = 300;
const int バッテリ分母 = 1;			/* グラフィックの幅が300なので、分子/分母が300になるように */
const int empty = 37;


////////////////////////////
/// プレイヤクラスの宣言 ///
////////////////////////////

////----------------------------------------------------------------------
////! @関数名：init
////!
////! @役割：プレイヤクラスの初期化処理
////!
////! @引数：なし
////!
////! @戻り値：初期化に成功したか否か
////----------------------------------------------------------------------
bool Player::init()
{

	// 毎フレーム更新を有効化
	scheduleUpdate();

	// フレーム数カウントの初期化
	m_cnt = 0;

	// ジャンプ量の決定
	m_jumping = 100.0f;

	// バッテリーの初期量
	m_consume = バッテリ分子;



	////////////////////////
	///	スプライトの設定 ///
	////////////////////////

	//==========プレイヤの設置・表示==========//

	// プレイヤを設置
	player = Sprite::create("player.png");
	m_playerPos = Vec2(200.0f, 200.0f);
	player->setPosition(m_playerPos);
	// モーション遷移のやり方がわからない為、不透明の他プレイヤ画像を用意しておく
	player2 = Sprite::create("player2.png");
	player2->setPosition(m_playerPos);
	player2->setVisible(false);
	playerJump = Sprite::create("PlayerJump.png");
	playerJump->setPosition(m_playerPos);
	playerJump->setVisible(false);
	playerAction = Sprite::create("playerAction.png");
	playerAction->setPosition(m_playerPos);
	playerAction->setVisible(false);
	playerAttack = Sprite::create("playerAttack.png");
	playerAttack->setPosition(m_playerPos);
	playerAttack->setVisible(false);
	playerOff = Sprite::create("playerOff.png");
	playerOff->setPosition(m_playerPos);
	playerOff->setVisible(false);

	// trueがplayer.pngでfalseがplayer2.png.最初はtrue
	m_frontback = true;		

	// プレイヤをシーンに貼り付ける
	this->addChild(player);
	this->addChild(player2);
	this->addChild(playerJump);
	this->addChild(playerAction);
	this->addChild(playerAttack);
	this->addChild(playerOff);


	//==========バッテリの設置・表示==========//

	// バッテリーゲージ
	gauge = Sprite::create("Gauge.png");
	gauge->setPosition(790.0f, 600.0f);
	this->addChild(gauge);

	// バッテリー容量
	charged = Sprite::create("Charged.png");
	charged->setPosition(640.0f, 600.0f);
	this->addChild(charged);

	// バッテリー容量をアンカーでゲージ左端に固定
	charged->setAnchorPoint(Vec2(0.0f, 0.5f));


	// プレイヤをノードで親子付する
	players = Node::create();
	this->addChild(players);
	players->addChild(player);
	players->addChild(player2);
	players->addChild(playerJump);
	players->addChild(playerAction);
	players->addChild(playerAttack);
	players->addChild(playerOff);


	//// バッテリをノードで親子付する
	//battery = Node::create();
	//this->addChild(battery);
	//battery->addChild(gauge);
	//battery->addChild(charged);


	////////////////////////
	///	各種ボタンの設定 ///
	////////////////////////

	//==========ボタンの設置・表示==========//

	// 右ボタン
	ui::Button* rightButton = ui::Button::create("RightButton.png");
	rightButton->setPosition(Vec2(860.0f, 75.0f));
	this->addChild(rightButton);
	// 左ボタン
	ui::Button* leftButton = ui::Button::create("LeftButton.png");
	leftButton->setPosition(Vec2(100.0f, 75.0f));
	this->addChild(leftButton);
	// アクションボタン
	ui::Button* actionButton = ui::Button::create("ActionButton.png");
	actionButton->setPosition(Vec2(610.0f, 75.0f));
	this->addChild(actionButton);
	// ジャンプボタン
	ui::Button* jumpButton = ui::Button::create("JumpButton.png");
	jumpButton->setPosition(Vec2(350.0f, 75.0f));
	this->addChild(jumpButton);


	//==========イベントコールバックの登録==========//

	// 左、右ボタンはタッチイベントリスナー
	rightButton->addTouchEventListener(CC_CALLBACK_2(Player::rightButtonMove, this));
	leftButton->addTouchEventListener(CC_CALLBACK_2(Player::leftButtonMove, this));
	// ジャンプ、アクションボタンはクリックイベントリスナー
	jumpButton->addClickEventListener(CC_CALLBACK_1(Player::buttonJump, this));
	actionButton->addTouchEventListener(CC_CALLBACK_1(Player::buttonAction, this));

	return true;
}


////----------------------------------------------------------------------
////! @関数名：update
////!
////! @役割：プレイヤクラスの更新処理
////!
////! @引数：フレーム数(float)
////!
////! @戻り値：なし(void)
////----------------------------------------------------------------------
void Player::update(float delta)
{
	// 毎フレーム増えていくカウント変数
	m_cnt++;

	// 毎フレームバッテリが減る
	m_consume--;

	m_battery = m_consume / バッテリ分母;

	// バッテリの消費を矩形処理で表現
	charged->setTextureRect(Rect(0, 0, m_battery, 50));

	// バッテリが残ってたら毎フレームプレイヤの座標を現在の位置へ更新
	if (m_battery > empty)
	{
		m_playerPos += Vec2(m_movement, 0.0f);			/* m_movementはボタンを押している間のみ値が入る */
		players->setPositionX(m_playerPos.x);
	}

	// 30フレームでプレイヤ画像の切り替え
	if (m_frontback)
	{
		//	// player.pngの場所にplayer2.pngを設置
		//	player->getPosition();
		player->setVisible(true);
		player2->setVisible(false);

	}
	else
	{
		player2->setVisible(true);
		player->setVisible(false);
	}

	//* 30フレーム経ったら表裏判断のブール型を切り替える
	if (m_cnt > 30)
	{
		//* これで切り替える処理に
		if (m_frontback)
		{
			m_frontback = false;
		}
		else
		{
			m_frontback = true;
		}

		// さらにここでカウントを０にすれば、ここのブールの切り替えを連続で行うことに
		m_cnt = 0;
	}
	


	//* アクション中の移動値を取ってくれる関数をif文に利用する
	actionNow = players->numberOfRunningActions();

	if (actionNow)
	{
		// ジャンプモーションを表示・ニュートラルモーションを非表示
		player->setVisible(false);
		player2->setVisible(false);
		playerJump->setVisible(true);
	}
	else
	{
		// ジャンプモーションを非表示
		playerJump->setVisible(false);
	}

	// バッテリーが切れたら機能停止グラに
	if (m_battery < empty)
	{
		player->setVisible(false);
		player2->setVisible(false);
		playerJump->setVisible(false);
		playerAction->setVisible(false);
		playerAttack->setVisible(false);
		playerOff->setVisible(true);
	}

}


////----------------------------------------------------------------------
////! @関数名：rightButtonMove
////!
////! @役割：右移動のボタンが押されたら、プレイヤを右へ移動させる。
////!
////! @引数：右ボタンのタッチ判定(Ref)
////!
////! @戻り値：プレイヤの移動量(int)
////----------------------------------------------------------------------
void Player::rightButtonMove(Ref* ref, cocos2d::ui::Widget::TouchEventType eventtype)
{
	switch (eventtype)
	{
		// 押した時
	case ui::Widget::TouchEventType::BEGAN:
		// 押したら移動量に値を代入
		m_movement = 5.0f;
		break;

		// 動かした時
	case ui::Widget::TouchEventType::MOVED:
		// 動かしたときは何もしない
		break;

		// 離した時
	case ui::Widget::TouchEventType::ENDED:
		// 離したら移動量を０に
		m_movement = 0.0f;
		break;

		// キャンセルされた時・ボタン上でないところで離されること
	case ui::Widget::TouchEventType::CANCELED:
		// ボタンの外でも離したら移動量を０に
		m_movement = 0.0f;
		break;

	default:
		m_movement = 0.0f;
		break;
	}

}



////----------------------------------------------------------------------
////! @関数名：leftButtonMove
////!
////! @役割：左移動のボタンが押されたら、プレイヤを左へ移動させる。
////!
////! @引数：左ボタンのタッチ判定(Ref)
////!
////! @戻り値：プレイヤの移動量(int)
////----------------------------------------------------------------------
void Player::leftButtonMove(Ref * ref, cocos2d::ui::Widget::TouchEventType eventtype)
{
	switch (eventtype)
	{
		// 押した時
	case ui::Widget::TouchEventType::BEGAN:
		// 押したら移動量に値を代入
		m_movement = -5.0f;
		break;

		// 動かした時
	case ui::Widget::TouchEventType::MOVED:
		// 動かしたときは何もしない
		break;

		// 離した時
	case ui::Widget::TouchEventType::ENDED:
		// 離したら移動量を０に
		m_movement = 0.0f;
		break;

		// キャンセルされた時・ボタン上でないところで離されること
	case ui::Widget::TouchEventType::CANCELED:

		// ボタンの外でも離したら移動量を０に
		m_movement = 0.0f;
		break;

	default:
		m_movement = 0.0f;
		break;
	}

}


////----------------------------------------------------------------------
////! @関数名：buttonJump
////!
////! @役割：ジャンプボタンが押されたら、プレイヤをジャンプさせる。
////!
////! @引数：ジャンプのボタンタッチ判定(Ref)
////!
////! @戻り値：プレイヤのジャンプ量(int)
////----------------------------------------------------------------------
bool Player::buttonJump(Ref * ref)
{
	if (m_battery >= empty)
	{
		if (!actionNow)
		{
			JumpBy* jumping = JumpBy::create(0.5f, Vec2(0.0f, 0.0f), m_jumping, 1);
			// ジャンプモーションを非表示
			players->runAction(jumping);
		}
	}


	return false;
}


////----------------------------------------------------------------------
////! @関数名：onActionButtonTouch
////!
////! @役割：その時に応じたアクションを行う。
////!
////! @引数：アクションのボタンタッチ判定(Ref)
////!
////! @戻り値：
////----------------------------------------------------------------------
bool Player::buttonAction(Ref * ref)
{
	if (m_consume >= empty)
	{

	}
	return false;
}
