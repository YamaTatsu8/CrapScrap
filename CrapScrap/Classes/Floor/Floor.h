////////////////
// ��b�̊�� //
////////////////

// �t���A�N���X
#pragma once
#include "cocos2d.h"

#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

//���̍ő吔
const int FLOOR_MAX = (2000);
//�v���X�̍ő吔
const int PRESS_MAX = (40);
//�`�b�v�̍ő吔
const int CHIP_MAX = (3600);
//�d�r�̍ő吔
const int BATTERY_MAX = (4);
//���ƍ����̃`�b�v��
const int WIDTH = (120);
const int HEIGHT = (30);
// �`�b�v�̃T�C�Y
const float CHIP_SIZE = (32.0f);

class Floor :public cocos2d::Layer
{
private:

	//�`�b�v
	int m_Chip[HEIGHT][WIDTH];

	//
	cocos2d::Node* m_pFloorNode;
	//
	cocos2d::Node* m_pPressNode[PRESS_MAX];

	//��
	cocos2d::Sprite* m_pFloor[FLOOR_MAX];
	//�v���X
	cocos2d::Sprite* m_pPress[PRESS_MAX * 3];
	//�h�A
	cocos2d::Sprite* m_pDoor;
	//�d�r
	cocos2d::Sprite* m_pBattery[BATTERY_MAX];
	//�R���x�A
	cocos2d::Sprite* m_pLeftConveyor;
	cocos2d::Sprite* m_pRightConveyor;
	//�G���x�[�^�[
	cocos2d::Sprite* m_pElevator;
	//�S�[��
	cocos2d::Sprite* m_pGoal;
	//�e�X�g
	cocos2d::Sprite* test[32][32];

public:

	CREATE_FUNC(Floor);

	//����������
	bool init();

	// ���t���[���̍X�V����
	void update(float delta) override;
	
	//�v���X����������������
	void Collapse();

	//�}�b�v�̓ǂݍ���
	void importData(std::string fileName);

	//�G���x�[�^�[�̏㏸
	void rising();

	//���̏���
	void FloorCollapse();

	//
	bool isCollision(cocos2d::Rect rect);
};