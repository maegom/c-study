
#include "MainMonster.h"
#include "../GameManager.h"
#include "Bullet.h"
#include "GuidedBullet.h"
#include "../Level/LevelManager.h"
#include "../Level/MainLevel.h"

CMainMonster::CMainMonster() :
	mDir(1),
	mAccTime(0.f),
	mCount(0)
{
	// CBullet의 고유한 번호를 저장한다.
	mTypeID = typeid(CMainMonster).hash_code();
}

CMainMonster::CMainMonster(const CMainMonster& Obj) :
	CMonster(Obj)
{
	mDir = Obj.mDir;
}

CMainMonster::~CMainMonster()
{
}

void CMainMonster::Init()
{
	CMonster::Init();

	SetMoveSpeed(300.f);
}

void CMainMonster::Input(float DeltaTime)
{
	CMonster::Input(DeltaTime);

	Move((float)mDir, 0.f);
}

void CMainMonster::Update(float DeltaTime)
{
	CMonster::Update(DeltaTime);

	// GameManager가 가지고 있는 윈도우 크기를 얻어온다.
	Resolution	RS = CGameManager::GetInst()->GetResolution();

	// CObject의 Update에서 이동이 되었을 것이다.
	if (mPos.x + mSize.x >= RS.Width)
	{
		mPos.x = RS.Width - mSize.x;
		mDir = -1;
	}

	else if (mPos.x <= 0.f)
	{
		mPos.x = 0.f;
		mDir = 1;
	}

	// 총알을 발사하기 위해 시간을 누적한다.
	mAccTime += DeltaTime;

	if (mAccTime >= 1.f)
	{
		mAccTime -= 1.f;

		// 총알 카운트
		++mCount;

		CLevel* Level = CLevelManager::GetInst()->GetLevel();

		// 총알이 3번 발사되는건지 판단한다.
		if (mCount == 3)
		{
			mCount = 0;

			// 플레이어를 향하는 방향을 구한다.
			CObject* Player = Level->FindObject("Player");

			Vector2D	Dir;
			Vector2D	BulletPos(mPos.x + mSize.x * 0.5f - 25.f * 0.5f,
				mPos.y + mSize.y + 1.f);

			if (Player)
			{
				Dir = Player->GetPos() + Player->GetSize() * 0.5f - BulletPos;
				Dir.Normalize();
			}

			CGuidedBullet* Bullet = Level->CreateObj<CGuidedBullet>("MonsterBullet");

			Bullet->SetSize(25.f, 25.f);

			Bullet->SetPos(BulletPos);

			Bullet->SetGuidedDir(Dir);
		}

		else
		{
			CBullet* Bullet = Level->CreateObj<CBullet>("MonsterBullet");

			Bullet->SetSize(25.f, 25.f);

			Bullet->SetPos(mPos.x + mSize.x * 0.5f - Bullet->GetSize().x * 0.5f,
				mPos.y + mSize.y + 1.f);

			// 몬스터 총알은 아래로 이동해야 되기 때문에 y값이 점점 커져야 한다.
			Bullet->SetDir(1);
		}
	}
}

void CMainMonster::Collision(float DeltaTime)
{
	CMonster::Collision(DeltaTime);
}

void CMainMonster::Render(HDC hDC)
{
	CMonster::Render(hDC);
}

void CMainMonster::Collision(CObject* Dest)
{
	if (strcmp(Dest->GetName(), "Bullet") != 0)
		return;

	CMainLevel* Level = (CMainLevel*)CLevelManager::GetInst()->GetLevel();

	Level->AddScore(10);
}
