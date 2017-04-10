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

	int floorNum = 0;
	int pressNum = 0;
	int dentiNum = 0;

	m_floor = Node::create();
	this->addChild(m_floor);

	for (int i = 0; i < PRESS_MAX; i++)
	{
		m_press[i] = Node::create();
		this->addChild(m_press[i]);
	}

	for (int i = 0; i < CHIP_MAX; i++)
	{
		switch (m_Chip[i / 120][i % 120])
		{
		case 1:
			//1�������ꍇ����\��
			floor[floorNum] = Sprite::create("floor.png");
			floor[floorNum]->setPosition((i % WIDTH)* CHIP_SIZE + CHIP_SIZE / 2.0f, 960.0f - CHIP_SIZE * (i / WIDTH) - CHIP_SIZE / 2.0f);
			m_floor->addChild(floor[floorNum]);
			floorNum++;
			break;
		case 2:
			//2�������ꍇ�v���X��\��
			press[pressNum] = Sprite::create("press.png");
			press[pressNum]->setPosition((i % WIDTH)* CHIP_SIZE + CHIP_SIZE / 2.0f, 960.0f - CHIP_SIZE * (i / WIDTH) - CHIP_SIZE / 2.0f);
			m_press[pressNum / 3]->addChild(press[pressNum]);
			pressNum++;
			break;
		case 3:
			//3�������ꍇ�h�A��\��
			door = Sprite::create("door.png");
			door->setPosition((i % WIDTH)* CHIP_SIZE + CHIP_SIZE / 2.0f, 960.0f - CHIP_SIZE * (i / WIDTH) - CHIP_SIZE / 2.0f);
			this->addChild(door);
			break;
		case 4:
			//4�������ꍇ�d�r��\��
			denti[dentiNum] = Sprite::create("denti.png");
			denti[dentiNum]->setPosition(((i % WIDTH)* CHIP_SIZE) + CHIP_SIZE / 2.0f, 960 - CHIP_SIZE * (i / WIDTH) - CHIP_SIZE / 2.0f);
			this->addChild(denti[dentiNum]);
			dentiNum++;
			break;
		case 5:
			//5�������ꍇ�A�����[���[��\��
			leftConbea = Sprite::create("conbea.png");
			leftConbea->setPosition(((i % WIDTH)* CHIP_SIZE) + CHIP_SIZE / 2.0f, 960 - CHIP_SIZE * (i / WIDTH) - CHIP_SIZE / 2.0f);
			this->addChild(leftConbea);
			break;
		case 6:
			//6�������ꍇ�A�E���[���[��\��
			rightConbea = Sprite::create("conbea.png");
			rightConbea->setPosition(((i % WIDTH)* CHIP_SIZE) + CHIP_SIZE / 2.0f, 960 - CHIP_SIZE * (i / WIDTH) - CHIP_SIZE / 2.0f);
			this->addChild(rightConbea);
			break;
		case 7:
			//7�������ꍇ�G���x�[�^�[��\��
			elevator = Sprite::create("elevator.png");
			elevator->setPosition(((i % WIDTH)* CHIP_SIZE) + CHIP_SIZE / 2.0f, 960 - CHIP_SIZE * (i / WIDTH) - CHIP_SIZE / 2.0f);
			this->addChild(elevator);
			break;
		case 9:
			//9�������ꍇ�S�[����\��
			goal = Sprite::create("goal.png");
			goal->setPosition(((i % WIDTH)* CHIP_SIZE) + CHIP_SIZE / 2.0f, 960 - CHIP_SIZE * (i / WIDTH) - CHIP_SIZE / 2.0f);
			this->addChild(goal);
			break;
		default:
			break;
		}
		/*
		if (m_Chip[i / 120][i % 120] == 0)
		{

		}
		else if (m_Chip[i / 120][i % 120] == 1)
		{
			//1�������ꍇ����\��
			floor[floorNum] = CCSprite::create("floor.png");
			floor[floorNum]->setPositionX((i % 120)* CHIP_SIZE + CHIP_SIZE / 2.0f);
			floor[floorNum]->setPositionY(960.0f - CHIP_SIZE * (i / 120) - CHIP_SIZE / 2.0f);

			m_floor->addChild(floor[floorNum]);
			floorNum++;
		}
		else if (m_Chip[i / 120][i % 120] == 2)
		{
			//2�������ꍇ�v���X��\��
			press[i] = CCSprite::create("press.png");
			press[i]->setPositionX((i % 120)* CHIP_SIZE + CHIP_SIZE / 2.0f);
			press[i]->setPositionY(960.0f - CHIP_SIZE * (i / 120) - CHIP_SIZE / 2.0f);
			m_press->addChild(press[i]);
		}
		else if (m_Chip[i / 120][i % 120] == 3)
		{
			//3�������ꍇ�h�A��\��
			door = CCSprite::create("door.png");
			door->setPosition((i % 120)* CHIP_SIZE + CHIP_SIZE / 2.0f, 960.0f - CHIP_SIZE * (i / 120) - CHIP_SIZE / 2.0f);
			this->addChild(door);
		}
		else if (m_Chip[i / 120][i % 120] == 4)
		{
			//4�������ꍇ�d�r��\��
			denti[n] = CCSprite::create("denti.png");
			denti[n]->setPosition(((i % 120)* CHIP_SIZE) + CHIP_SIZE / 2.0f, 960 - CHIP_SIZE * (i / 120) - CHIP_SIZE / 2.0f);
			this->addChild(denti[n]);
			n++;
		}
		else if (m_Chip[i / 120][i % 120] == 5)
		{
			//5�������ꍇ�A�����[���[��\��
			leftConbea = CCSprite::create("conbea.png");
			leftConbea->setPosition(((i % 120)* CHIP_SIZE) + CHIP_SIZE / 2.0f, 960 - CHIP_SIZE * (i / 120) - CHIP_SIZE / 2.0f);
			this->addChild(leftConbea);
		}
		else if (m_Chip[i / 120][i % 120] == 6)
		{
			//6�������ꍇ�A�E���[���[��\��
			rightConbea = CCSprite::create("conbea.png");
			rightConbea->setPosition(((i % 120)* CHIP_SIZE) + CHIP_SIZE / 2.0f, 960 - CHIP_SIZE * (i / 120) - CHIP_SIZE / 2.0f);
			this->addChild(rightConbea);
		}
		else if (m_Chip[i / 120][i % 120] == 7)
		{
			//7�������ꍇ�G���x�[�^�[��\��
			elevator = CCSprite::create("elevator.png");
			elevator->setPosition(((i % 120)* CHIP_SIZE) + CHIP_SIZE / 2.0f, 960 - CHIP_SIZE * (i / 120) - CHIP_SIZE / 2.0f);
			this->addChild(elevator);
		}
		else if (m_Chip[i / 120][i % 120] == 8)
		{
			//�󔒂̂��ߖ���
		}
		else if (m_Chip[i / 120][i % 120] == 9)
		{
			//9�������ꍇ�S�[����\��
			goal = CCSprite::create("goal.png");
			goal->setPosition(((i % 120)* CHIP_SIZE) + CHIP_SIZE / 2.0f, 960 - CHIP_SIZE * (i / 120) - CHIP_SIZE / 2.0f);
			this->addChild(goal);
		}
		*/
	}


	return true;
}

