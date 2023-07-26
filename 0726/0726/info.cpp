#include "info.h" 

//번호 저장
void SaveNum(int* Number)
{
    //번호 저장
    for (int i = 0; i < 25; i++)
    {
        Number[i] = i + 1; // 1번 부터 저장
    }
}

//번호 섞기
void Shuffle(int* Number)
{
    //숫자 카드를 랜덤하게 섞는다.
    for (int i = 0; i < 100; ++i)
    {
        int   Index1 = rand() % 25;
        int   Index2 = rand() % 25;

        int   Temp = Number[Index1];
        Number[Index1] = Number[Index2];
        Number[Index2] = Temp;
    }
}
//빙고판 출력
void PrintBingoBoard(int* Number) {

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
}

//입력한 숫자에 * 출력
void PrintStar(int* Number, int Input) {

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
}

//빙고 몇개인지 체크
void BingoCheck(int* Number, int* BingoCount) {

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
            ++*BingoCount;

        //세로 빙고
        if (CheckCount1 == 5)
            ++*BingoCount;
    }
    //대각선 빙고 체크
       // 왼쪽상단->오른쪽하단 대각선
    int CheckCount3 = 0;
    for (int i = 0; i < 5; ++i)
    {
        if (Number[i * 6] == INT_MAX)
            ++CheckCount3;
    }

    if (CheckCount3 == 5)
        ++BingoCount;

    // 오른쪽 상단 -> 왼쪽 하단 대각선
    int CheckCount4 = 0;

    for (int i = 1; i <= 5; ++i)
    {
        if (Number[i * 4] == INT_MAX)
            ++CheckCount4;
    }

    if (CheckCount4 == 5)
        ++BingoCount;
}