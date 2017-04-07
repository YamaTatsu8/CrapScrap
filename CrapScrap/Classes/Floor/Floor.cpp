#include "Floor.h"

using namespace cocos2d;
using namespace std;


bool Floor::init()
{
	importData("ScrapMap.csv");


	for (int i = 0; i < TIP_MAX; i++)
	{
		if (m_Tip[i / 120][i % 40])
		{
			floor[i] = Sprite::create("floor.png");
		}
	}
	return false;
}

void Floor::Collapse(int num)
{

}

void Floor::importData(std::string fileName)
{


}



