#include<iostream>
using namespace std;


int N, M;
int map[500][500];
int maxSum = -1;
pair<int, int> now;//���� ģ��
//�̰� �� ��ģ�� ������
int dirx[14] = {-100, -1,-2,1,2,0,-1,-1,-2,0,-1,1,1,2 };
int diry[14] = {-100, 0,0,0,0,-1,-1,1,1,2,2,1,2,1 };
//�� ��ũ��̳밡 ������ �ϴ� Exist��
pair<int, int> check[19] = { {100,100}, {5,9},{1,7},{1,2},{3,9},{11,13},{5,7},{3,4},{1,9},{7,8},
						{5,11},	{1,11},{7,10},{7,3},{1,6},{9,11},{7,11},{7,9},{1,3} };

void makeExsit(bool e[])
{
	for (int i = 1; i < 14; i++)
	{
		int nextx = now.first + dirx[i];
		int nexty = now.second + diry[i];
		if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= M)//�׵θ��� ��� false
			e[i] = false;
		else//�׵θ� �ƴϸ� �尡���ϱ� true
			e[i] = true;
	}
	return;
}
void technomino()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 1; j++) { //�����ʾְ� �����ϲ�..
			bool Exist[14] = { false, };//����������, ������ ��
			now = make_pair(i, j);
			makeExsit(Exist);
			//������ ��� ã��
			for (int x = 1; x < 19; x++) {
				if (Exist[check[x].first] && Exist[check[x].second]) {//�� ��Ʈ �� �ȴ�!
					//������ �� ��� + �ִ밪 ��
					int sum = (map[now.first][now.second]) +
						(map[now.first][now.second+1]) +
						(map[now.first+dirx[check[x].first]][now.second+diry[check[x].first]]) +
						(map[now.first + dirx[check[x].second]][now.second + diry[check[x].second]]);

					if (sum > maxSum)
						maxSum = sum;
				}
			}
		}
	}
	//���η� �� ��� ã��
	for (int i = 0; i < N-3; i++) {//�� ���������� �ǹ� ���� + �ٷ� �׵θ� ����
		for (int j = 0; j < M; j++) {
			//dir[3]�� ����ϸ� �ǰڱ�
			int sum = (map[i][j]) +	(map[i+1][j]) +	(map[i+2][j]) +	(map[i+3][j]);
			if (sum > maxSum)
				maxSum = sum;
		}
	}
	

	return;
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	technomino();
	cout << maxSum << endl;
	return 0;
}