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
	Mode는 2가지로 구분된다. 
	파일을 만들거나 읽어 오거나 
	1번 글자
	w: 파일을 새로 만들어 줄때
	r : 기존 파일을 읽어올때
	a : 기존파일을 읽어와서 그 뒤에 내용을 추가해줄 때

	2번 글자
	t: 텍스트 파일 
	b: 바이너리 파일 
	*/

	//fopen_s(&FileStream, 경로, Mode );  //상대 경로, 절대 경로 
	fopen_s(&FileStream, "Test.txt", "wt");  //상대 경로

	if (FileStream)
	{
		//파일에 문자를 추가할떄
		//fputc : 문자 하나를 추가할 때
		//fputs : 문자열을 추가할 때
		fputs("문자열 추가\n", FileStream);
		fputc('t', FileStream);

		//작업이 완료된 파일 스트림은 무조건 닫아줘야 한다.
		fclose(FileStream);
	}

	//읽기
	fopen_s(&FileStream, "Test.txt", "rt");  //상대 경로

	if (FileStream)
	{
		//파일에 문자를 추가할떄
		//fgetc : 문자 하나를 읽어 올때
		//fgets : 문자열을 읽어올 때 한 줄을 읽어온다.
		char Text[256] = {};
		fgets(Text,100, FileStream);
		char Text1 = fgetc(FileStream);

		std::cout << Text ;

		//작업이 완료된 파일 스트림은 무조건 닫아줘야 한다.
		fclose(FileStream);
	}


	int* Num = nullptr;

	//Test(Num);

	Test1(&Num);

	return 0;
}