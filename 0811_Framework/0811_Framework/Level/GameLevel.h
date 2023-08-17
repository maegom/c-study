#pragma once
#include "Level.h"
class CGameLevel :
    public CLevel
{
public:
	CGameLevel();
	virtual ~CGameLevel();

private:
	int		mScore;

public:
	void AddScore(int Score)
	{
		mScore += Score;
	}

public:
	virtual void Init();
	virtual void Render(HDC hDC);
};

