// LinkedList03.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

struct NODE
{
	int nData = 0;
	NODE* pNextNode = NULL;
};

NODE* ListHeadNode = NULL;

//void ListQuickSort(NODE* pNode, )
//{
//
//}


void AddNode(int nData, NODE* pNode)
{
	while (pNode->pNextNode != NULL)
	{
		pNode = pNode->pNextNode;
	}

	pNode->pNextNode = new NODE;

	pNode->pNextNode->nData = nData;

	return;
}

void InsertNode(int nInsertData, NODE* pNode)
{
	NODE* pPrveNode = NULL;

	while (pNode->pNextNode != NULL)
	{
		pPrveNode = pNode;
		pNode = pNode->pNextNode;

		if (pNode->nData > nInsertData)
		{
			NODE* pNewNode = new NODE;

			pNewNode->nData = nInsertData;

			pPrveNode->pNextNode = pNewNode;
			pNewNode->pNextNode = pNode;

			return;
		}
	}

	//널이라면 리스트의 끝이니까 그냥 추가
	AddNode(nInsertData, pNode);
}


void PrintList(NODE* pNode)
{
	while (pNode->pNextNode != NULL)
	{

		if (pNode->nData != 0)
		{
			std::cout << pNode->nData << std::endl;
		}

		pNode = pNode->pNextNode;
	}
}

void DeleteNode(int nDeleteData, NODE* pNode)
{
	NODE* pPrvNode = NULL;

	while (pNode->nData != nDeleteData)
	{
		pPrvNode = pNode;

		pNode = pNode->pNextNode;
	}

	pPrvNode->pNextNode = pNode->pNextNode;

	delete pNode;
}


int main()
{
	if (ListHeadNode == NULL)
	{
		ListHeadNode = new NODE;
	}

	int AddData = 0;

	while (AddData != 100)
	{
		std::cin >> AddData;

		AddNode(AddData, ListHeadNode);
	}

	int InputDeleteData = 0;

	do
	{
		PrintList(ListHeadNode);

		
		std::cin >> InputDeleteData;
		std::cout << "삭제할 노드 : " << InputDeleteData << std::endl;


		DeleteNode(InputDeleteData, ListHeadNode);

	} while (InputDeleteData != 100);


	int InputInsertData = 0;

	do
	{
		PrintList(ListHeadNode);

		std::cin >> InputInsertData;
		std::cout << "삽입할 Data : " << InputInsertData << std::endl;

		InsertNode(InputInsertData, ListHeadNode);

	} while (InputInsertData != 100);



	
	

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
