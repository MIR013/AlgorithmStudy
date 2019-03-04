//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//void how2plus(int num)
//{
//	vector<int> ans;
//	ans.resize(num + 1);
//
//	ans[0] = 0; ans[1] = 1; ans[2] = 2; ans[3] = 4;
//	for (int i = 4; i <= num; i++)
//		ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
//
//	cout << ans[num]<<endl;
//	return;
//}
//int main()
//{
//	int n, x;
//	vector<int> num;
//	cin >> x;
//	for (int i = 0; i < x; i++)
//	{
//		cin >> n;
//		num.push_back(n);
//	}
//	for (int i = 0; i < x; i++)
//		how2plus(num[i]);
//
//	return 0;
//}