//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//vector<int> ans;
//
//void tile(int num)
//{
//	ans.resize(num + 1);
//
//	ans[0] = 1;
//	ans[1] = 1;
//
//	for (int i = 2; i <= num; i++)
//	{
//		ans[i] = (ans[i - 1] + ans[i - 2])%10007;
//	}
//}
//int main()
//{
//	int n;
//	cin >> n;
//	tile(n);
//	cout << ans[n];
//	return 0;
//}