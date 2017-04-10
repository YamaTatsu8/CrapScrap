//ヘッダファイルの読み込み
#include "HelloWorldScene.h"
#include "TransitionOpen.h"

USING_NS_CC;

TransitionOpen* TransitionOpen::create(float t, Scene* scene)
{
	// トランジションシーンの作成
	TransitionOpen* newScene = new (std::nothrow) TransitionOpen();
	// トランジションシーンの初期化
	if (newScene && newScene->initWithDuration(t, scene))
	{
		// 自動解放マネージャに登録
		newScene->autorelease();
		return newScene;
	}
	// 初期化に失敗した場合、解放してNULLポインタを返す
	CC_SAFE_DELETE(newScene);
	return nullptr;
}

void TransitionOpen::onEnter()
{
	// 基底クラスの処理（タッチ無効化など）
	TransitionScene::onEnter();

	Size s = Director::getInstance()->getWinSize();

	// 前シーンを非表示
	_outScene->setVisible(false);
	
	// タイトル画像 =========================================================
	Sprite* title1 = Sprite::create("Title.png");
	title1->setTextureRect(Rect(0, 0, 960, 430));
	title1->setPosition(WINDOW_W / 2, title1->getContentSize().height);
	this->addChild(title1);
	this->reorderChild(title1, 1);

	Sprite* title2 = Sprite::create("Title.png");
	title2->setTextureRect(Rect(0, 450, 960, 370));
	title2->setPosition(WINDOW_W / 2, title2->getContentSize().height / 2);
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


	// 各種アクションを生成

	//上下に開く
	title1->runAction(MoveBy::create(0.5f, Vec2(0, title1->getContentSize().height)));
	title2->runAction(MoveBy::create(0.5f, Vec2(0, -title2->getContentSize().height)));

	//歯車回る
	gear1->runAction
	(
		Sequence::create
		(
			RotateBy::create(0.5f, 360),
			MoveBy::create(0.25f, Vec2(0, 300)),
			nullptr
		)
	);
	gear2->runAction
	(
		Sequence::create
		(
			RotateBy::create(0.5f, -360),
			MoveBy::create(0.25f, Vec2(0, - 300)),
			nullptr
		)
	);
	 
	//待機
	ActionInterval *delay = DelayTime::create(1.0f);

	// 次シーンへのアクションを実行
	_inScene->runAction
	(
		Sequence::create
		(
			// 待機
			delay,
			// シーン遷移の終了処理
			CallFunc::create(CC_CALLBACK_0(TransitionScene::finish, this)),
			nullptr
		)
	);
}