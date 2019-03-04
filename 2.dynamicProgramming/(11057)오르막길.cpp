#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void mountain(int num)
{
	vector<vector<int>> ans;
	for (int i = 0; i <= num; i++)
	{
		vector<int> element;
		element.resize(10);
		ans.push_back(element);
	}
	for (int i = 0; i < 10; i++)
		ans[1][i] = 1;

	for (int i = 2; i <= num; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				ans[i][j] += ans[i - 1][k];
				ans[i][j] %= 10007;
			}

		}
	}

	int answer = 0;
	for (int i = 0; i < 10; i++)
		answer += ans[num][i];
	cout << answer%10007;
	return;
}
int main()
{
	int n;
	cin >> n;

	mountain(n);

	return 0;
}