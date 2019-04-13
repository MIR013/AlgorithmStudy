#include<iostream>

using namespace std;

//UP=0,DOWN=1,LEFT=2,RIGHT=3
int dirx[4] = { -1,1,0,0 };//�����¿�
int diry[4] = { 0,0,-1,1 };
int N;
int input[101][101];
int maximum = -1;
int score = 0;
int startx, starty;
// �̸� �����ص���...!
pair<int, int> hall1[11];
pair<int, int> hall2[11];

void for_moving(int nextx, int nexty, int whereis)
{
	while (1) {
		//ó�� ��ġ�� ���ƿԴ°�?
		if (nextx == startx && nexty == starty) {
			break;
		}
		//üũ
		if (nexty < 0 || (whereis == 1 && input[nextx][nexty] == 1) || (whereis == 0 && input[nextx][nexty] == 2) || \
			(whereis == 2 && input[nextx][nexty] == 3) || (whereis == 2 && input[nextx][nexty] == 4) || \
			(whereis == 2 && input[nextx][nexty] == 5)) {
			//���������� ƨ�ܳ���
			score++;
			nextx += dirx[3]; nexty += diry[3]; whereis = 3;
		}
		else if (nexty >= N || (whereis == 3 && input[nextx][nexty] == 1) || (whereis == 3 && input[nextx][nexty] == 2) || \
			(whereis == 0 && input[nextx][nexty] == 3) || (whereis == 1 && input[nextx][nexty] == 4) || \
			(whereis == 3 && input[nextx][nexty] == 5)) {
			//�������� ƨ�ܳ���
			score++;
			nextx += dirx[2]; nexty += diry[2]; whereis = 2;
		}
		else if (nextx < 0 || (whereis == 0 && input[nextx][nexty] == 1) || (whereis == 2 && input[nextx][nexty] == 2) || \
			(whereis == 3 && input[nextx][nexty] == 3) || (whereis == 0 && input[nextx][nexty] == 4) || \
			(whereis == 0 && input[nextx][nexty] == 5)) {
			//�Ʒ��� ƨ�ܳ���
			score++;
			nextx += dirx[1]; nexty += diry[1]; whereis = 1;
		}
		else if (nextx >= N || (whereis == 2 && input[nextx][nexty] == 1) || (whereis == 1 && input[nextx][nexty] == 2) || \
			(whereis == 1 && input[nextx][nexty] == 3) || (whereis == 3 && input[nextx][nexty] == 4) || \
			(whereis == 1 && input[nextx][nexty] == 5)) {
			//���� ƨ�ܳ���
			score++;
			nextx += dirx[0]; nexty += diry[0]; whereis = 0;
		}
		//6~10
		else if (input[nextx][nexty] > 5 && input[nextx][nexty] < 11)
		{
			//���� x
			if (hall1[input[nextx][nexty]].first == nextx && hall1[input[nextx][nexty]].second == nexty) {
				//hall1�� ������ hall2�� �̵�
				int bnextx = hall2[input[nextx][nexty]].first + dirx[whereis];
				int bnexty = hall2[input[nextx][nexty]].second + diry[whereis];
				nextx = bnextx; nexty = bnexty;
			}
			else {
				int bnextx = hall1[input[nextx][nexty]].first + dirx[whereis];
				int bnexty = hall1[input[nextx][nexty]].second + diry[whereis];
				nextx = bnextx; nexty = bnexty;
			}
		}
		//-1
		else if (input[nextx][nexty] == -1) {
			break;
		}
		else {
			//�׳� ������
			nextx += dirx[whereis]; nexty += diry[whereis];
		}
	}
	return;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		//hall1,hall2�ʱ�ȭ
		for (int i = 6; i <= 10; i++)
		{
			hall1[i] = make_pair(-1, -1);
			hall2[i] = make_pair(-1, -1);
		}
		//input
		//scanf("%d", &N);
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++) {
				cin >> input[i][j];
				//scanf("%d", &input[i][j]);
				if (input[i][j] > 5 && input[i][j] < 11) {
					//hall ���
					if (hall1[input[i][j]].first != -1) {
						//hall1�� ������ 2�� ���
						hall2[input[i][j]].first = i;
						hall2[input[i][j]].second = j;
					}
					else {
						hall1[input[i][j]].first = i;
						hall1[input[i][j]].second = j;
					}
				}
			}
		}

		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < N; y++) {
				//��ĭ���� ���� �ִ´�
				if (input[x][y] != 0)
					continue;
				startx = x; starty = y;
				//�����¿�
				for (int d = 0; d < 4; d++)
				{
					score = 0;
					int nextx = x + dirx[d];
					int nexty = y + diry[d];
					for_moving(nextx, nexty, d);
					if (score > maximum) {
						maximum = score;
					}
				}

			}
		}
		//printf("#%d %d\n", test_case, maximum);
		cout << "#" << test_case << " " << maximum << endl;
		maximum = -1;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}