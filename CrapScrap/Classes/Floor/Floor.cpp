#include "Floor.h"

using namespace cocos2d;
using namespace std;

//������
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
		//0�������ꍇ�\�����Ȃ�
		if (m_Tip[i / 120][i % 120] == 0)
		{

		}
		else if (m_Tip[i / 120][i % 120] == 1)
		{
			//1�������ꍇ����\��
			floor[floorNum] = CCSprite::create("floor.png");
			floor[floorNum]->setPositionX((i % 120)*32.0f);
			floor[floorNum]->setPositionY(960.0f - 32 * (i / 120));

			this->addChild(floor[floorNum]);
			floorNum++;
		}
		else if (m_Tip[i / 120][i % 120] == 2)
		{
			//2�������ꍇ�v���X��\��
			press[i] = CCSprite::create("press.png");
			press[i]->setPositionX((i % 120)*32.0f);
			press[i]->setPositionY(960.0f - 32 * (i / 120));
			this->addChild(press[i]);
		}
		else if (m_Tip[i / 120][i % 120] == 3)
		{
			//3�������ꍇ�h�A��\��
			door = CCSprite::create("door.png");
			door->setPosition((i % 120)*32.0f, 960.0f - 32 * (i / 120));
			this->addChild(door);
		}
		else if (m_Tip[i / 120][i % 120] == 4)
		{
			//4�������ꍇ�d�r��\��
			denti[n] = CCSprite::create("denti.png");
			denti[n]->setPosition(((i % 120)*32.0f), 960 - 32 * (i / 120));
			this->addChild(denti[n]);
			n++;
		}
		else if (m_Tip[i / 120][i % 120] == 5)
		{
			//5�������ꍇ�A�����[���[��\��
			leftConbea = CCSprite::create("conbea.png");
			leftConbea->setPosition(((i % 120)*32.0f), 960 - 32 * (i / 120));
			this->addChild(leftConbea);
		}
		else if (m_Tip[i / 120][i % 120] == 6)
		{
			//6�������ꍇ�A�E���[���[��\��
			rightConbea = CCSprite::create("conbea.png");
			rightConbea->setPosition(((i % 120)*32.0f), 960 - 32 * (i / 120));
			this->addChild(rightConbea);
		}
		else if (m_Tip[i / 120][i % 120] == 7)
		{
			//7�������ꍇ�G���x�[�^�[��\��
			elevator = CCSprite::create("elevator.png");
			elevator->setPosition(((i % 120)*32.0f), 960 - 32 * (i / 120));
			this->addChild(elevator);
		}
		else if (m_Tip[i / 120][i % 120] == 8)
		{
			//�󔒂̂��ߖ���
		}
		else if (m_Tip[i / 120][i % 120] == 9)
		{
			//9�������ꍇ�S�[����\��
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
	// �t�@�C���̃t���p�X���擾
	std::string filePath = FileUtils::getInstance()->fullPathForFilename(fileName);
	ssize_t size;
	// �f�[�^�ǂݍ���
	unsigned char* data = FileUtils::getInstance()->getFileData(filePath, "r", &size);
	// �f�[�^����X�g�����O�X�g���[���쐬
	stringstream ss((char*)data);

	std::string csvLine;

	int i = 0;
	while (getline(ss, csvLine))
	{ // �s���Ƃ̏���
	  // 1�s���̃X�g�����O�X�g���[��
		istringstream csvStream(csvLine);
		std::string csvCol;

		while (getline(csvStream, csvCol, ','))
		{ // �J���}�ŕ���
		  // �����񂩂琔�������o
		  //if (atoi(csvCol.c_str()) != 0)
		  //{
		  //	// �J���}�ŋ�؂�ꂽ�������擾�ł��Ă���
		  //	CCLog("%d", atoi(csvCol.c_str()));
		  //}
			m_Tip[i / 120][i % 120] = atoi(csvCol.c_str());
			i++;
		}
	}

}