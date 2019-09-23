#include<algorithm>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

int findRecept(int value, vector<int> buildings,int start)//�۽��ϴ� ž ����, ž, ������ �ε���
{
	for (int i = start; i >= 0; i--) {
		if (buildings[i] >= value) { //������ �ɸ��� ����
			return i;//1���� �����ؼ�..
		}
	}
	//������ �Ȱɷ��� ���
	return -1;
}
int main()
{
	int n;
	vector<int> communication;
	vector<pair<int,int> > stack; //[�ǹ���ȣ, ����]
	cin >> n;
	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		communication.push_back(data);
	}
	/*
		stack: �� �տ� ������ ū �ǹ����� ����
		���ÿ� �߰��Ҷ�, ������ ������ pop�ϰ�
						 ������ ũ�� �� ���� �ǹ��� �۽ŵ� �� �� push
		���ÿ� �ƹ� ������ ���ٸ�, �� �տ� ū�� ���ٴ� ��
	
		������ o(n)�� �ݵ�� ���ƾ� �Ѵ�.
	*/
	for (int i = 0; i < n; i++) {
		//���� Ȯ��
		if (stack.empty()) {
			printf("%d ", 0);
			stack.push_back(make_pair(i+1, communication[i]));
		}
		else {
			//���� �� ��
			int value = communication[i];
			//pop�ϱ� - top���� ũ��
			while (!stack.empty()) {//�� pop�Ǽ� ��� ���⼭ �ɸ�
				if (value <= stack.back().second) {
					break;
				}
				stack.pop_back();
			}
			//���
			if (stack.empty()) {
				printf("%d ", 0);
			}
			else {
				printf("%d ", stack.back().first);
			}
			//�ֱ�
			stack.push_back(make_pair(i + 1, value));
		}
	}



	return 0;
}