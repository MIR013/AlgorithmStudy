//#include<iostream>
//#include<stdio.h>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//vector<int> n;
//vector<int> m;
//
//int compare(const void *a, const void *b)
//{
//	int num1 = *(int *)a;
//	int num2 = *(int *)b;
//	if (num1 < num2) return -1;
//	if (num1 > num2) return 1;
//	return 0;
//}
//void isSame(int num, int start, int end)
//{
//	int mid = start + (end - start) / 2;
//
//	if (num == n[mid]) {
//		printf("%d ", 1);
//		return;
//	}
//	else if (start == end)
//	{
//		printf("0 ");
//		return;
//	}
//	else if (num < n[mid])
//	{
//		isSame(num, start, mid - 1);
//	}
//	else
//		isSame(num, mid + 1, end);
//
//}
//void card(int nsize, int msize)
//{
//	for (int i = 0; i < msize; i++)
//		isSame(m[i], 0, nsize);
//	printf("\n");
//}
//int main()
//{
//	int nNum, mNum;
//	int dump;
//
//	scanf("%d", &nNum);
//	for (int i = 0; i < nNum; i++)
//	{
//		cin >> dump;
//		n.push_back(dump);
//	}
//	scanf("%d", &mNum);
//	for (int i = 0; i < mNum; i++)
//	{
//		cin >> dump;
//		m.push_back(dump);
//	}
//	sort(n.begin(), n.end());
//
//
//	card(nNum, mNum);
//
//	return 0;
//}