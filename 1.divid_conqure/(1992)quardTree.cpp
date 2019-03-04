//#include<stdio.h>
//#include<iostream>
//#include<vector>
//#include<stdlib.h>
//#include<string>
//
//using namespace std;
//
//
//vector<vector<char> > arr;
//string ans;
//
//bool isSame(int row, int col, int n)
//{
//	char fir = arr[row][col];
//
//	for (int i = row; i < row + n; i++)
//		for (int j = col; j < col + n; j++)
//			if (fir != arr[i][j])
//				return false;
//	return true;
//}
//void tree(int row, int col, int n)
//{
//	if (isSame(row, col, n))
//	{
//		ans.push_back(arr[row][col]);
//		return;
//	}
//	else
//	{
//		ans.push_back('(');
//		for (int i = 0; i < 2; i++) {
//			for (int j = 0; j < 2; j++) {
//				tree(row + (n / 2)*i, col + (n / 2)*j, n / 2);
//			}
//		}
//		ans.push_back(')');
//	}
//}
//int main()
//{
//	int size, num;
//	cin >> size;
//
//	//2차원 벡터로 초기화
//	for (int i = 0; i < size; i++)
//	{
//		vector<char> element;
//		element.resize(size);
//		arr.push_back(element);
//	}
//	//2차원 벡터 사용
//	for (int i = 0; i < size; i++)
//		for (int j = 0; j < size; j++)
//			cin >> arr[i][j];
//
//
//	tree(0, 0, size);
//	cout << ans;
//
//
//	return 0;
//}