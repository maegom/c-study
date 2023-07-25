#include <iostream> 
#include <time.h>

/*
플레이어는 가위, 바위, 보중 하나 선택
AI는 랜덤
누가 이겼는지 판단.
*/

/*
열거체 : 상수에 이름을 부여하는 기능이다. 
열거체를 이용하여 이름이 부여된 상수는 나열되는 순서레 따라 값이 변경될 수 있다.

형태 
enum 열거체명
{이름부여} //이름이 부여된 목록은 0부터 시작해서 값이 1씩 증가되어 지정된다.

열거형은 목록의 상수를 이용할 수도 있지만 열거형의 이름 자체가 일종의 사용자정의 변수타입이 된다.

열거형으로 만든 변수는 해당 열거형의 목록에 지정된 값만 저장할 수 있다. 

열거형은 무조건 4byte 로 크기 잡힘

enumclass 는 타입에 대해 더 엄격

*/

/*
switch : 분기문의 한 종류 (여러가지 경우중 하나)
형태 
switch (분기처리하고자 하는 값)
 {
	case 체크할 상수 :  동작시킬코드    break;   //변수 안되고 꼭 상수  , break 의 역할은 switch 문 빠져나감.
 }
*/

enum SRP
{
	SISSOR=1,  //지정된거 다음부터 +1
	ROCK,
	PAPER
};

enum class SRP1 : unsigned char  //이렇게 타입 지정 가능
{
	SISSOR1 = 1,  //지정된거 다음부터 +1
	ROCK1,		//2U : unsigned 
	PAPER1
};
int main()
{
	srand((unsigned int)time(0));  //형변환 : (변환할 타입) 의 형태로 사용하며, 어떤 값이나 변수를 지정하는 타입으로 일시적으로 인식시켜줌
	rand();

	std::cout << "무엇을 낼지 선택하시오!\n" << std::endl;
	std::cout << "1.가위" << std::endl;
	std::cout << "2.바위" << std::endl;
	std::cout << "3.보\n" << std::endl;

	int player;
	int AI;

	std::cin >> player;
	AI = rand()%3 + 1;

	switch (AI)
	{
	case SISSOR :	std::cout << "AI 는 가위를 냈습니다.\n" << std::endl;  		break;
	case ROCK	:	std::cout << "AI 는 바위를 냈습니다.\n" << std::endl;	 		break;
	case PAPER	:	std::cout << "AI 는 보를 냈습니다.\n" << std::endl;	  		break;
	}
	
	/*if (AI == SISSOR)
		std::cout << "AI 는 가위를 냈습니다.\n" << std::endl;
	else if (AI == ROCK)
		std::cout << "AI 는 바위를 냈습니다.\n" << std::endl;
	else if (AI == PAPER)
		std::cout << "AI 는 보를 냈습니다.\n" << std::endl;*/

	SRP srp;
	srp = SISSOR;

	SRP1 srp1;
	srp1 = SRP1::SISSOR1; //enum 와 enumclass차이
	
	std::cout << "SRT size =" << sizeof(SRP) << std::endl;
	std::cout << "SRT1 size =" << sizeof(SRP1) << std::endl;
	
	if (player == AI)
		std::cout << "비겼습니다." << std::endl;
	else if (player == SISSOR && AI == PAPER || player == ROCK && AI == SISSOR || player == PAPER && AI == ROCK)
		std::cout << "당신이 이겼습니다." << std::endl;
	else
		std::cout << "당신이 졌습니다." << std::endl;

	return 0;
}