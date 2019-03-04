#include<iostream>

#define MOD 1000000000

using namespace std;
static int ans[201][201] = { 0 };

void sumDivid(int n, int k)
{

	//초기화
	for (int i = 0; i <= n; i++) {
		ans[1][i] = 1;
	}
	for (int i = 2; i <= k; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int l = 0; l <= j; l++)
			{
				ans[i][j] += ans[i - 1][l];
			}
			ans[i][j] %= MOD;
		}
	}

	//출력
	cout << ans[k][n] <<endl;
	return;
}
int main()
{
	int n, k;
	cin >> n >> k;
	sumDivid(n, k);
	return 0;
}