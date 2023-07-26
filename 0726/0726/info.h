#pragma once //이 헤더파일을 1번만 포함시켜준다. 

#include <iostream>
#include <time.h>

//번호 저장
void SaveNum(int* Number);

//번호 섞기
void Shuffle(int* Number);

//빙고판 출력
void PrintBingoBoard(int* Number);

//입력한 숫자에 * 출력
void PrintStar(int*, int);

//빙고 몇개인지 체크
void BingoCheck(int*, int*);
