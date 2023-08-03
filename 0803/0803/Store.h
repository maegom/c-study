#pragma once

#include "Info.h"

class CStore
{
public:
	CStore();
	~CStore();

private:
	class CItem* mItemArray;
	int			mItemCount;

private:
	int Menu();

public:
	bool Init(const char* FileName);
	void Run();
};

