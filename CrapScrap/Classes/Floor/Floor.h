//�@Tatsuya Yamada
// �t���A�N���X
#pragma once
#include "cocos2d.h"

#include<fstream>
#include<iostream>
#include<string>
#include<sstream>

//���̍ő吔
const int FLOOR_MAX = 3600;
//�`�b�v�̍ő吔
const int TIP_MAX = 3600;
//���ƍ����̃`�b�v��
const int WIGHT = 120;
const int HEIGHT = 40;

class Floor:public cocos2d::Layer
{	
private:

	//�`�b�v
	int m_Tip[WIGHT][HEIGHT];

public:

	

	//����������
	bool init();

	//��
	cocos2d::Sprite* floor[FLOOR_MAX];

	//�v���X����������������
	void Collapse(int num);

	//�}�b�v�̓ǂݍ���
	void importData(std::string fileName);

};