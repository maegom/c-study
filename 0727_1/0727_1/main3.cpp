
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
		// 이름/직업/공격력/방어력 이렇게 저장되어 있다.
		int	Count = 0;

		char	Line[256] = {};
		fgets(Line, 256, FileStream);

		// 문자열에 숫자가 있을 경우 이 숫자를 int로 변경해준다.
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