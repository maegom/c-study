#include <iostream>

int main()
{
	/*	진수

	2진수 : 0~1 사이로 구성된 숫자 집합
	0b1110111  : 0b 는 2진수
	10진수 : 0~9 사이로 구성된 숫자 집합
	16진수 : 0~ 15사이로 구성된 숫자 집합 10~15는 a~ f로 표현
	0x  : 16진수

	216 을 2진수, 16진수로 변환
	216/2 108 -0
	   /2 54  -0
	   /2 27  -0
	   /2 13  -1
	   /2  6  -1
	   /2  3  -0
	   /2  1  -1

	   0b11011000

	다시 10진수
	1   1  0  1  1 0 0 0
	128 64 32 16 8 4 2 1

	128+64+16+8

	16진수는 2진수 4자리로 구성된다.
	1101  1000
	13		8
	0xd8

	비트단위 논리연산자 : 2진수 단위의 연산을 수행한다.
	값대 값은 연산하여 결과로 값이 나온다.
	AND(&), OR(|), NOT(~), XOR(^)
	비트단위 논리연산자를 사용하면 피연산자달을 먼저 2진수로 변환한다.

	216 & 357
	011011000
	101100101

	001000000

	216 | 357
	011011000
	101100101

	111111101

	~216
	11011000

	00000000 00000000 00000000 11011000
	11111111 11111111 11111111 00100111
	대칭 되는 -217


	216 ^ 357
	011011000
	101100101

	110111101

	*/

	std::cout << "216 & 35 = " << (216 & 357) << std::endl;
	std::cout << "216 | 35 = " << (216 | 357) << std::endl;
	std::cout << "~216  = " << (~216) << std::endl;
	std::cout << "216 ^ 357 = " << (216 ^ 357) << std::endl;


	const int State1 = 0x1;		//1
	const int State2 = 0x2;		//10
	const int State3 = 0x4;		//100
	const int State4 = 0x8;		//1000
	const int State5 = 0x10;	//10000
	const int State6 = 0x20;	//100000
	const int State7 = 0x40;	//1000000

	int State = 0;
	/*
	OR 를 이용하여 추가하고 AND를 이용해서 상태가 있는지 검사한다.
	XOR를 이용해서 상태가 켜져있을 경우 제거하고 상태가 없을 경우 켜준다
	*/


	State = State | State3;  // 000 | 100 = 100
	State = State | State5;  // 00100 | 10000 = 10100
	State = State | State7;

	State = State ^ State7; //1010100 ^ 1000000 = 0010100

	std::cout << "State1 = " << (State & State1) << std::endl;
	std::cout << "State2 = " << (State & State2) << std::endl;
	std::cout << "State3 = " << (State & State3) << std::endl;
	std::cout << "State4 = " << (State & State4) << std::endl;
	std::cout << "State5 = " << (State & State5) << std::endl;
	std::cout << "State6 = " << (State & State6) << std::endl;
	std::cout << "State7 = " << (State & State7) << std::endl;

	/*
	쉬프트 연산자 :  << , >> 2가지 있다.
	216 << 2   /2^2곱
	: 11011000 왼쪽으로 2칸이동해라
	   00000000 00000000 00000011 01100000 왼쪽 두개 제거 > 오른쪽 두개0 붙임
	   :864

	   216 >> 2 /2^2나눔
	: 11011000 오른쪽으로 2칸이동해라
	  00110110 오른쪽 두개 제거 > 왼쪽 두개0 붙임
	   :864
	*/

	unsigned char r = 201;
	unsigned char g = 157;
	unsigned char b = 182;
	unsigned char a = 240;

	unsigned int Color = 0;

	Color = a;
	//00000000 00000000 00000000 aaaaaaaaa

	Color = Color << 8;
	//00000000 00000000 aaaaaaaaa 00000000

	Color = Color | r;
	//00000000 00000000 aaaaaaaaa rrrrrrrr

	Color = Color << 8;
	//00000000 aaaaaaaaa rrrrrrrr 00000000

	Color = Color | g;
	//00000000 aaaaaaaaa rrrrrrrr gggggggg

	Color = Color << 8;
	//aaaaaaaaa rrrrrrrr gggggggg 00000000

	Color = Color | b;
	//aaaaaaaaa rrrrrrrr gggggggg bbbbbbbb

	std::cout << Color << std::endl;

	std::cout << "b = " << (Color & 0x000000ff) << std::endl;
	std::cout << "g = " << (Color >> 8 & 0x000000ff) << std::endl;
	std::cout << "r = " << (Color >> 16 & 0x000000ff) << std::endl;
	std::cout << "a = " << (Color >> 24 & 0x000000ff) << std::endl;

	const int test1 = 0b11111111111;		//1
	std::cout << "test1 = " << test1 << std::endl;

	/*
	증감연산자 : ++, --
	++:변수의 값 1증가 
	--:변수의 값 1감소
	왼쪽 : 전치연산
	오른쪽 : 후치연산

	*/

	int Number = 100;
	std::cout << ++Number << std::endl;
	std::cout <<  Number++ << std::endl;
	std::cout <<  Number << std::endl;

	std::cout << --Number << std::endl;
	std::cout << Number-- << std::endl;
	std::cout << Number << std::endl;

	/*
	연산자 축약형 : +=, -=, &=, |=
	*/

	Number = 10;
	Number += 20;

	std::cout << Number << std::endl;



	return 0;
}