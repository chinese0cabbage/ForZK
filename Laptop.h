#pragma once
#include"Computer.h"
class Laptop :Computer {
public:
	bool IsAbleToAddInternalStorage;
	double weight;//µçÄÔÖØÁ¿
	void AddInternalStorage(int size) {
		this->InternalStorage += size;
	}
	Laptop() :Computer() {

	}
};