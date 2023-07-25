// #:전처리기 : 컴파일 전에 먼저 처리를 하고 컴파일을 수행
// #include : 컴파일 전에 헤더파일 내용을 포함시켜서 사용
/*
실행파일 제작 순서
컴파일 -> 링크 > 실행파일 생성
*/
#include <iostream>

int main()  //진입점 main 
{//코드블록

	//using namespace std; //안쓰는게 좋다 (이름 충돌을 방지하기 위한 문법)

	// 오른쪽에서 왼쪽으로 작동

	std::cout << "console \"큰따옴표\" output\n"; // :: <-범위 지정 연산자 
	
	std::cout << "test output1" << std::endl;  //cout 에서만 사용 가능 
	std::cout << "test output2\n";
	 
/*
용량 최소단위 : bit
1 bit 는 0 or 1 저장할수 있는 공간
1byte : 8 bit

문자를 출력할 때는 정해진 아스키코드 표를 참조하여 값에 맞는 문자를 출력하는 시스템이다.
알파벳, 숫자, 간단한 특부수문자들은 1byte로 표현이 가능하지만
한글, 중국어는 2byte. 로 표현 된다. 

타입   ㅣ  표현 종류 ㅣ   크기   ㅣ  표현범위
bool       참/거짓       1byte     true(1)/false(0) // 0이아닌 모든 수는 참으로 판단한다. 
Char		문자			1byte     -128~ 127
short		정수			2byte	-32768~ 32767  //개발할때 잘 안씀
int			정수			4byte	-2147483648 ~ 2147483647
__int64		정수			8byte	
float	  부동소수점		4byte	
double	  부동소수점		8byte	

signed : 기본타입이다. 부호가 있는 타입
unsighned : 부호가 없는 타입이다. 음주 값이 모든 양수로 전환되어 0~ 표현되는 값의 범위가 넓어진다.

00000000 맨 왼쪽 부호 비트 

*/
	//FLT_MAX;

	//변수 선언방법  : 특수문자는 _만 허용, 첫글자는 알파벳이나 _만 가능.
	// 타입 변수이름;

	bool	test = true; // = : 대입 연산자 , 오른쪽의 값을 왼쪽으로 대입
	std::cout << test << std::endl;

	char	text = 'B';
	std::cout << text << std::endl;
	std::cout << (int)text << std::endl;

	for (int i = 0; i < 255; i++)
	{
		char	text2 = i;
		std::cout << text2 << " ";
	}

	char	text1 = 67;
	std::cout << text1 << std::endl;
	 
	short	number = 32767;  //변수의 표현범위가 벗어날 경우 +값으로 표현범위가 벗어나면 -값의 최소값으로 이동하여 표현
	//-값으로 표현범위가 벗어나면 +값의 최대값으로 이동하여 표현
	std::cout << number << std::endl;

	unsigned char r = 230;
	std::cout << r << std::endl;

	int number1 = 2147483647;
	std::cout << number1 << std::endl;

	__int64 number2 = 2147483647999999990;
	std::cout << number2 << std::endl;

	float number3 = 3.14125962f;  //소수점은 기본적으로 double인식 ,3.14f 붙여서 사용
	std::cout << number3 << std::endl;  //cout 은 소수점 5번째 자리까지 출력, 6번째 자리에서 반올림

	double	 number4 = 3.141259623;
	std::cout << number4 << std::endl;
	
	/*
	상수 : 값을 바꿀 수 없는 수
	변수를 상수로 바꿔서 사용할 수도 있다.

	const 키워드를 이용해서 변수를 상수로 바꿀 수 있다. 
	const 키워드는 변수의 타입 왼쪽에 붙여준다.
	변수를 상수로 만들게 되면 반드시 선언과 동시에 값을 초기화 시켜야한다. 선언 이후에는 값을 지정할 수 없다.

	*/
	const int	number5 = 1010;
	//number5 = 200;

	/*
	사칙연산자 : + , - ,* , / ,%(나머지연산자)
	10/3 = 3.33333333...
	but 10/3 = 3   
	  정수/정수 = 정수가 나온다.
	 만약 결과값이 소수점단위의 값이 나와야 한다면 둘중하나는 실수여야 한다. 
	*/ 

	std::cout << "10 / 3 = " << 10.0f / 3.0f << std::endl;  //0으로 나누는거 주의
	std::cout << "10 % 3 = " << 10 % 3 << std::endl; //나머지 연산은 정수 연산만 지원한다. 
	std::cout << "10 +3 * 1 = " << 10 + 3 * 1  << std::endl;

	/*
	관계연산자 : < , > , >=, <= , == (같다), !=(다르다)
	값 대 값을 연산해서 결과로 참,거짓이 나오게 된다. 
	10 > 20 = false 
	10 == 20 = false 
	*/

	std::cout << "10 < 20 = " << (10 < 20) << std::endl;
	std::cout << "10 > 20 = " << (10 > 20) << std::endl;
	std::cout << "10 == 20 = " << (10 == 20) << std::endl;
	std::cout << "10 != 20 = " << (10 != 20) << std::endl;



	/*
	논리 연산자 : AND(&&) , OR(||), NOT(!),
	참/거짓 대 참/거짓 연산해서 참/거짓 나옴.
	A	B	AND		OR
	0	0	0		0
	1	0	0		1
	0	1	0		1
	1	1	1		1

	*/

	std::cout << "false && false = " << (false && false) << std::endl;
	std::cout << "true && false = " << (true && false) << std::endl;
	std::cout << "true && true = " << (true && true) << std::endl;

	std::cout << "false || false = " << (false || false) << std::endl;
	std::cout << "true || false = " << (true || false) << std::endl;
	std::cout << "true || true = " << (true || true) << std::endl;

	std::cout << "!false =" << !false << std::endl;
	std::cout << "!true =" << !true << std::endl; 
  
	return 0;
}