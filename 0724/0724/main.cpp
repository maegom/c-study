#include <iostream>
/*
	구조체 : 여러개의 변수를 하나로 묶어서 사용할 수 있게 해주는 문법이다.

	형태
	struct 구조체이름
	{
		원하는 변수 선언
	};

	사용자정의 변수 타입을 만들어준다.
	구조체이름이 변수 타입이 된다.


	*/

//	#define :   전처리기 , 컨파일 전에 NAME_SIZE이름에 모두 32로 모두 교체
#define NAME_SIZE	32
#define TEST	std::cout<< "Test" << std::endl; //가급적 안쓴다. 

enum class CharcterType
{
	Type1,
	Type2,
	Type3
};

struct TestSturct
{
	int test1;
	int test2;
	int test3;
};

struct Playar
{
	char	Name[NAME_SIZE];
	CharcterType Type12;
	int Option;
	TestSturct TestStr;
};

int main() {

	TEST

	Playar player = {}; //모든 멤버들을 0으로 초기화 
	Playar player1 = {"aa0b" , CharcterType::Type1}; //이렇겐 잘 사용 안함 

	//구조체는 .을 이용하여 멤버에 접근한다. 
	//Name은 char 배열이다. 
	std::cout << player1.Name << std::endl; // char 배열의 모든문자 출력
	std::cout << player1.Name[0] << std::endl; 
	//std::cout << player.Type12 << std::endl;
	//문자열의 끝을 인식하기 위하여 반드시 마지막에 널문자(0)을 넣어주어야 한다. 
	//그래서 실제 배열은 32개이지만 실제 문자를 저장할 수 있는 공간은 31개 이다. 

	return 0;
}