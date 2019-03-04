//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//vector<int> ans;
//
//void make2one(int num)
//{
//	ans.resize(num + 1);
//	ans[0] = 0;
//	ans[1] = 0; 
//	
//	//2부터 인풋으로 들어옴...
//	for (int i = 2; i <= num; i++)
//	{
//		//이 세개 중 작은값이 들어가야 한다
//		ans[i] = ans[i - 1] + 1;
//		if ((i % 2) == 0) ans[i] = min(ans[i],ans[i / 2] + 1);
//		if ((i % 3) == 0) ans[i] = min(ans[i],ans[i / 3] + 1);
//	}
//	return;
//}
//int main()
//{
//	int n;
//	cin >> n;
//
//	make2one(n);
//
//	cout << ans[n];
//
//	return 0;
//}