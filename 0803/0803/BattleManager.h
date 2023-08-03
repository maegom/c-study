#pragma once

#include "Info.h"

enum class EBattleLevelMenu
{
	None,
	Easy,
	Normal,
	Hard,
	Back
};

/*
Ŭ���� ���漱�� : ���� Ŭ������ ������ �ִ� ������Ͽ� ���� include ���� ���������� ����� �� �ְ�
���ִ� ����̴�.
include ���� �� �� �ֱ� ������ ����� ��ȯ������ ������ �� �ִ�.
Ư�� Ŭ������ �ִ� ��� ������ ���ְ� �ش� Ÿ���� ������ Ÿ�� ������ ������ ������ ���·� 
������ִ� ���̴�.
*/

class CBattle;
class CBattleManager
{
private:
	CBattleManager();
	~CBattleManager();

private:
	static CBattleManager* mInst;

public:
	static CBattleManager* GetInst()
	{
		if (nullptr == mInst)
			mInst = new CBattleManager;

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
	CBattle* mBattle[3];

private:
	EBattleLevelMenu Menu();

public:
	bool Init();
	void Run();
};

