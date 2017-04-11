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

	m_pFloorNode = Node::create();
	this->addChild(m_pFloorNode);

	for (int i = 0; i < PRESS_MAX; i++)
	{
		m_pPressNode[i] = Node::create();
		this->addChild(m_pPressNode[i]);
	}

	for (int i = 0; i < CHIP_MAX; i++)
	{
		switch (m_Chip[i / 120][i % 120])
		{
		case 1:
			//1�������ꍇ����\������������
			m_pFloor[floorNum] = Sprite::create("floor.png");
			m_pFloor[floorNum]->setPosition((i % WIDTH)* CHIP_SIZE + CHIP_SIZE / 2.0f, 960.0f - CHIP_SIZE * (i / WIDTH) - CHIP_SIZE / 2.0f);
			m_pFloorNode->addChild(m_pFloor[floorNum]);
			floorNum++;
			break;
		case 2:
			//2�������ꍇ�v���X��\���ő�
			m_pPress[pressNum] = Sprite::create("press.png");
			m_pPress[pressNum]->setPosition((i % WIDTH)* CHIP_SIZE + CHIP_SIZE / 2.0f - 0.1f, 960.0f - CHIP_SIZE * (i / WIDTH) - CHIP_SIZE / 2.0f);
			m_pPressNode[pressNum / 3]->addChild(m_pPress[pressNum]);
			pressNum++;
			break;
		case 3:
			//3�������ꍇ�h�A��\��wwww
			m_pDoor = Sprite::create("door.png");
			m_pDoor->setPosition((i % WIDTH)* CHIP_SIZE + CHIP_SIZE / 2.0f, 960.0f - CHIP_SIZE * (i / WIDTH) - CHIP_SIZE / 2.0f);
			this->addChild(m_pDoor);
			break;
		case 4:
			//4�������ꍇ�d�r��\��w
			m_pBattery[dentiNum] = Sprite::create("denti.png");
			m_pBattery[dentiNum]->setPosition(((i % WIDTH)* CHIP_SIZE) + CHIP_SIZE / 2.0f, 960 - CHIP_SIZE * (i / WIDTH) - CHIP_SIZE / 2.0f);
			this->addChild(m_pBattery[dentiNum]);
			dentiNum++;
			break;
		case 5:
			//5�������ꍇ�A�����[���[��\�����Ăق���
			m_pLeftConveyor = Sprite::create("conbea.png");
			m_pLeftConveyor->setPosition(((i % WIDTH)* CHIP_SIZE) + CHIP_SIZE / 2.0f, 960 - CHIP_SIZE * (i / WIDTH) - CHIP_SIZE / 2.0f);
			this->addChild(m_pLeftConveyor);
			break;
		case 6:
			//6�������ꍇ�A�E���[���[��\���ł���
			m_pRightConveyor = Sprite::create("conbea.png");
			m_pRightConveyor->setPosition(((i % WIDTH)* CHIP_SIZE) + CHIP_SIZE / 2.0f, 960 - CHIP_SIZE * (i / WIDTH) - CHIP_SIZE / 2.0f);
			this->addChild(m_pRightConveyor);
			break;
		case 7:
			//7�������ꍇ�G���x�[�^�[��\���ł���
			m_pElevator = Sprite::create("elevator.png");
			m_pElevator->setPosition(((i % WIDTH)* CHIP_SIZE) + CHIP_SIZE / 2.0f, 960 - CHIP_SIZE * (i / WIDTH) - CHIP_SIZE / 2.0f);
			this->addChild(m_pElevator);
			break;
		case 9:
			//9�������ꍇ�S�[����\��������
			m_pGoal = Sprite::create("goal.png");
			m_pGoal->setPosition(((i % WIDTH)* CHIP_SIZE) + CHIP_SIZE / 2.0f, 960 - CHIP_SIZE * (i / WIDTH) - CHIP_SIZE / 2.0f);
			this->addChild(m_pGoal);
			break;
		default:
			break;
		}
	}
	scheduleUpdate();

	return true;
}

void Floor::update(float delta)
{
	FloorCollapse();
}

//�v���X�@�������Ă���
void Floor::Collapse()
{
	static int n = 0;
	MoveBy* down = MoveBy::create(0.7f, Vec2(0, -960 + CHIP_SIZE));
	MoveBy* up = MoveBy::create(0.7f, Vec2(0, 960 - CHIP_SIZE));

	m_pPress[n]->runAction(Sequence::create(down, DelayTime::create(0.1f) , up, nullptr));
	n++;
}

//���{�n���q�̏���
void Floor::FloorCollapse()
{
	int i = 0;
	Rect rect_floor[FLOOR_MAX];
	Rect rect_press[PRESS_MAX * 3];

	Node* parent;
	parent = m_pFloorNode->getParent();
	for (i = 0; i < FLOOR_MAX; i++)
	{
		if (m_pFloor[i] != nullptr)
		{
			rect_floor[i] = m_pFloor[i]->getBoundingBox();
			rect_floor[i] = RectApplyAffineTransform(rect_floor[i], parent->getNodeToWorldAffineTransform());
		}
	}
	for (int i = 0; i < PRESS_MAX; i++)
	{
		parent = m_pPressNode[i]->getParent();
		for (int j = 0; j < 3; j++)
		{
			rect_press[j + i * 3] = m_pPress[j + i * 3]->getBoundingBox();
			rect_press[j + i * 3] = RectApplyAffineTransform(rect_press[j + i * 3], parent->getNodeToWorldAffineTransform());
		}
	}

	for (int i = 0; i < FLOOR_MAX; i++)
	{
		for (int j = 0; j < PRESS_MAX; j++)
		{
			if (m_pFloor[i] != nullptr)
			{
				//��`�ǂ����̓����蔻��
				bool hit = rect_floor[i].intersectsRect(rect_press[j]);
				//���������ꍇ
				if (hit)
				{
					m_pFloor[i]->setVisible(false);

					//Point pos(m_pFloor[i]->getPosition());

					//ParticleSystemQuad* pSys;

					////�p�[�e�B�N���̎w��(plist�t�@�C���ǂݍ���)
					//pSys = ParticleSystemQuad::create("particle_texture.plist");

					////���W�w��
					//pSys->setPosition(pos);

					////�Đ���ɍ폜����ݒ�
					//pSys->setAutoRemoveOnFinish(true);

					//this->addChild(pSys);
				}
			}
		}
	}
}

bool Floor::isCollision(cocos2d::Rect rect)
{
	for (int i = 0; i < FLOOR_MAX; i++)
	{
		if (m_pFloor[i] != nullptr)
		{
			Rect floorRect = m_pFloor[i]->getBoundingBox();
			if (floorRect.intersectsRect(rect))
				return true;
		}
	}
	return false;
}

//�G���x�[�^���e���グ�̂Ƃ��Ƀo�C�u�X��������
void Floor::rising()
{
	// �㏸����A�N�V����
	MoveBy* rising = MoveBy::create(3, Vec2(0, 400));

	m_pElevator->runAction(rising);

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