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
//	//2���� ��ǲ���� ����...
//	for (int i = 2; i <= num; i++)
//	{
//		//�� ���� �� �������� ���� �Ѵ�
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