#include <iostream>

struct Item
{
	char	Name[32];
	int		Price;
	int		Sell;
};

int main() {

	FILE* FileStream = nullptr;

	fopen_s(&FileStream, "TestBinary.ssc", "wb");

	if (FileStream)
	{
		Item	item = {};
		strcpy_s(item.Name, "티켓");
		item.Price = 10000;
		item.Sell = 5000;

		fwrite(&item, sizeof(Item), 1, FileStream);

		fclose(FileStream);
	}

	fopen_s(&FileStream, "TestBinary.ssc", "rb");

	if (FileStream)
	{
		Item	item = {};
		strcpy_s(item.Name, "티켓");
		item.Price = 10000;
		item.Sell = 5000;

		fread(&item, sizeof(Item), 1, FileStream);

		fclose(FileStream);
	}

	return 0;
}