#pragma once
#include"Computer.h"
class Desktop:Computer
{
public:
	double ATXSize[3];//����ߴ�
	Desktop();
	~Desktop();

private:

};

Desktop::Desktop():Computer()
{
}

Desktop::~Desktop()
{
}