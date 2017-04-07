//ヘッダファイルの読み込み
#include "ResultScene.h"
#include "TitleScene.h"

USING_NS_CC;


// 初期化
bool ResultScene::init()
{
	// 基底クラスの初期化
	if (!Scene::init())
	{
		// 基底クラスの初期化が失敗なら、異常終了
		return false;
	}

	// 背景画像
	//Sprite* background = Sprite::create("title.png");
	//background->setPosition(480, 320);
	//this->addChild(background);

	// 毎フレーム更新を有効化
	scheduleUpdate();

	// タッチイベントリスナーを作成
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(ResultScene::onTouchBegan, this);
	_director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// 初期化が正常終了
	return true;
}

// 毎フレーム更新
void ResultScene::update(float delta)
{

}

// タッチ開始時コールバック
bool ResultScene::onTouchBegan(Touch* touch, Event* pEvent)
{
	// 次のシーンを作成する
	Scene* nextScene = TitleScene::create();
	// 次のシーンに移行
	_director->replaceScene(nextScene);

	return true;
}
