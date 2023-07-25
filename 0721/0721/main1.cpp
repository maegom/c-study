
#include <iostream>
#include <time.h>

//빙고게임
int main()
{
    //난수 발생
    srand((unsigned int)time(0));
    rand();

    //숫자 저장할 공간 생성
    int   Number[25] = {};

    // 0 ~ 24번 인덱스에 1 ~ 25까지 값을 차례대로 넣어준다.
    for (int i = 0; i < 25; ++i)
    {
        Number[i] = i + 1;
    }

    //숫자 카드를 랜덤하게 섞는다.
    for (int i = 0; i < 100; ++i)
    {
        int   Index1 = rand() % 25;
        int   Index2 = rand() % 25;

        int   Temp = Number[Index1];
        Number[Index1] = Number[Index2];
        Number[Index2] = Temp;
    }

    //변수 생성
    int   Input = 0;  //입력할 값
    int   BingoCount = 0; //빙고 수 체크

    while (true)
    {
        system("cls"); //화면 정리

        //빙고판 출력
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                int   Index = i * 5 + j;

                //숫자가 INT_MAX 일때 '*' 출력
                if (Number[Index] == INT_MAX)
                    std::cout << "*\t";

                //아니면 그냥 숫자 출력
                else
                    std::cout << Number[Index] << "\t";
            }

            std::cout << "\n";
            std::cout << "\n";
        }

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
        for (int i = 0; i < 25; ++i)
        {
            // 입력받은 숫자와 같은 숫자가 배열에 있을 경우
            if (Number[i] == Input)
            {
                // INT_MAX는 int값으로 표현할 수 있는 가장 큰 값이다.
                // 이 값일 경우 *로 판단하여 출력할 때 *로 출력한다.
                Number[i] = INT_MAX;

                // 숫자를 찾아서 *로 바꿨으면 더이상 검사할 필요가
                // 없기 때문에 for문을 빠져나간다.
                break;
            }
        }

        // 줄을 체크하기 전에 LineCount를 0으로 초기화하고
        // 매번 12줄 모두 새롭게 체크를 해준다.
        BingoCount = 0;

        int   CheckCount = 0, CheckCount1 = 0;

        for (int i = 0; i < 5; ++i)
        {
            //변수 초기화
            CheckCount = 0;
            CheckCount1 = 0;

            for (int j = 0; j < 5; ++j)
            {
                //가로줄 체크
                if (Number[i * 5 + j] == INT_MAX)
                    ++CheckCount;

                //세로줄 체크
                if (Number[j * 5 + i] == INT_MAX)
                    ++CheckCount1;
            }

            //가로 빙고
            if (CheckCount == 5)
                ++BingoCount;

            //세로 빙고
            if (CheckCount1 == 5)
                ++BingoCount;
        }

        //대각선 빙고 체크
        // 왼쪽상단->오른쪽하단 대각선
        CheckCount = 0;
        for (int i = 0; i < 5; ++i)
        {
            if (Number[i * 6] == INT_MAX)
                ++CheckCount;
        }

        if (CheckCount == 5)
            ++BingoCount;

        // 오른쪽 상단 -> 왼쪽 하단 대각선
        CheckCount = 0;

        for (int i = 1; i <= 5; ++i)
        {
            if (Number[i * 4] == INT_MAX)
                ++CheckCount;
        }

        if (CheckCount == 5)
            ++BingoCount;
    }

    return 0;
}