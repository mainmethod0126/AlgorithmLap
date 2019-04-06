// QuickSort04.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

#define MAX_SIZE 10

using namespace std;



void QuickSort(int* arr, int nStart, int nEnd)
{
	if (nStart >= nEnd)
	{
		return;
	}

	int nPivot = nStart;
	
	//탐색용 변수
	int i = nStart + 1;
	int j = nEnd;


	while (i <= j)
	{
		while (arr[nPivot] >= arr[i] && i < nEnd)
		{
			i++;
		}
		while (arr[nPivot] <= arr[j] && j > nStart)
		{
			j--;
		}

		if (i >= j)
		{
			int nTemp = arr[nPivot];
			arr[nPivot] = arr[j];
			arr[j] = nTemp;
		}
		else
		{
			int nTemp = arr[i];
			arr[i] = arr[j];
			arr[j] = nTemp;
		}
	}

	//좌
	QuickSort(arr, nStart, j - 1);
	//우
	QuickSort(arr, j + 1, nEnd);
}


int main()
{
	int arr[MAX_SIZE] = {0, };

	for (int i = 0; i < MAX_SIZE; i++)
	{
		cin >> arr[i];
	}

	// 들어온 값 확인
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << arr[i] << " ";
	}

	QuickSort(arr, 0, MAX_SIZE - 1);
	cout << endl;

	// 정렬 값 확인
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << arr[i] << " ";
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
