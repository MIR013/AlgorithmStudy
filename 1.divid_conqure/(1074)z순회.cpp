//#include<stdio.h>
//#include<iostream>
//#include<vector>
//#include<stdlib.h>
//#include<string>
//#include<math.h>
//
//using namespace std;
//static int theNum;
//static int r, c;
//
//void Z(int row, int col, int n)
//{
//	if ((row == r) && (col == c))
//	{
//		printf("%d", theNum);
//		exit(0);
//	}
//	//해당 정사각형에 답이 없다면 리턴
//	if (n == 1) {
//		theNum++;
//		return;
//	}
//	if ((row+n<r)&&(col+n<c)&&(row<r)&&(col<c))
//	{
//		theNum += (n*n);
//		return;
//	}
//	else
//	{
//		for (int i = 0; i < 2; i++) {
//			for (int j = 0; j < 2; j++)
//			{
//				Z(row + (n / 2)*i, col + (n / 2)*j, n / 2);
//			}
//		}
//	}
//}
//int main()
//{
//	int n;
//	cin >> n;
//	cin >> r;
//	cin >> c;
//
//	int size = (int)pow(2.0, n);
//	Z(0, 0, size);
//	return 0;
//}