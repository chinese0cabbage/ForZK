#pragma once
#include"Desktop.h"
#include"Laptop.h"
class Customer
{
public:
	char* name;
	int* CreditCardNum;
	int* Tel;
	void Buy();
	Customer();
	~Customer();

private:

};

Customer::Customer()
{
}

Customer::~Customer()
{
}