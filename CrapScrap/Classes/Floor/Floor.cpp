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

			//2�������ꍇ�v���X��\��
			press[i] = CCSprite::create("press.png");
			press[i]->setPositionX((i % 120)*32.0f);
			press[i]->setPositionY(960.0f - 32 * (i / 120));
			m_floor[i]->addChild(press[i]);
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

//�v���X�@�������Ă���
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

//���̏���
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

	//��`�ǂ����̓����蔻��
	bool hit = rect_floor[i].intersectsRect(rect_press[i]);

	//���������ꍇ
	if (hit)
	{
		floor[i]->setVisible(false);

		Point pos(floor[i]->getPosition());

		ParticleSystemQuad* pSys;

		//�p�[�e�B�N���̎w��(plist�t�@�C���ǂݍ���)
		pSys = ParticleSystemQuad::create("particle_texture.plist");

		//���W�w��
		pSys->setPosition(pos);

		//�Đ���ɍ폜����ݒ�
		pSys->setAutoRemoveOnFinish(true);

		this->addChild(pSys);

	}


}

//�G���x�[�^�̏㏸
void Floor::rising()
{
	//3�b�����Ă����㏸����
	MoveBy* rising = MoveBy::create(3, Vec2(0, 400));

	elevator->runAction(rising);

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