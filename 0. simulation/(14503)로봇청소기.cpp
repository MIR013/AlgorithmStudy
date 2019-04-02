#include<iostream>
using namespace std;

int N, M;
//0:��, 1:��, 2:��, 3:��
int dirx[4] = { 0,-1,0,1 };//�� ������ ���� ǥ��
int diry[4] = { -1,0,1,0 }; //��,��,��,��
int map[51][51];
int clean[51][51] = { 0 };
int totalClean = 0;

void vaccum(int r, int c, int d)
{
	/*
		��������� �������� ����
		���ư��� �� ���� ��͸� ����� �� ������
		���������� ���ο� �ִ� ���..
	*/
	bool isRun = true;
	while (isRun) {
		//printf("(%d %d-%d)\n", r, c,d);
		//�������� - 4���� Ž��
		if (!clean[r][c] && !map[r][c]) {//���� ��ġ�� û���� �� ���� ���->������������ û���ϸ� �ȵ�
			clean[r][c] = 1;
			totalClean++;
		}
		int index = 0;
		do {
			//���翡�� ����
			int nextx = r + dirx[d]; int nexty = c + diry[d];

			if (clean[nextx][nexty] == 0 && map[nextx][nexty] == 0) {
				//���ʿ� û��x + ���� �ƴ� ���
				r = nextx; c = nexty; d = (d + 3) % 4;//�� �������� ȸ�� �� ����
				break;
			}
			else if (clean[nextx][nexty] == 1 || map[nextx][nexty] == 1 || nextx < 0 || nextx >= N || nexty < 0 || nexty >= M) {
				//û���� ������ ���� or ���� ��� or �׵θ��� ���
				d = (d + 3) % 4;//���⸸ ȸ���ϰ� ���

				//�� ���� ��� �� �� ���
				if (index == 3) {
					//���� - �̰� ���ʰ� �ٸ�!!
					r = r + dirx[(d + 3) % 4];
					c = c + diry[(d + 3) % 4];
					//������ �Ұ����� ���- �׵θ� or �� �κ� ����
					if (r < 0 || r >= N || c < 0 || c >= M || map[r][c] == 1) {
						isRun = false;
						break;
					}
					//������ ������ ���
					else {
						index = 0;//2������ ���ư���.
						continue;
					}
				}
			}


			index++;
		} while (index < 4);
	}


	return;
}
int main()
{
	int r, c, d;//�κ��� ����

	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	vaccum(r, c, d);
	cout << totalClean << endl;
	return 0;
}