#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
//�迭���� �����ڴ�.
int R, C;//�迭 ũ��
//r,c�� ���� ����ǹǷ� - �� �°� ����ȭ �ʿ�(0�־��ֶ� �Ҹ�)
int input[9999][9999] = { 0 }; //�������� �� ����

void printall()
{
	for (int i = 1; i <= R; i++) {
		for(int j=1;j<=C;j++){
			printf("%3d ", input[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}
void sortR()
{
	int Cmax = C;
	//���� �ߺ��鼭 ó�l(����)
	for (int i = 1; i <= R; i++) {
		map<int, int> counts;//count���� ����ϱ� ���� �ؽ� ����
		for (int j = 1; j <= C; j++) {
			if (input[i][j] == 0) {
				continue;//0�� ��� ����!
			}
			if (counts.find(input[i][j]) == counts.end()) {
				//�ؽð� ������� ���
				counts[input[i][j]] = 1;
			}
			else {
				counts[input[i][j]] += 1;
			}
		}
		//���� (��:����)�ϱ� ���� -> �� ������ (���ͷ� ���� �� ���)
		vector<pair<int, int> > vectorData;
		map<int, int>::iterator iter;
		for (iter = counts.begin(); iter != counts.end(); ++iter) {
			vectorData.emplace_back(make_pair(iter->second, iter->first)); //(����, ��) ������
		}
		//������ ���������� ����(������ �������� ���� ��������)
		sort(vectorData.begin(), vectorData.end());
		//�迭 �����
		int index = 1;
		for (int k=0; k < vectorData.size(); k++) {
			input[i][index++] = vectorData[k].second;
			input[i][index++] = vectorData[k].first;
		}
		//ũ�Ⱑ �پ�� ��� �� �κ��� 0���� �����Ѵ�.
		for (; index <= C; index++) {
			input[i][index] = 0;
		}
		//��ü ���̴� �������� ��ȭ�ؾ� �Ѵ�.
		if (vectorData.size()*2 > Cmax) {
			Cmax = vectorData.size()*2;
		}
	}
	C = Cmax;

	return;
}
void sortC()
{
	int Rmax = R;
	//���� �ߺ��鼭 ó�l(����)
	for (int i = 1; i <= C; i++) {
		map<int, int> counts;//count���� ����ϱ� ���� �ؽ� ����
		for (int j = 1; j <= R; j++) {
			if (input[j][i] == 0) {
				continue;//0�� ��� ����!
			}
			if (counts.find(input[j][i]) == counts.end()) {
				//�ؽð� ������� ���
				counts[input[j][i]] = 1;
			}
			else {
				counts[input[j][i]] += 1;
			}
		}
		//���� (��:����)�ϱ� ���� -> �� ������ (���ͷ� ���� �� ���)
		vector<pair<int, int> > vectorData;
		map<int, int>::iterator iter;
		for (iter = counts.begin(); iter != counts.end(); ++iter) {
			vectorData.emplace_back(make_pair(iter->second, iter->first)); //(����, ��) ������
		}
		//������ ���������� ����(������ �������� ���� ��������)
		sort(vectorData.begin(), vectorData.end());
		//�迭 �����
		int index = 1;
		for (int k = 0; k < vectorData.size(); k++) {
			input[index++][i] = vectorData[k].second;
			input[index++][i] = vectorData[k].first;
		}
		//ũ�Ⱑ �پ�� ��� �� �κ��� 0���� �����Ѵ�.
		for (; index <= R; index++) {
			input[index][i] = 0;
		}
		//��ü ���̴� �������� ��ȭ�ؾ� �Ѵ�.
		if (vectorData.size() * 2 > Rmax) {
			Rmax = vectorData.size() * 2;
		}
	}
	R = Rmax;
	return;
}
int main()
{
	int r, c, k;
	int time = 0;
	cin >> r >> c >> k;
	
	/*
	�ִ� ������ 2��� Ŀ�� �� �ִ�. 
	�迭 �ִ� ũ��: 2147483647 -> �������̸� 46300����
	*/

	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			cin >> input[i][j];
		}
	}
	R = 3; C = 3;

	while (input[r][c] != k)
	{
		if (time > 100) {
			time = -1;
			break;
		}
		//���� �� ���
		if (R >= C) {
			sortR();
		}
		else {
			//���� �� ���
			sortC();
		}
		//printall();
		time++;
	}

	cout << time << endl;

	return 0;
}