#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M, K;
int map[11][11]; //���� ����
int s2d2[11][11]; //ä������ ���
vector<int> tree[11][11]; //�������� ���� -> �̷��� �ϸ� �� ������ �迭 ���Ұ��� ����Ÿ�������ؼ� ���������� ������ �� �ִ�.
bool cmp(int a, int b) {
	return a < b; //��������
}

void getmoney()
{
	//���� �ϳ��� ������� ������ ®�µ� �װ� �ƴ϶� ���� �������� ������ ��� ������;;
	for (int time = 0; time < K; time++)
	{
		vector< pair< pair<int, int>, int> > dead; //���� ������ ��ġ, ���� ����
		vector<int> live[11][11];//���� ��Ƴ��� �ֵ� ����

		//��
		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= N; y++) {
				for (int age = 0; age < tree[x][y].size(); age++) {
					//��ֺ��� ����� �Դ´�.
					if (map[x][y] - tree[x][y][age] >= 0)
					{
						//����� ���� �� �ִ�.
						map[x][y] -= tree[x][y][age]; //�ڱ⳪�̸�ŭ �԰�
						live[x][y].push_back(tree[x][y][age] + 1);//1�� ����
						tree[x][y][age]++; //���� ����Ϸ��� ���ؾ���

						//��а� ��������� ������ �Ѿ��
						//����
						if (tree[x][y][age] % 5 == 0) {
							//���̰� 5������� ������
							for (int i = -1; i <= 1; i++) {
								for (int j = -1; j <= 1; j++) {
									if (i == 0 && j == 0) //������ ������ġ��
										continue;
									//��輱 üũ
									if ((x + i) < 1 || (x + i) > N || (y + j) < 1 || (y + j) > N)
										continue;
									//���ο� ���� ��� - ���� �ٷ� ����ϸ� �����ذ� �ƴ� �̹��ؿ� ����� ����;;
									live[x+i][y+j].push_back(1);
								}
							}
						}
					}
					else {
						//����� ���� �� ����. - ���� ����
						dead.push_back({ {x,y},tree[x][y][age] }); //��е� ���� ����
					}
				}

			}
		}

		int dlen = dead.size();
		//���� - ������ ����� ����
		for (int c = 0; c < dlen; c++)
		{
			//�ڱ� ������ ������ �߰�
			map[dead[c].first.first][dead[c].first.second] += (dead[c].second / 2);
		}

		//�ܿ� - ������ ��������� pq�Ⱦ�
		for (int i = 1; i <= N; i++) { //��� �߰�
			for (int j = 1; j <= N; j++) {
				map[i][j] += s2d2[i][j];
			}
		}

		
		//��Ƴ��� ���� ����
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				tree[i][j].clear();
				for (int x = 0; x < live[i][j].size(); x++) {
					tree[i][j].push_back(live[i][j][x]);
				}
				//�ϴ±迡 ����
				sort(tree[i][j].begin(), tree[i][j].end(), cmp);
			}
		}


	}
	//���� ������ �� ���
	int total = 0;
	for (int i = 1; i <= N; i++) { //��� �߰�
		for (int j = 1; j <= N; j++) {
			total += tree[i][j].size();
		}
	}
	printf("%d", total);

	return;
}
int main()
{

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) { //�迭 index 1���� ����
		for (int j = 1; j <= N; j++) {
			cin >> s2d2[i][j];//��� �ʱ�ȭ
			map[i][j] = 5;//�� �ʱ�ȭ
		}
	}
	//�����Է�
	for (int i = 1; i <= M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}

	getmoney();

	return 0;
}