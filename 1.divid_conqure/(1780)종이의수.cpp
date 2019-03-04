//#include<iostream>
//#include<deque>
//#include<stdio.h>
//
//#define A 1
//
//static int zeroNum = 0;
//static int plusNum = 0;
//static int minusNum = 0;
//int arr[3000][3000];
//
//bool isSame(int row,int col, int n)
//{
//	int num = arr[row][col];
//
//	for (int i = row; i < row + n; i++)
//	{
//		for (int j = col; j < col + n; j++)
//		{
//			if (num != arr[i][j])
//				return false;
//		}
//	}
//	return true;
//}
//void paper(int row,int col,int n)
//{
//	if (isSame(row, col, n))
//	{
//		switch (arr[row][col])
//		{
//		case -1: minusNum++;
//			break;
//		case 0: zeroNum++;
//			break;
//		case 1: plusNum++;
//			break;
//		}
//		return;
//	}
//	else
//	{
//		for (int i=0;i<3;i++)
//		{
//			for (int j = 0; j < 3; j++)
//			{
//				paper(row+(n / 3)*i, col+(n / 3)*j, (n / 3));
//			}
//		}
//	}
//}
//int main()
//{
//	int size;
//
//#if A
//	FILE *f = fopen("input.txt", "r");
//	fscanf(f, "%d", &size);
//	for (int i = 0; i < size; i++)
//		for (int j = 0; j < size; j++)
//			fscanf(f,"%d", &arr[i][j]);
//#else
//	//입력
//	scanf("%d", &size);
//	//생각하기 쉽게 1에서 부터 시작하자
//	for (int i = 0; i < size; i++)
//		for (int j = 0; j < size; j++)
//			scanf("%d", &arr[i][j]);
//#endif
//
//	paper(0, 0, size);
//
//	printf("%d\n%d\n%d\n", minusNum, zeroNum, plusNum);
//	return 0;
//}