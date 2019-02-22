// BackJoon1759.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

// L = 암호의 길이
// C = 암호 조합에 쓰일 총 알파벳의 수
int L, C;

// 모음 자음
//int vowel;
//int consonant;

using namespace std;

void DFS(int depth, int nSetCnt, int vowel, int consonant);

vector<char> vecPassword;
vector<char> vecSelPassword;
vector<bool> vecVisitPassword;

int main()
{
	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		char cInput;
		cin >> cInput;
		vecPassword.push_back(cInput);
		vecVisitPassword.push_back(0);
	}

	for (int i = 0; i < C; i++)
	{
		vecSelPassword.push_back(0);
	}
	// char 어차피 아스키코드 기반이라 정렬가능

	sort(vecPassword.begin(), vecPassword.end());

	DFS(0, 0, 0, 0);

	// for (int i = 0; i < C; i++)
	// {
	// 	cout << vecPassword[i];
	// }
}

void DFS(int Index, int nSetCnt, int vowel, int consonant)
{
	// 만약 4개가 다 들어갔다라면 탈출 조건 확인해준다
	if (nSetCnt == L)
	{

		if (vowel < 1 || consonant < 2 || !(is_sorted(&vecSelPassword[0], &vecSelPassword[L])))
		{
			nSetCnt--;
			return;
		}

		// 모음 자음의 갯수가 조건과 맞고 오름차 순서가 맞다면 출력해준다

		for (int i = 0; i < L; i++)
		{
			cout << vecSelPassword[i];
		}
		cout << endl;
		nSetCnt--;
		return;
	}


	for (int i = 0; i < C; i++)
	{
		if (vecVisitPassword[i] != 0) continue;
		// 일단 출력할 배열에 현재 선택된 알파벳을 넣는다

		if ( nSetCnt > 0 ) {
			if ( vecSelPassword[nSetCnt-1] > vecPassword[i] ){
				continue;
			}
		}
		// 선택된 마지막 알파벳보다 작은 알파벳이 들어오는 경우는 제외한다.

		vecSelPassword[nSetCnt] = vecPassword[i];
		if (vecSelPassword[nSetCnt] == 'a' || vecSelPassword[nSetCnt] == 'e' || vecSelPassword[nSetCnt] == 'i' || vecSelPassword[nSetCnt] == 'o' || vecSelPassword[nSetCnt] == 'u')
		{
			vowel++;
		}
		else
		{
			consonant++;
		}

		// 선택된 알파벳이 모음인지 자음인지 구분하여 카운팅해준다
		vecVisitPassword[i] = 1;
		DFS(i, nSetCnt + 1, vowel, consonant);
		vecVisitPassword[i] = 0;

		if (vecSelPassword[nSetCnt] == 'a' || vecSelPassword[nSetCnt] == 'e' || vecSelPassword[nSetCnt] == 'i' || vecSelPassword[nSetCnt] == 'o' || vecSelPassword[nSetCnt] == 'u')
		{
			vowel--;
		}
		else
		{
			consonant--;
		}

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
