//#include<iostream>
//#include<stdio.h>
//#define MOD 1000000000
//using namespace std;
//
//int ans[101][10];
//void stair(int num)
//{
//	//1�ʱ�ȭ
//	ans[1][0] = 0;
//	for (int i = 1; i < 10; i++)
//	{
//		ans[1][i] = 1;
//	}
//
//	//ù ������ 0�� ���������� �ι������ʹ� 0 �� �����Ѵ�
//	if (num > 1) {
//		for (int i = 2; i <= num; i++)
//		{
//			for (int j = 0; j < 10; j++)
//			{
//				//����ؼ� ���� Ŀ���״� ���⼭ ������Ѵ�.
//				if (j == 0) ans[i][j] = ans[i - 1][j + 1] % MOD;
//				else if (j == 9) ans[i][j] = ans[i - 1][j - 1] % MOD;
//				else ans[i][j] = (ans[i - 1][j + 1] + ans[i - 1][j - 1])% MOD; 
//			}
//		}
//	}
//	int sum = 0;
//	for (int i = 0; i < 10; i++)
//		sum = (sum + ans[num][i]) % MOD;
//	cout << sum; //�׸��� ���ϸ� �� Ŀ���� ���⼭�� ���ش�
//	return;
//}
//int main()
//{
//	int N;
//	cin >> N;
//
//	stair(N);
//
//	return 0;
//}