//ヘッダファイルの読み込み
#include "HelloWorldScene.h"
#include "ResultScene.h"
#include "TitleScene.h"
#include "TransitionClose.h"

USING_NS_CC;

//シーン生成
ResultScene * ResultScene::create(ResultType type)
{
	ResultScene *pRet = new(std::nothrow) ResultScene();
	if (pRet && pRet->init(type))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
}

// 初期化
bool ResultScene::init(ResultType type)
{
	// 基底クラスの初期化
	if (!Scene::init())
	{
		// 基底クラスの初期化が失敗なら、異常終了
		return false;
	}

	// 背景画像
	Sprite* background;
	if (type == GameClear)
		background = Sprite::create("GameClear.png");
	else
		background = Sprite::create("GameOver.png");

	background->setPosition(480, 320);
	this->addChild(background);

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

	nextScene = TransitionClose::create(1.0f, nextScene);

	// 次のシーンに移行
	_director->replaceScene(nextScene);

	return true;
}
