#include "Object.h"

CObject::CObject()	:
	mSize(100.f, 100.f),
	mName{},
	mActive(true),
	mMoveSpeed(0.f)
{
}

CObject::CObject(const CObject& Obj)
{
}

CObject::~CObject()
{
}

void CObject::Init()
{
}

void CObject::Input(float DeltaTime)
{
}

void CObject::Update(float DeltaTime)
{
	// �̵� ������ �����Ǿ��� ��� �̵���Ų��.
	// ���� D�� ������ ���������� �̵���Ų�ٰ� ������ ���
	// mMoveDir�� x���� 1, y���� 0�� ���� ���̴�.
	// ���⿡ mMoveSpeed�� ���ϰ� �Ǹ� mMoveSpeed�� 200�̶�� ������ ���
	// 200, 0 �� ������ �� ���̴�.
	// ���⿡ ���ڷ� ���� ��ŸŸ���� �����ְ� �Ǹ� �ʴ� 200��ŭ�� �Ÿ���
	// �̵��ϴ� ���� �ϼ��ȴ�.
	// �ӵ� : 200
	//��ŸŸ��: 1 / 60
	//
	//200 * (1 / 60)
	//��ŸŸ���� 1 / 60 �ʶ�� 200�� 1�ʵ��� �������� 60�� ���ϰ� �ǹǷ� �� �����Ǵ�
	//���� 200 / 60 * 60�� �Ǿ� 200�� ������ �ȴ�.
	mPos += mMoveDir * mMoveSpeed * DeltaTime;
}

void CObject::Collision(float DeltaTime)
{
}

void CObject::Render(HDC hDC)
{
	Rectangle(hDC, (int)mPos.x, (int)mPos.y, (int)(mPos.x + mSize.x),
		(int)(mPos.y + mSize.y));

	mMoveDir.x = 0.f;
	mMoveDir.y = 0.f;
}
