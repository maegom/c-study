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
클래스 전방선언 : 실제 클래스를 가지고 있는 헤더파일에 대해 include 없이 제한적으로 사용할 수 있게
해주는 기능이다.
include 없이 할 수 있기 때문에 헤더의 순환참조를 막아줄 수 있다.
특정 클래스가 있다 라고 가정을 해주고 해당 타입의 포인터 타입 변수만 선언이 가능한 형태로 
만들어주는 것이다.
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

