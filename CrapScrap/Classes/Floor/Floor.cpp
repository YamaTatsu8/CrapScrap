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
			floor[floorNum] = CCSprite::create("floor.png");
			floor[floorNum]->setPositionX((i % 120)*32.0f);
			floor[floorNum]->setPositionY(960.0f - 32 * (i / 120));

			this->addChild(floor[floorNum]);
			floorNum++;
		}
		else if (m_Tip[i / 120][i % 120] == 2)
		{
			//2だった場合プレスを表示
			press[i] = CCSprite::create("press.png");
			press[i]->setPositionX((i % 120)*32.0f);
			press[i]->setPositionY(960.0f - 32 * (i / 120));
			this->addChild(press[i]);
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

void Floor::Collapse(int num)
{

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