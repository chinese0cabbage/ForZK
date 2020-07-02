#pragma once
class Company
{
public:
	char name[20];
	char UnifiedSocialCreditCode[30];
	char ComputerUniqueIDs[100][20];
	void Sell();
	Company();
	~Company();

private:

};

Company::Company()
{
}

Company::~Company()
{
}