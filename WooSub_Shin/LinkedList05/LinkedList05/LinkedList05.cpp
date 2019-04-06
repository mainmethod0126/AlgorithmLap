// LinkedList05.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

#define FOR_MAX 10

struct NODE
{
	int nData = 0;
	NODE* pNextNode = NULL;
};


using namespace std;

NODE* CreateNode(int nInputData)
{
	NODE* pNewNode = new NODE;
	pNewNode->nData = nInputData;

	return pNewNode;
}


void insertNode(NODE* pNode, int nInputData)
{
	NODE* pPrevNode = NULL;
	

	while (pNode != NULL)
	{
		if (pPrevNode != NULL)
		{
			if (pNode->nData >= nInputData)
			{
				pPrevNode->pNextNode = CreateNode(nInputData);
				pPrevNode->pNextNode->pNextNode = pNode;

				return;
			}
		}

		pPrevNode = pNode;
		pNode = pNode->pNextNode;
	}

	pPrevNode->pNextNode = CreateNode(nInputData);
}

void DeletedNode(NODE* pNode, int nDeleteData)
{
	NODE* pPrevNode = NULL;

	while (pNode != NULL)
	{
		if (pNode->nData == nDeleteData)
		{
			if (pNode->pNextNode == NULL)
			{
				pPrevNode->pNextNode = NULL;
				delete pNode;

				return;
			}
			else
			{
				pPrevNode->pNextNode = pNode->pNextNode;
				return;
			}
		}

		pPrevNode = pNode;
		pNode = pNode->pNextNode;
	}

}


void PrintList(NODE* pNode)
{
	while (pNode != NULL)
	{
		if (pNode->pNextNode != NULL)
		{
			cout << pNode->pNextNode->nData << "->";
		}
		pNode = pNode->pNextNode;
	}
}

int main()
{

	NODE* pListHeadNode = new NODE;

	for (int i = 0; i < FOR_MAX; i++)
	{
		int nInputData;

		cout << "리스트에 추가할 값 입력 : ";
		cin >> nInputData;
		cout << endl;

		insertNode(pListHeadNode, nInputData);
	}

	cout << endl;

	PrintList(pListHeadNode);

	int nDeleteData = 0;

	while (nDeleteData != 1000)
	{
		cout << endl;
		cout << "리스트에서 삭제할 값 입력 : ";
		cin >> nDeleteData;
		DeletedNode(pListHeadNode, nDeleteData);

		cout << endl;
		PrintList(pListHeadNode);

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
