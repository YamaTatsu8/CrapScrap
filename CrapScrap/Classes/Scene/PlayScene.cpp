// == ヘッダファイルの読み込み ========
#include "PlayScene.h"
#include "ResultScene.h"

// == 名前空間の指定 ==================
USING_NS_CC;

//-----------------------------------------------
//! @brief 初期化処理
//!
//! @param[in] なし
//!
//! @return 終了状態
//-----------------------------------------------
bool PlayScene::init()
{
	// 基底クラスの初期化
	if (!Scene::init())
	{
		// 基底クラスの初期化が失敗なら、異常終了
		return false;
	}

	// 背景画像
	Sprite* pBackground = Sprite::create("play.png");
	pBackground->setPosition(480, 320);
	this->addChild(pBackground);

	// 毎フレーム更新を有効化
	scheduleUpdate();

	// インスタンスを生成
	m_pFloor = new Floor();

	// シーンにつなぐ
	this->addChild(m_pFloor);

	schedule(CC_CALLBACK_0(Floor::Collapse, m_pFloor), 5.0f, "0");
	// 初期設定
	m_pFloor->init();

	// タッチイベントリスナーを作成
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(PlayScene::onTouchBegan, this);
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
void PlayScene::update(float delta)
{

}

//-----------------------------------------------
//! @brief タッチ開始時処理
//!
//! @param[in] 引数
//!
//! @return 以降のタッチ処理を行うかどうか
//-----------------------------------------------
bool PlayScene::onTouchBegan(Touch* touch, Event* pEvent)
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
void PlayScene::TransScene()
{
	// 次のシーンを作成する
	Scene* nextScene = ResultScene::create(GameClear);
	// 次のシーンに移行
	_director->replaceScene(nextScene);
}