#include <iostream>

//���� �����
int main()
{
	// ���� �ּ� ����
	FILE* FileStream = nullptr;

	// ���� �ҷ�����(����*, �б�, ����)
	fopen_s(&FileStream, "Test.txt", "wt");
	//(�ּ�      , "���ϸ�" , "���");
/* ���� 2���� �����̴�.

1�� ����
w : ������ ���� ������ٶ�
r : ���� ������ �о�ö�
a : ���� ������ �о�ͼ� �� �ڿ� ������ �߰����� ��

2�� ����
t : �ؽ�Ʈ ����
b : ���̳ʸ� ����
*/

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

	// ���� �ҷ�����(����, �б�*, ����)
	fopen_s(&FileStream, "Test.txt", "rt");

	if (FileStream)
	{
		// ���Ͽ� ���ڸ� �߰��Ҷ�
		// fgetc : ���� �ϳ��� �о�� ��
		// fgets : ���ڿ��� �о�� �� �� ���� �о�´�.
		char	Text[256] = {};
		fgets(Text, 256, FileStream);

		std::cout << Text;

		char Text1 = fgetc(FileStream);

		std::cout << Text1 << std::endl;

		fclose(FileStream);
	}
	return 0;
}