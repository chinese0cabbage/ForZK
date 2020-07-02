#pragma once
#include"Company.h"
class Computer
{
public:
	double Price;
	char *Version;
	char *UniqueID;
	Company HostCompany;
	Computer();
	//Computer(char* CPU, char* GPU[], int internal, int memory);
	~Computer();

protected:
	char* CPUVersion[20];
	char* GPUVersion[20];
	int InternalStorage;
	int Memory;
};

Computer::Computer()
{
}

Computer::~Computer()
{
}