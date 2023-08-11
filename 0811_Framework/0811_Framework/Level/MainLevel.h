#pragma once

#include "Level.h"

class CMainLevel :
	public CLevel
{
public:
	CMainLevel();
	virtual ~CMainLevel();

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

