//#include<iostream>
//#include<stdio.h>
//#include<deque>
//
//int arr[100][100];
//int brr[100][100];
//int crr[100][100];
//
//void mulmatrix(int n, int m, int k)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			for (int l = 0; l < k; l++)
//			{
//				crr[i][l] += arr[i][j] * brr[j][l];
//			}
//		}
//	}
//}
//int main()
//{
//	int n, m, k;
//
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			scanf("%d", &arr[i][j]);
//
//	scanf("%d %d", &m, &k);
//	for (int i = 0; i < m; i++)
//		for (int j = 0; j < k; j++)
//			scanf("%d", &brr[i][j]);
//	mulmatrix(n, m, k);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < k; j++)
//			printf("%d ", crr[i][j]);
//		printf("\n");
//	}
//	return 0;
//}