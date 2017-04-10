//ヘッダファイルの読み込み
#include "HelloWorldScene.h"
#include "TransitionClose.h"

USING_NS_CC;

TransitionClose* TransitionClose::create(float t, Scene* scene)
{
	// トランジションシーンの作成
	TransitionClose* newScene = new (std::nothrow) TransitionClose();
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

void TransitionClose::onEnter()
{
	// 基底クラスの処理（タッチ無効化など）
	TransitionScene::onEnter();

	Size s = Director::getInstance()->getWinSize();

	// 次シーンを非表示
	_inScene->setVisible(false);

	// タイトル画像 =========================================================
	Sprite* title1 = Sprite::create("Title.png");
	title1->setTextureRect(Rect(0, 0, 960, 430));
	title1->setPosition(WINDOW_W / 2, WINDOW_H + title1->getContentSize().height/2);
	this->addChild(title1);
	this->reorderChild(title1, 1);

	Sprite* title2 = Sprite::create("Title.png");
	title2->setTextureRect(Rect(0, 450, 960, 370));
	title2->setPosition(WINDOW_W / 2, 0 - title2->getContentSize().height / 2);
	this->addChild(title2);

	// 歯車 =================================================================
	Sprite* gear1 = Sprite::create("Title.png");
	gear1->setTextureRect(Rect(0, 832, 128, 128));
	gear1->setScale(2.0f);
	gear1->setPosition(0, 900);
	this->addChild(gear1, 2);

	Sprite* gear2 = Sprite::create("Title.png");
	gear2->setTextureRect(Rect(0, 832, 128, 128));
	gear2->setScale(3.5f);
	gear2->setPosition(800, -270);
	this->addChild(gear2, 2);


	// 各種アクションを生成

	//上下から閉じる
	title1->runAction
	(
		Sequence::create
		(
			DelayTime::create(0.25f),
			MoveBy::create(0.5f, Vec2(0, -title1->getContentSize().height)),
			nullptr
		)
	);
	title2->runAction
	(
		Sequence::create
		(
			DelayTime::create(0.25f),
			MoveBy::create(0.5f, Vec2(0, title2->getContentSize().height)),
			nullptr
		)
	);

	//歯車回る
	gear1->runAction
	(
		Sequence::create
		(
			MoveBy::create(0.25f, Vec2(0, -300)),
			RotateBy::create(0.5f, -360),
			nullptr
		)
	);
	gear2->runAction
	(
		Sequence::create
		(
			MoveBy::create(0.25f, Vec2(0, 300)),
			RotateBy::create(0.5f, 360),
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