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
	//�ִ��� ū �߷��� ������ ������ "����" -> �׸���
	//���� �� ���� ���� ���� k�� ��ŭ �� �� �ִ�.
	sort(loof.begin(), loof.end());//����Ʈ�� ��������

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