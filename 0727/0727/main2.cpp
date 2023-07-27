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
	Mode�� 2������ ���еȴ�. 
	������ ����ų� �о� ���ų� 
	1�� ����
	w: ������ ���� ����� �ٶ�
	r : ���� ������ �о�ö�
	a : ���������� �о�ͼ� �� �ڿ� ������ �߰����� ��

	2�� ����
	t: �ؽ�Ʈ ���� 
	b: ���̳ʸ� ���� 
	*/

	//fopen_s(&FileStream, ���, Mode );  //��� ���, ���� ��� 
	fopen_s(&FileStream, "Test.txt", "wt");  //��� ���

	if (FileStream)
	{
		//���Ͽ� ���ڸ� �߰��ҋ�
		//fputc : ���� �ϳ��� �߰��� ��
		//fputs : ���ڿ��� �߰��� ��
		fputs("���ڿ� �߰�\n", FileStream);
		fputc('t', FileStream);

		//�۾��� �Ϸ�� ���� ��Ʈ���� ������ �ݾ���� �Ѵ�.
		fclose(FileStream);
	}

	//�б�
	fopen_s(&FileStream, "Test.txt", "rt");  //��� ���

	if (FileStream)
	{
		//���Ͽ� ���ڸ� �߰��ҋ�
		//fgetc : ���� �ϳ��� �о� �ö�
		//fgets : ���ڿ��� �о�� �� �� ���� �о�´�.
		char Text[256] = {};
		fgets(Text,100, FileStream);
		char Text1 = fgetc(FileStream);

		std::cout << Text ;

		//�۾��� �Ϸ�� ���� ��Ʈ���� ������ �ݾ���� �Ѵ�.
		fclose(FileStream);
	}


	int* Num = nullptr;

	//Test(Num);

	Test1(&Num);

	return 0;
}