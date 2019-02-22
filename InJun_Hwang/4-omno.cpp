// ConsoleApplication6.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� �����˴ϴ�.
//


#include <iostream>

using namespace std;

int Temphap;

int Max;

int map[500][500] = {0, };
int  L, W;

int Long(int i, int j) {
   Temphap =  map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
   if (i < 0 || i >= L || j < 0 || j >= W)
   {
      return Temphap = 0;
   }
   else if (Temphap > Max)
      Max = Temphap;

   Temphap = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j];
   if (i < 0 || i >= L || j < 0 || j >= W)
   {
      return Temphap = 0;
   }
   else if (Temphap > Max)
      Max = Temphap;

}

int square(int i, int j) {

   Temphap = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1];
   if (i < 0 || i >= L || j < 0 || j >= W)
   {
      return Temphap = 0;
   }
   else
   if (Temphap > Max)
      Max = Temphap;
}

int gun(int i, int j) {
   Temphap = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j];
   if (i < 0 || i >= L || j < 0 || j >= W)
   {
      return Temphap = 0;
   }
   else
   if (Temphap > Max)
      Max = Temphap;

   Temphap = map[i][j] + map[i][j + 1] + map[i+1][j + 1] + map[i + 2][j+1];
   if (i < 0 || i >= L || j < 0 || j >= W)
   {
      return Temphap = 0;
   }
   else
   if (Temphap > Max)
      Max = Temphap;

   Temphap = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 2];
   if (i-1 < 0 || i >= L || j < 0 || j >= W)
   {
      return Temphap = 0;
   }
   else
   if (Temphap > Max)
      Max = Temphap;

   Temphap = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+ 2][j+1];
   if (i < 0 || i >= L || j < 0 || j >= W)
   {
      return Temphap = 0;
   }
   else
   if (Temphap > Max)
      Max = Temphap;
}

int xy(int i, int j) {

   Temphap = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
   if (i < 0 || i >= L || j-1 < 0 || j >= W)
   {
      return Temphap = 0;
   }
   else
   if (Temphap > Max)
      Max = Temphap;

   Temphap = map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i - 1][j + 2];
   if (i-1 < 0 || i >= L || j < 0 || j >= W)
   {
      return Temphap = 0;
   }
   else
   if (Temphap > Max)
      Max = Temphap;
}

int exceptionF(int i, int j) {

   Temphap = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
   if (i < 0 || i >= L || j < 0 || j >= W)
   {
      return Temphap = 0;
   }
   else
   if (Temphap > Max)
      Max = Temphap;

   Temphap = map[i][j] + map[i][j + 1] + map[i-1][j +1] + map[i + 1][j + 1];
   if (i-1 < 0 || i >= L || j < 0 || j >= W)
   {
      return Temphap = 0;
   }
   else
   if (Temphap > Max)
      Max = Temphap;

   Temphap = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i -1][j + 1];
   if (i-1 < 0 || i >= L || j < 0 || j >= W)
   {
      return Temphap = 0;
   }
   else
   if (Temphap > Max)
      Max = Temphap;

   Temphap = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j + 1];
   if (i < 0 || i >= L || j < 0 || j >= W)
   {
      return Temphap = 0;
   }
   else
   if (Temphap > Max)
      Max = Temphap;
}



int main()
{
   cin >> L >> W; // mapũ�� ����

   for (int i = 0; i < L; i++) {
      for (int j = 0; j < W; j++) {

         cin >> map[i][j];                 // �����Է¹ޱ� = �� ������
      }
   }


   for (int i = 0; i < L; i++) {
      for (int j = 0; j < W; j++) {

         Long(i, j);
         gun(i, j);
         square(i, j);
         exceptionF(i,j);


         }
      }

   cout << Max << endl;
   return 0;



}
