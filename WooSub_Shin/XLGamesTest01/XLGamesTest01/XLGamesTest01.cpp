// XLGamesTest01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

#define MAX_SIZE 10

using namespace std;


struct NODE
{
	int nSize = 0;
	int* nArr = NULL;
};

int main()
{

	NODE* nArrList[MAX_SIZE] = { NULL, };

	for (int i = 0; i < MAX_SIZE; i++)
	{
		nArrList[i] = new NODE;
		nArrList[i]->nArr = new int[i + 3];
		nArrList[i]->nSize = i + 3;
		nArrList[i]->nArr[0] = 0;
		nArrList[i]->nArr[nArrList[i]->nSize - 1] = 0;
	}

	for (int i = 0; i < MAX_SIZE - 1; i++)
	{
		//nArrList[i]->nArr = { 0, };

		if (i == 0)
		{
			nArrList[i]->nArr[i + 1] = 1;
		}

		for (int j = 1; j < nArrList[i]->nSize; j++)
		{
			nArrList[i + 1]->nArr[j] = nArrList[i]->nArr[j - 1] + nArrList[i]->nArr[j];
		}
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 1; j < nArrList[i]->nSize - 1; j++)
		{
			cout << nArrList[i]->nArr[j];
		}
		
		cout << endl;
	}
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
