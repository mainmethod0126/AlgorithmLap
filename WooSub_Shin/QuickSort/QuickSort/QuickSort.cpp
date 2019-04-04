// QuickSort.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

#define MAX_SIZE 10

using namespace std;

int m_nArr[MAX_SIZE];

void QuickSort(int *pArr, int nStartIndex, int nEndIndex);


void QuickSort(int *pArr, int nStartIndex, int nEndIndex)
{
	int nPivot = nStartIndex;
	int i = nStartIndex + 1;
	int j = nEndIndex;
	int nTemp = 0;


	// 배열에 피벗 혼자만 남았을때
	if (nStartIndex >= nEndIndex)
	{
		return;
	}

	// 교차되지 않았다면 계속 루프 교차되면 빠져나온다
	while (i <= j)
	{
		while (pArr[nPivot] >= pArr[i] && i < nEndIndex)
		{
			i++;
		}
		while (pArr[nPivot] <= pArr[j] && j > nStartIndex)
		{
			j--;
		}

		// 교차되었다면 피벗이랑 down값이랑 변경
		if (i >= j)
		{
			nTemp = pArr[j];
			pArr[j] = pArr[nPivot];
			pArr[nPivot] = nTemp;
		}
		// 교차 안되었다면 큰값 작은값 변경
		else
		{
			nTemp = pArr[i];
			pArr[i] = pArr[j];
			pArr[j] = nTemp;
		}
	}

	//빠져나왔다면
	QuickSort(pArr, nPivot, j - 1);
	QuickSort(pArr, j + 1, nEndIndex);
}


int main()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cin >> m_nArr[i];
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << m_nArr[i] <<" ";
	}

	QuickSort(m_nArr, 0, MAX_SIZE - 1);

	cout << endl;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << m_nArr[i] << " ";
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
