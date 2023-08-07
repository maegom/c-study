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
	// ���� ����� �Բ� ���漱���� �ؼ� ������ ������ ����� �� �ִ�.
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

