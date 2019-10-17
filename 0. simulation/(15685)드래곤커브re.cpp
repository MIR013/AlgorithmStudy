#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define SIZE 101

using namespace std;

int map[SIZE][SIZE] = { 0 };
int dirx[4] = { 1,0,-1,0 };
int diry[4] = { 0,-1,0,1 };

void print(int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%1d ", map[i][j]);
		}
		printf("\n");
	}
	printf("================\n");

	return;
}
int checkSquare()
{
	int result = 0;

	//1�� ���� ���� �簢���� �������
	// i+1,j+1,i+1/j+1�� �κ��� ��� 1�̸� �簢�� �ϳ� �ϼ�!
	// ĭ���ʰ��� ����� �ϳ��� �ٿ��� ����
	for (int i = 0; i < SIZE-1; i++) {
		for (int j = 0; j < SIZE-1; j++) {
			if (map[i][j] == 1) {
				if (map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1) {
					result++;
				}
			}
		}
	}

	return result;
}
void dragon(int x, int y, int dir, int g)
{

	//������
	int pointx = x + dirx[dir];
	int pointy = y + diry[dir];
	vector<pair<int, int> > dra;
	vector<int> direction;

	//Ŀ�갡 �� ���� 1�̶�� ����!
	map[y][x] = 1;
	map[pointy][pointx] = 1;
	direction.push_back(dir);
	dra.push_back(make_pair(x, y));
	dra.push_back(make_pair(pointx, pointy));
	//������ ������ �ΰ� ������ ���߿� �״�� �ű�� �ɰ� ������
	/*
	90�� ȸ���ϸ�
	��->��, ��->�Ʒ�, �Ʒ�->��, ��->��
	(����)->(point)�̷� ������
	�ٵ� �̰� ������ ����������� Ȯ���� �� ��
	dra�� �Ųٷ� �����ؾ���!
	*/

	//print(10);

	while (g > 0) 
	{
		//������ �������� ��� ���� 90�� �ð�
		int dsize = direction.size();
		int nextx = dra.back().first;
		int nexty = dra.back().second;

		for (int i = dsize-1; i >= 0; i--)
		{ 
			//�������� �����ϰ� ����
			//����� ���� ���� �߰�!
			switch (direction[i])
			{
			case 0://���� -> ��
				nextx += dirx[1];
				nexty += diry[1];
				direction.push_back(1);
				break;
			case 1://�� ->��
				nextx += dirx[2];
				nexty += diry[2];
				direction.push_back(2);
				break;
			case 2://��->�Ʒ�
				nextx += dirx[3];
				nexty += diry[3];
				direction.push_back(3);
				break;
			case 3://�Ʒ�->��
				nextx += dirx[0];
				nexty += diry[0];
				direction.push_back(0);
				break;
			}

			map[nexty][nextx] = 1;
			dra.push_back(make_pair(nextx, nexty));
		}

		//�� point�� ������ ��� �Ѵ�.
		pointx = dra.back().first;
		pointy = dra.back().second;

		g--;
		//print(10);
	}


	return;
}
int main()
{
	/*
	x���̶� y�� �ݴ������
	//������, ���۹���, ����
	������ �������� �ð�������� 90�� ȸ��
	100*100���� + n���� �巡�� Ŀ��

	Ŀ�� �׸��� -> �簢�� ����ϱ�

	*/

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		dragon(x, y, d, g);
	}

	cout << checkSquare() << endl;


	return 0;
}