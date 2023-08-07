#pragma once

#include "Info.h"

class CStore
{
public:
	CStore();
	~CStore();

private:
	CArray<class CItem*>	mItemArray;

private:
	int Menu();

public:
	bool Init(const char* FileName);
	void Run();
};

