
#include <iostream>

struct Player
{
	char	Name[32];
	char	Job[32];
	int		Attack;
	int		Armor;
};

int main()
{
	FILE* FileStream = nullptr;

	fopen_s(&FileStream, "PlayerInfo.txt", "rt");

	if (FileStream)
	{
		// �̸�/����/���ݷ�/���� �̷��� ����Ǿ� �ִ�.
		int	Count = 0;

		char	Line[256] = {};
		fgets(Line, 256, FileStream);

		// ���ڿ��� ���ڰ� ���� ��� �� ���ڸ� int�� �������ش�.
		Count = atoi(Line);

		fgets(Line, 256, FileStream);
		std::cout << Line;

		for (int i = 0; i < Count; ++i)
		{
			fgets(Line, 256, FileStream);

			Player	player = {};
			//std::cout << Line;
			char* Context = nullptr;
			char* Result = strtok_s(Line, "/", &Context);

			std::cout << Result << "\t";

			strcpy_s(player.Name, Result);

			Result = strtok_s(nullptr, "/", &Context);

			std::cout << Result << "\t";

			strcpy_s(player.Job, Result);

			Result = strtok_s(nullptr, "/", &Context);

			std::cout << Result << "\t";

			std::cout << Context;

			player.Attack = atoi(Result);
			player.Armor = atoi(Context);
		}

		fclose(FileStream);
	}

	return 0;
}