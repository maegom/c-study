
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
	파일입출력 : 파일을 만들고 읽어오기 위한 기능이다.
	C언어 방식과 C++방식이 제공된다.
	*/
	FILE* FileStream = nullptr;

	/*
	fopen_s에서 Mode는 2가지 부분으로 구분된다.
	2개의 알파벳 조합으로 처리된다.
	1번 글자
	w : 파일을 새로 만들어줄때
	r : 기존 파일을 읽어올때
	a : 기존 파일을 읽어와서 그 뒤에 내용을 추가해줄 때

	2번 글자
	t : 텍스트 파일
	b : 바이너리 파일
	*/
	fopen_s(&FileStream, "Test.txt", "wt");
	
	if (FileStream)
	{
		// 파일에 문자를 추가할때
		// fputc : 문자 하나를 추가할 때
		// fputs : 문자열을 추가할 때
		fputs("문자열 추가\n", FileStream);
		fputc('T', FileStream);


		// 작업이 완료된 파일 스트림은 무조건 닫아줘야 한다.
		fclose(FileStream);
	}

	fopen_s(&FileStream, "Test.txt", "rt");

	if (FileStream)
	{
		// 파일에 문자를 추가할때
		// fgetc : 문자 하나를 읽어올 때
		// fgets : 문자열을 읽어올 때 한 줄을 읽어온다.
		//fputs("문자열 추가\n", FileStream);
		//fputc('T', FileStream);
		char	Text[256] = {};
		fgets(Text, 256, FileStream);

		std::cout << Text;

		char Text1 = fgetc(FileStream);

		std::cout << Text1 << std::endl;


		// 작업이 완료된 파일 스트림은 무조건 닫아줘야 한다.
		fclose(FileStream);
	}

	int* Num = nullptr;

	//Test(Num);

	Test1(&Num);

	return 0;
}
