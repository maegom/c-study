#include "Store.h"
#include "Item.h"
#include "Inventory.h"
#include "Player.h"
#include "ObjectManager.h"

CStore::CStore()	:
	mItemCount(0),
	mItemArray(nullptr)
{
}

CStore::~CStore()
{
	if (mItemArray)
	{
		delete[] mItemArray;
	}
}

int CStore::Menu()
{
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();

	system("cls");
	for (int i = 0; i < mItemCount; ++i)
	{
		std::cout << i + 1 << ". ";
		mItemArray[i].Output();
		std::cout << std::endl;
	}

	std::cout << mItemCount + 1 << ". 뒤로가기" << std::endl;

	std::cout << "보유금액 : " << Player->GetMoney() << std::endl;

	std::cout << "아이템을 선택하세요 : ";
	int	Input;
	std::cin >> Input;

	if (Input <= 0 ||
		Input > mItemCount + 1)
		return 0;

	return Input;
}

bool CStore::Init(const char* FileName)
{
	FILE* FileStream = nullptr;

	fopen_s(&FileStream, FileName, "rb");

	if (!FileStream)
		return false;

	fread(&mItemCount, sizeof(int), 1, FileStream);

	// 위에서 읽어온 mItemCount는 이 상점에서 판매하는 아이템이 몇개인지를 가져온다.
	// 그러므로 아이템을 저장하기 위한 배열은 멤버변수로 구성되어 있으므로 해당 배열을
	// 위에서 읽어온 아이템의 수량만큼 동적배열로 할당해준다.
	mItemArray = new CItem[mItemCount];

	for (int i = 0; i < mItemCount; ++i)
	{
		mItemArray[i].Init(FileStream);
	}

	fclose(FileStream);

	return true;
}

void CStore::Run()
{
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();
	;
	while (true)
	{
		int Input = Menu();

		if (Input == -1)
			continue;

		else if (Input == mItemCount + 1)
			break;

		int	ItemIndex = Input - 1;

		// 인벤토리에 칸이 부족할 경우 추가할 수 없다.
		if (CInventory::GetInst()->IsFull())
		{
			std::cout << "가방의 공간이 부족합니다." << std::endl;
			system("pause");
			continue;
		}

		// 가지고 있는 돈보다 작은지 판단한다.
		else if (Player->GetMoney() < mItemArray[ItemIndex].GetPrice())
		{
			std::cout << "소지금이 부족합니다." << std::endl;
			system("pause");
			continue;
		}

		// 인벤토리에 아이템을 추가해준다.
		// 구매할 아이템을 복사생성자의 인자에 전달해주어서 인벤토리에 추가하기 위해
		// 새로 생성하는 아이템의 정보를 구매한 아이템의 정보로 그대로 복사해준다.
		CItem* InvenItem = new CItem(mItemArray[ItemIndex]);

		// 인벤토리에 아이템을 추가해준다.
		CInventory::GetInst()->AddItem(InvenItem);

		Player->AddMoney(-InvenItem->GetPrice());
	}
}
