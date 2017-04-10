//�@Tatsuya Yamada
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
const int DENTI_MAX = (4);
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
	cocos2d::Node* m_floor;
	//
	cocos2d::Node* m_press[PRESS_MAX];

	//��
	cocos2d::Sprite* floor[FLOOR_MAX];
	//�v���X
	cocos2d::Sprite* press[PRESS_MAX * 3];
	//�h�A
	cocos2d::Sprite* door;
	//�d�r
	cocos2d::Sprite* denti[DENTI_MAX];
	//�R���x�A
	cocos2d::Sprite* leftConbea;
	cocos2d::Sprite* rightConbea;
	//�G���x�[�^�[
	cocos2d::Sprite* elevator;
	//�S�[��
	cocos2d::Sprite* goal;
	//�e�X�g
	cocos2d::Sprite* test[32][32];

public:

	CREATE_FUNC(Floor);

	//����������
	bool init();

	//�v���X����������������
	void Collapse();

	//�}�b�v�̓ǂݍ���
	void importData(std::string fileName);

	//�G���x�[�^�[�̏㏸
	void rising();

	//���̏���
	void FloorCollapse();

};