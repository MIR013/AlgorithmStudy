//#include<iostream>
//#include<stdio.h>
//#define MOD 1000000000
//using namespace std;
//
//int ans[101][10];
//void stair(int num)
//{
//	//1초기화
//	ans[1][0] = 0;
//	for (int i = 1; i < 10; i++)
//	{
//		ans[1][i] = 1;
//	}
//
//	//첫 시작이 0이 없을뿐이지 두번쨰부터는 0 이 존재한다
//	if (num > 1) {
//		for (int i = 2; i <= num; i++)
//		{
//			for (int j = 0; j < 10; j++)
//			{
//				//계속해서 수가 커질테니 여기서 해줘야한다.
//				if (j == 0) ans[i][j] = ans[i - 1][j + 1] % MOD;
//				else if (j == 9) ans[i][j] = ans[i - 1][j - 1] % MOD;
//				else ans[i][j] = (ans[i - 1][j + 1] + ans[i - 1][j - 1])% MOD; 
//			}
//		}
//	}
//	int sum = 0;
//	for (int i = 0; i < 10; i++)
//		sum = (sum + ans[num][i]) % MOD;
//	cout << sum; //그리고 더하면 또 커지니 여기서도 해준다
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