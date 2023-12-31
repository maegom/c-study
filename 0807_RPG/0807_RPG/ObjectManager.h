#pragma once

#include "Info.h"

class CObjectManager
{
private:
	CObjectManager();
	~CObjectManager();

private:
	static CObjectManager* mInst;

public:
	static CObjectManager* GetInst()
	{
		if (nullptr == mInst)
			mInst = new CObjectManager;

		return mInst;
	}

	static void DestroyInst()
	{
		if (nullptr != mInst)
		{
			delete mInst;
			mInst = nullptr;
		}
	}

private:
	// 변수 선언과 함께 전방선언을 해서 포인터 변수를 사용할 수 있다.
	class CPlayer* mPlayer;

public:
	CPlayer* GetPlayer()
	{
		return mPlayer;
	}

public:
	bool Init();
	class CMonster* CreateMonster(EBattleType Type);
};

