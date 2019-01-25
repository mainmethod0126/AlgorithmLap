#include <iostream>
#define Max 100
using namespace std;
int main()
{
	int N = 0; //라운드수 

	int a; // 그림의 개수 
	int A[Max] = {};

	int b;
	int B[Max] = {};


	cout << "라운드 수를 입력하세요 : ";
	cin >> N;

	for (int i = 0; i < N; i++) {


		cin >> a;
		for (int i = 0; i < a; i++)
		{
			cin >> A[i];
		}

		cin >> b;
		for (int i = 0; i < b; i++)
		{
			cin >> B[i];
		}

		cout << a;
		for (int i = 0; i < a; i++)
		{
			cout << A[i];
		}

		cout << endl;

		cout << b;
		for (int i = 0; i < b; i++)
		{
			cout << B[i];
		}

		cout << endl;

		int tempA = 0;
		int tempB = 0;

		int hapA = 0;
		int hapB = 0;

		for (int i = 0; i < a; i++)
		{
			hapA = hapA + A[i];
		}
		for (int i = 0; i < b; i++)
		{
			hapB = hapB + B[i];
		}


		for (int i = 0; i < a; i++)
		{
			if (A[i] == 4)
				tempA++;

		}


		for (int i = 0; i < b; i++)
		{
			if (B[i] == 4)
				tempB++;
		}

		if (tempA > tempB)
		{
			cout << "A" << endl;
			continue;

		}

		else if (tempA < tempB)
		{
			cout << "B" << endl;
			continue;

		}

		else if (tempA == tempB)
		{
			if (hapA == hapB)
				cout << "D" << endl;


			else
				tempA = 0;
			tempB = 0;

		}

		for (int i = 0; i < a; i++)
		{
			if (A[i] == 3)
				tempA++;
		}

		for (int i = 0; i < b; i++)
		{
			if (B[i] == 3)
				tempB++;
		}

		if (tempA > tempB)
		{
			cout << "A" << endl;
			continue;

		}

		else if (tempA < tempB)
		{
			cout << "B" << endl;
			continue;

		}

		else if (tempA == tempB)
		{
			if (hapA == hapB)
				cout << "D" << endl;

			else
				tempA = 0;
			tempB = 0;
		}

		for (int i = 0; i < a; i++)
		{
			if (A[i] == 2)
				tempA++;
		}

		for (int i = 0; i < b; i++)
		{
			if (B[i] == 2)
				tempB++;
		}

		if (tempA > tempB)
		{
			cout << "A" << endl;
			continue;

		}

		else if (tempA < tempB)
		{
			cout << "B" << endl;
			continue;

		}

		else if (tempA == tempB)
		{
			if (hapA == hapB)
				cout << "D" << endl;

			else
				tempA = 0;
			tempB = 0;
		}

		for (int i = 0; i < a; i++)
		{
			if (A[i] == 1)
				tempA++;
		}

		for (int i = 0; i < b; i++)
		{
			if (B[i] == 1)
				tempB++;
		}

		if (tempA > tempB)
		{
			cout << "A" << endl;
			continue;

		}

		else if (tempA < tempB)
		{
			cout << "B" << endl;
			continue;

		}

		else if (tempA == tempB)
		{
			if (hapA == hapB)
				cout << "D" << endl;
		}

	}
}