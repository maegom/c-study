#include "info.h"

//빙고게임
int main()
{
    //난수 발생
    srand((unsigned int)time(0));
    rand();

    //숫자 저장할 공간 생성
    int   Number[25] = {};

    // 0 ~ 24번 인덱스에 1 ~ 25까지 값을 차례대로 넣어준다.
    SaveNum(Number);

    Shuffle(Number);

    //변수 생성
    int   Input = 0;  //입력할 값
    int   BingoCount = 0; //빙고 수 체크

    while (true)
    {
        system("cls"); //화면 정리

        //빙고판 출력
        PrintBingoBoard(Number);

        // 완성된 빙고가 5줄 이상이면 종료
        if (BingoCount >= 5)
        {
            std::cout << std::endl << "빙고를 완성하였습니다.\n";
            break;
        }

        //현재 빙고 개수 출력
        std::cout << "빙고 수 : " << BingoCount << std::endl;

        // 오픈할 카드 번호 입력 받기
        std::cout << std::endl << "오픈할 번호를 선택하시오(0:종료) : ";
        std::cin >> Input;

        // 입력값 예외 설정
        if (Input == 0) //0을 입력하면 종료
            break;

        else if (Input < 0 || Input > 25) //출력된 숫자 외 입력하면 재입력
            continue;

        // 입력받은 숫자를 배열에서 찾아서 *로 바꿔준다.
        PrintStar(Number, Input);

        //빙고줄수 체크
        BingoCount = 0;    // 매번 초기화 
        BingoCheck(Number, &BingoCount);
    }

    return 0;
}