#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int R, C, M;//��, ��, ����� ��
int fishman = 0;//���ò��� ���� ��ġ(c������ �����δ�)
int total_size = 0;
typedef struct shark {
	int speed;
	int size; //�� -1�̸� ���� �ɷ� ����
	int dir; //��:1 �Ʒ�:2 ������:3 ����:4
};
vector<shark> map[101][101];//����� ��ġ ����

void printMap()
{
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			printf("%2d ", map[i][j][0].size);
		}
		printf("\n");
	}
	printf("\n");

}
bool nextValue(int *nexts, int init, int end, int speed)//���۰�, ó�� ����, �迭�� �������, ������ �Ÿ�
{
	int time = 0;
	int initdir = init;
	while (time < speed) {
		//������ �� ���⺯���ؾ��ϴ�..
		*nexts += init;
		//�׵θ� ���� ���
		if (*nexts < 1 || *nexts > end) {
			init = -init;//���⺯��
			*nexts += (2 * init);
		}
		time++;
	}
	//���Ⱚ�� ����ȴٸ� �̰͵� �˷������
	if (initdir != init) {
		return false;//�����
	}
	return true;
}
shark sortShark(vector<shark> arr)
{
	int maxIndex = -1;
	int maxValue = -1;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].size > maxValue) {
			maxValue = arr[i].size;
			maxIndex = i;
		}
	}

	return arr[maxIndex];
}
void eatShark()
{
	//��ø�� �� �ִٸ� �����ؼ� ���� ū�ָ� �����.
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j].size() > 1) {
				shark temp = sortShark(map[i][j]);
				map[i][j].erase(map[i][j].begin(), map[i][j].end());
				map[i][j].push_back(temp);
			}
		}
	}

	return;
}
void moveShark()
{
	//�ϳ��ϳ����� �����Խô�..
	//=> �������� �ߺ������� �׳� ũ�� ���ϸ� �ذ�� ��
	//¶�� ���� ū ����Ⱑ �����ϱ�

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			//�� �����Ѵٸ�
			if (map[i][j][0].size != -1) {
				int dir = map[i][j][0].dir;
				int speed = map[i][j][0].speed;
				int nextx = i, nexty = j;
				int time = 0;
				//�̵� + �׵θ� Ȯ��
				switch (dir) {
				case 1:
					if (!nextValue(&nextx, -1, R, speed)) {
						map[i][j][0].dir = 2;//������ȯ
					}
					nexty = j;
					break;
				case 2:
					if (!nextValue(&nextx, 1, R, speed)) {
						map[i][j][0].dir = 1;//������ȯ
					}
					nexty = j;
					break;
				case 3:
					nextx = i;
					if (!nextValue(&nexty, 1, C, speed)) {
						map[i][j][0].dir = 4;
					}
					break;
				case 4:
					nextx = i;
					if (!nextValue(&nexty, -1, C, speed)) {
						map[i][j][0].dir = 3;
					}
					break;
				}

				//���ڸ��� �� �ִ���...?
				//�̰� �� �����̰� �� �Ŀ� ũ����ؾ��� �� ������
				//��� �̵�
				map[nextx][nexty].push_back(map[i][j][0]);
				//���� �ִ� �� ������(����)
				map[i][j][0].size = -1;

			}
		}
	}

}
void getShark(int here)
{
	//���⼭�� �ݵ�� 0�� �� �� ����
	for (int i = 1; i <= R; i++)
	{
		//������ �������ȼ� �� Ȯ���Ѵ�.
		if (map[i][here][0].size != -1)
		{
			//��� ����
			total_size += map[i][here][0].size;

			map[i][here][0].dir = 0;
			map[i][here][0].size = -1;
			map[i][here][0].speed = 0;
			break;
		}

	}

	return;
}

int main()
{
	cin >> R >> C >> M;
	int num = 0;//����� �ε��� �ο�

	//�ʱ�ȭ
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			map[i][j].push_back({ -1,-1,-1 });
		}
	}

	for (int i = 0; i < M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		shark temp;
		temp.speed = s;
		temp.dir = d;
		temp.size = z;
		map[r][c][0] = temp;
	}

	//printMap();


	while (fishman < C) {
		//���ÿ��� ���������� ������
		fishman++;
		//������
		getShark(fishman);
		//��� �̵�
		moveShark();
		//��� �Ա�
		eatShark();

		//printMap();
	}

	cout << total_size << endl;

	return 0;
}