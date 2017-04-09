#include "Floor.h"

using namespace cocos2d;
using namespace std;

//初期化
bool Floor::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto file = FileUtils::getInstance()->fullPathForFilename("ScrapMap.csv");

	importData(file);

	int n = 0;
	int floorNum = 0;

	for (int i = 0; i < TIP_MAX; i++)
	{
		//0だった場合表示しない
		if (m_Tip[i / 120][i % 120] == 0)
		{

		}
		else if (m_Tip[i / 120][i % 120] == 1)
		{
			//1だった場合床を表示
			m_floor[floorNum] = Node::create();
			m_floor[floorNum]->setPosition((i % 120)*32.0f, 960.0f - 32 * (i / 120));
			this->addChild(m_floor[floorNum]);

			floor[floorNum] = CCSprite::create("floor.png");
			floor[floorNum]->setPositionX((i % 120)*32.0f);
			floor[floorNum]->setPositionY(960.0f - 32 * (i / 120));

			m_floor[floorNum]->addChild(floor[floorNum]);
			floorNum++;
		}
		else if (m_Tip[i / 120][i % 120] == 2)
		{
			m_press[i] = Node::create();
			m_press[i]->setPosition((i % 120)*32.0f, 960.0f - 32 * (i / 120));
			this->addChild(m_press[i]);

			//2だった場合プレスを表示
			press[i] = CCSprite::create("press.png");
			press[i]->setPositionX((i % 120)*32.0f);
			press[i]->setPositionY(960.0f - 32 * (i / 120));
			m_floor[i]->addChild(press[i]);
		}
		else if (m_Tip[i / 120][i % 120] == 3)
		{
			//3だった場合ドアを表示
			door = CCSprite::create("door.png");
			door->setPosition((i % 120)*32.0f, 960.0f - 32 * (i / 120));
			this->addChild(door);
		}
		else if (m_Tip[i / 120][i % 120] == 4)
		{
			//4だった場合電池を表示
			denti[n] = CCSprite::create("denti.png");
			denti[n]->setPosition(((i % 120)*32.0f), 960 - 32 * (i / 120));
			this->addChild(denti[n]);
			n++;
		}
		else if (m_Tip[i / 120][i % 120] == 5)
		{
			//5だった場合、左ローラーを表示
			leftConbea = CCSprite::create("conbea.png");
			leftConbea->setPosition(((i % 120)*32.0f), 960 - 32 * (i / 120));
			this->addChild(leftConbea);
		}
		else if (m_Tip[i / 120][i % 120] == 6)
		{
			//6だった場合、右ローラーを表示
			rightConbea = CCSprite::create("conbea.png");
			rightConbea->setPosition(((i % 120)*32.0f), 960 - 32 * (i / 120));
			this->addChild(rightConbea);
		}
		else if (m_Tip[i / 120][i % 120] == 7)
		{
			//7だった場合エレベーターを表示
			elevator = CCSprite::create("elevator.png");
			elevator->setPosition(((i % 120)*32.0f), 960 - 32 * (i / 120));
			this->addChild(elevator);
		}
		else if (m_Tip[i / 120][i % 120] == 8)
		{
			//空白のため無し
		}
		else if (m_Tip[i / 120][i % 120] == 9)
		{
			//9だった場合ゴールを表示
			goal = CCSprite::create("goal.png");
			goal->setPosition(((i % 120)*32.0f), 960 - 32 * (i / 120));
			this->addChild(goal);
		}
	}


	return true;
}

//プレス機が落ちてくる
void Floor::Collapse(int num)
{
	int i = 0;

	for (i = 0; i < PRESS_MAX; i++)
	{
		press[i];
	}

	MoveBy* down = MoveBy::create(10.0f, Vec2(0, 960));

	press[i]->runAction(down);
}

//床の消失
void Floor::FloorCollapse()
{
	int i = 0;
	Rect rect_floor[FLOOR_MAX];
	Rect rect_press[PRESS_MAX];

	for ( i = 0; i < FLOOR_MAX; i++)
	{
		rect_floor[i] = floor[i]->getBoundingBox();
	}
	for ( i = 0; i < PRESS_MAX; i++)
	{
		rect_press[i] = press[i]->getBoundingBox();
	}

	Node* parent[2000];
	parent[i] = m_floor[i]->getParent();
	rect_floor[i] = RectApplyAffineTransform(rect_floor[i], parent[i]->getNodeToWorldAffineTransform());
	
	parent[i] = m_press[i]->getParent();
	rect_press[i] = RectApplyAffineTransform(rect_press[i], parent[i]->getNodeToWorldAffineTransform());

	//矩形どうしの当たり判定
	bool hit = rect_floor[i].intersectsRect(rect_press[i]);

	//当たった場合
	if (hit)
	{
		floor[i]->setVisible(false);

		Point pos(floor[i]->getPosition());

		ParticleSystemQuad* pSys;

		//パーティクルの指定(plistファイル読み込み)
		pSys = ParticleSystemQuad::create("particle_texture.plist");

		//座標指定
		pSys->setPosition(pos);

		//再生後に削除する設定
		pSys->setAutoRemoveOnFinish(true);

		this->addChild(pSys);

	}


}

//エレベータの上昇
void Floor::rising()
{
	//3秒かけてｙ分上昇する
	MoveBy* rising = MoveBy::create(3, Vec2(0, 400));

	elevator->runAction(rising);

}

void Floor::importData(std::string fileName)
{
	// ファイルのフルパスを取得
	std::string filePath = FileUtils::getInstance()->fullPathForFilename(fileName);
	ssize_t size;
	// データ読み込み
	unsigned char* data = FileUtils::getInstance()->getFileData(filePath, "r", &size);
	// データからストリングストリーム作成
	stringstream ss((char*)data);

	std::string csvLine;

	int i = 0;
	while (getline(ss, csvLine))
	{ // 行ごとの処理
	  // 1行分のストリングストリーム
		istringstream csvStream(csvLine);
		std::string csvCol;

		while (getline(csvStream, csvCol, ','))
		{ // カンマで分割
		  // 文字列から数字を検出
		  //if (atoi(csvCol.c_str()) != 0)
		  //{
		  //	// カンマで区切られた数字が取得できている
		  //	CCLog("%d", atoi(csvCol.c_str()));
		  //}
			m_Tip[i / 120][i % 120] = atoi(csvCol.c_str());
			i++;
		}
	}

}