// == ヘッダファイルの読み込み ========
#include "TitleScene.h"
#include "PlayScene.h"
#include "TransitionOpen.h"
#include "HelloWorldScene.h"

// == 名前空間の指定 ==================
USING_NS_CC;

//-----------------------------------------------
//! @brief 初期化処理
//!
//! @param[in] なし
//!
//! @return 終了状態
//-----------------------------------------------
bool TitleScene::init()
{
	// 基底クラスの初期化
	if (!Scene::init())
	{
		// 基底クラスの初期化が失敗なら、異常終了
		return false;
	}

	// タイトル画像 =========================================================
	Sprite* title1= Sprite::create("Title.png");
	title1->setTextureRect(Rect(0, 0, 960, 430));
	title1->setPosition(WINDOW_W / 2, title1->getContentSize().height);
	this->addChild(title1);
	this->reorderChild(title1, 1);

	Sprite* title2 = Sprite::create("Title.png");
	title2->setTextureRect(Rect(0, 450, 960, 370));
	title2->setPosition(WINDOW_W / 2, title2->getContentSize().height/2);
	this->addChild(title2);

	// 歯車 =================================================================
	Sprite* gear1 = Sprite::create("Title.png");
	gear1->setTextureRect(Rect(0, 832, 128, 128));
	gear1->setScale(2.0f);
	gear1->setPosition(0, 600);
	this->addChild(gear1, 2);

	Sprite* gear2 = Sprite::create("Title.png");
	gear2->setTextureRect(Rect(0, 832, 128, 128));
	gear2->setScale(3.5f);
	gear2->setPosition(800, 30);
	this->addChild(gear2, 2);

	// 文字 =================================================================
	Sprite* text = Sprite::create("Title.png");
	text->setTextureRect(Rect(150, 832, 416, 64));
	text->setPosition(WINDOW_W / 2, 100);
	this->addChild(text, 2);

	// 各種アクションを生成

	//文字の点滅
	text->runAction(RepeatForever::create(Blink::create(1.0f, 1)));

	// 毎フレーム更新を有効化
	scheduleUpdate();

	// タッチイベントリスナーを作成
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// 初期化が正常終了
	return true;
}

//-----------------------------------------------
//! @brief 毎フレームの更新処理
//!
//! @param[in] 引数
//!
//! @return なし
//-----------------------------------------------
void TitleScene::update(float delta)
{
	
}

//-----------------------------------------------
//! @brief タッチ開始時処理
//!
//! @param[in] 引数
//!
//! @return 以降のタッチ処理を行うかどうか
//-----------------------------------------------
bool TitleScene::onTouchBegan(Touch* touch, Event* pEvent)
{
	TransScene();
	return true;
}

//-----------------------------------------------
//! @brief シーン遷移処理
//!
//! @param[in] なし
//!
//! @return なし
//-----------------------------------------------
void TitleScene::TransScene()
{
	// 次のシーンを作成する
	Scene* nextScene = PlayScene::create();
	nextScene = TransitionOpen::create(1.0f, nextScene);
	// 次のシーンに移行
	_director->replaceScene(nextScene);
}