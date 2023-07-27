#include <iostream>

//파일 입출력
int main()
{
	// 파일 주소 저장
	FILE* FileStream = nullptr;

	// 파일 불러오기(쓰기*, 읽기, 업뎃)
	fopen_s(&FileStream, "Test.txt", "wt");
	//(주소      , "파일명" , "모드");
/* 모드는 2가지 조합이다.

1번 글자
w : 파일을 새로 만들어줄때
r : 기존 파일을 읽어올때
a : 기존 파일을 읽어와서 그 뒤에 내용을 추가해줄 때

2번 글자
t : 텍스트 파일
b : 바이너리 파일
*/

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

	// 파일 불러오기(쓰기, 읽기*, 업뎃)
	fopen_s(&FileStream, "Test.txt", "rt");

	if (FileStream)
	{
		// 파일에 문자를 추가할때
		// fgetc : 문자 하나를 읽어올 때
		// fgets : 문자열을 읽어올 때 한 줄을 읽어온다.
		char	Text[256] = {};
		fgets(Text, 256, FileStream);

		std::cout << Text;

		char Text1 = fgetc(FileStream);

		std::cout << Text1 << std::endl;

		fclose(FileStream);
	}
	return 0;
}