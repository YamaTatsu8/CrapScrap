//�@Tatsuya Yamada
// �t���A�N���X
#pragma once
#include "cocos2d.h"

#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

//���̍ő吔
const int FLOOR_MAX = 2000;
//�v���X�̍ő吔
const int PRESS_MAX = 3600;
//�`�b�v�̍ő吔
const int TIP_MAX = 3600;
//�h�A�̍ő吔
const int DOOR_MAX = 3600;
//�R���x�A�̍ő吔
const int CONBEA_MAX = 3600;
//�d�r�̍ő吔
const int DENTI_MAX = 4;
//���ƍ����̃`�b�v��
const int WIGHT = 120;
const int HEIGHT = 30;

class Floor :public cocos2d::Layer
{
private:

	//�`�b�v
	int m_Tip[HEIGHT][WIGHT];

public:

	CREATE_FUNC(Floor);

	//����������
	bool init();

	//��
	cocos2d::CCSprite* floor[FLOOR_MAX];
	//�v���X
	cocos2d::CCSprite* press[PRESS_MAX];
	//�h�A
	cocos2d::CCSprite* door;
	//�d�r
	cocos2d::CCSprite* denti[DENTI_MAX];
	//�R���x�A
	cocos2d::CCSprite* leftConbea;
	cocos2d::CCSprite* rightConbea;
	//�G���x�[�^�[
	cocos2d::CCSprite* elevator;
	//�S�[��
	cocos2d::CCSprite* goal;

	//�e�X�g
	cocos2d::Sprite* test[32][32];



	//�v���X����������������
	void Collapse(int num);

	//�}�b�v�̓ǂݍ���
	void importData(std::string fileName);

};