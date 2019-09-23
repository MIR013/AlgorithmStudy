#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	vector<int> loof;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		loof.push_back(data);
	}
	//최대한 큰 중량을 가지게 밧줄을 "선택" -> 그리디
	//로프 중 가장 작은 애의 k배 만큼 들 수 있다.
	sort(loof.begin(), loof.end());//디폴트는 오름차순

	int max_value = -1;
	for (int i = 0; i < n; i++) {
		int next = loof[i];
		int w = next * (n - i);
		if (max_value < w) {
			max_value = w;
		}
	}
	printf("%d\n", max_value);

}