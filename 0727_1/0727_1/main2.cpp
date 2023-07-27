
#include <iostream>

void Test(int* Pointer)
{
	Pointer = new int;
}

void Test1(int** Pointer)
{
	*Pointer = new int;
}

int main()
{
	/*
	��������� : ������ ����� �о���� ���� ����̴�.
	C��� ��İ� C++����� �����ȴ�.
	*/
	FILE* FileStream = nullptr;

	/*
	fopen_s���� Mode�� 2���� �κ����� ���еȴ�.
	2���� ���ĺ� �������� ó���ȴ�.
	1�� ����
	w : ������ ���� ������ٶ�
	r : ���� ������ �о�ö�
	a : ���� ������ �о�ͼ� �� �ڿ� ������ �߰����� ��

	2�� ����
	t : �ؽ�Ʈ ����
	b : ���̳ʸ� ����
	*/
	fopen_s(&FileStream, "Test.txt", "wt");
	
	if (FileStream)
	{
		// ���Ͽ� ���ڸ� �߰��Ҷ�
		// fputc : ���� �ϳ��� �߰��� ��
		// fputs : ���ڿ��� �߰��� ��
		fputs("���ڿ� �߰�\n", FileStream);
		fputc('T', FileStream);


		// �۾��� �Ϸ�� ���� ��Ʈ���� ������ �ݾ���� �Ѵ�.
		fclose(FileStream);
	}

	fopen_s(&FileStream, "Test.txt", "rt");

	if (FileStream)
	{
		// ���Ͽ� ���ڸ� �߰��Ҷ�
		// fgetc : ���� �ϳ��� �о�� ��
		// fgets : ���ڿ��� �о�� �� �� ���� �о�´�.
		//fputs("���ڿ� �߰�\n", FileStream);
		//fputc('T', FileStream);
		char	Text[256] = {};
		fgets(Text, 256, FileStream);

		std::cout << Text;

		char Text1 = fgetc(FileStream);

		std::cout << Text1 << std::endl;


		// �۾��� �Ϸ�� ���� ��Ʈ���� ������ �ݾ���� �Ѵ�.
		fclose(FileStream);
	}

	int* Num = nullptr;

	//Test(Num);

	Test1(&Num);

	return 0;
}
