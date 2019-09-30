#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

//������ ������ n�� �������迭�� �迭�� �����ϱ�
int map[51][51]; //�̼����� ��
int R, C, time;//��,��,�����ð�
pair<int, int> machine[2];//����û������ ��ġ [��,�Ʒ�]
int dirx[4] = {-1,0,1,0};//��,��,��,��
int diry[4] = {0,1,0,-1};

void printAll()
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%3d ", map[i][j]);
		}
		printf("\n");
	}

	return;
}
void upside()
{
	/*
		����û���� ���� ����	
		�ݽð�ϱ� �ð�������� ����
		machine[0]
	*/
	int mx = machine[0].first;
	int my = machine[0].second;

	//�Ʒ�
	for (int i = mx-2; i >= 0; i--) {
		map[i+1][0] = map[i][0];
	}
	//����
	for (int i = 1; i <= C-1; i++) {
		map[0][i - 1] = map[0][i];
	}
	//��
	for (int i = 1; i <= mx; i++) {
		map[i - 1][C-1] = map[i][C - 1];
	}
	//������
	for (int i = C-2; i > 0; i--) {
		map[mx][i + 1] = map[mx][i];
	}
	map[mx][1] = 0;//����û���⿡�� ���� ��

	return;
}
void downside()
{
	/*
		����û���� �Ʒ��� ����
		�ð�
		machine[1]
	*/

	int mx = machine[1].first;
	int my = machine[1].second;


	//��
	for (int i = mx+2; i < R; i++) {
		map[i - 1][0] = map[i][0];
	}
	//����
	for (int i = 1; i < C; i++) {
		map[R-1][i - 1] = map[R-1][i];
	}
	//�Ʒ�
	for (int i = R - 2; i >= mx; i--) {
		map[i + 1][C-1] = map[i][C-1];
	}
	//������
	for (int i = C - 2; i > 0; i--) {
		map[mx][i + 1] = map[mx][i];
	}
	map[mx][1] = 0;//����û���⿡�� ���� ��


	return;
}
void diffusion()
{
	/*
	map�� ��� �̼������� Ȯ��ȴ�.
	��, �׵θ��� ���Ƴ� ���, ����û���⿡ �ٴ� ���� �þ�� ����
	��� ������ �̼������� ��� ��ø�Ǳ� ������ �迭�ϳ��� ���� ������
	swap�ؼ� ó���� ����
	*/
	int temp[51][51] = { 0 };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == -1) {
				temp[i][j] = -1;
				continue;
			}
			if (map[i][j]) {
				int num = 0; // Ȯ���� ����
				int diff = int(map[i][j] / 5); //Ȯ�귮
				//�����¿� ����
				for (int dir = 0; dir < 4; dir++) {
					int nextx = i + dirx[dir];
					int nexty = j + diry[dir];

					//�׵θ� Ȯ��
					if (nextx < 0 || nextx >= R || nexty < 0 || nexty >= C)
						continue;
					//����û�������� Ȯ��
					if (map[nextx][nexty] == -1)
						continue;
					//�Ѵ� �ƴϸ� Ȯ��
					num++;
					temp[nextx][nexty] += diff;
				}
				//���� �ڸ� ����
				temp[i][j] += map[i][j] - (diff*num);
			}
		}
	}

	swap(map,temp);

	return;
}
int main()
{
	/*
		�ùķ��̼�
		�̼����� Ȯ�� �� ����û����
		�̰� �ð���..
	*/
	//�Է�
	int p = 0; //machine�� �ε���
	cin >> R >> C >> time;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				machine[p++] = make_pair(i, j);
			}
		}
	}


	//�̼����� ����
	while (time > 0)
	{
		//�̼����� Ȯ��
		diffusion();
		//����û���� ����
		upside();
		downside();
		time--;
	}

	//���� �̼����� ���
	int total = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != -1) {
				total += map[i][j];
			}
		}
	}
	cout << total << endl;
	
	return 0;
}