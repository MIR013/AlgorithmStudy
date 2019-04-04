#include<iostream>
using namespace std;


int N, M;
int map[500][500];
int maxSum = -1;
pair<int, int> now;//왼쪽 친구
//이거 맨 앞친구 기준임
int dirx[14] = {-100, -1,-2,1,2,0,-1,-1,-2,0,-1,1,1,2 };
int diry[14] = {-100, 0,0,0,0,-1,-1,1,1,2,2,1,2,1 };
//각 테크노미노가 가져야 하는 Exist들
pair<int, int> check[19] = { {100,100}, {5,9},{1,7},{1,2},{3,9},{11,13},{5,7},{3,4},{1,9},{7,8},
						{5,11},	{1,11},{7,10},{7,3},{1,6},{9,11},{7,11},{7,9},{1,3} };

void makeExsit(bool e[])
{
	for (int i = 1; i < 14; i++)
	{
		int nextx = now.first + dirx[i];
		int nexty = now.second + diry[i];
		if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= M)//테두리일 경우 false
			e[i] = false;
		else//테두리 아니면 드가지니까 true
			e[i] = true;
	}
	return;
}
void technomino()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 1; j++) { //오른쪽애가 있으니께..
			bool Exist[14] = { false, };//여기있을때, 가능한 곳
			now = make_pair(i, j);
			makeExsit(Exist);
			//적합한 모양 찾기
			for (int x = 1; x < 19; x++) {
				if (Exist[check[x].first] && Exist[check[x].second]) {//두 세트 다 된다!
					//내부의 합 계산 + 최대값 비교
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
	//세로로 긴 모양 찾기
	for (int i = 0; i < N-3; i++) {//더 내려가봤자 의미 없음 + 바로 테두리 제어
		for (int j = 0; j < M; j++) {
			//dir[3]을 사용하면 되겠군
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