//�v���X�@�������Ă���
void Floor::Collapse()
{
	static int n = 0;
	MoveBy* down = MoveBy::create(0.7f, Vec2(0, -960 + CHIP_SIZE));
	MoveBy* up = MoveBy::create(0.7f, Vec2(0, 960 - CHIP_SIZE));

	m_press[n]->runAction(Sequence::create(down, DelayTime::create(0.1f) , up, nullptr));
	n++;
}

//���̏���
void Floor::FloorCollapse()
{
	int i = 0;
	Rect rect_floor[FLOOR_MAX];
	Rect rect_press[PRESS_MAX * 3];

	Node* parent;
	parent = m_floor->getParent();
	for ( i = 0; i < FLOOR_MAX; i++)
	{
		rect_floor[i] = floor[i]->getBoundingBox();
		rect_floor[i] = RectApplyAffineTransform(rect_floor[i], parent->getNodeToWorldAffineTransform());
	}
	for (int i = 0; i < PRESS_MAX; i++)
	{
		parent = m_press[i]->getParent();
		for (int j = 0; j < PRESS_MAX * 3; i++)
		{
			rect_press[j] = press[j]->getBoundingBox();
			rect_press[j] = RectApplyAffineTransform(rect_press[j], parent->getNodeToWorldAffineTransform());
		}
	}
	

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
	// �㏸����A�N�V����
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
	{ 
		// �s���Ƃ̏���
		// 1�s���̃X�g�����O�X�g���[��
		istringstream csvStream(csvLine);
		std::string csvCol;

		while (getline(csvStream, csvCol, ','))
		{
			m_Chip[i / 120][i % 120] = atoi(csvCol.c_str());
			i++;
		}
	}

}