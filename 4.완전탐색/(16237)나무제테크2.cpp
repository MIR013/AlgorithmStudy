#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M, K;
int map[11][11]; //땅의 상태
int s2d2[11][11]; //채워지는 양분
vector<int> tree[11][11]; //나무들의 나이 -> 이렇게 하면 한 이차원 배열 원소값을 벡터타입으로해서 여러가지를 지정할 수 있다.
bool cmp(int a, int b) {
	return a < b; //오름차순
}

void getmoney()
{
	//나무 하나당 사계절을 보내개 짰는데 그게 아니라 나무 여러개가 계절로 계속 가야함;;
	for (int time = 0; time < K; time++)
	{
		vector< pair< pair<int, int>, int> > dead; //죽은 나무의 위치, 나이 저장
		vector<int> live[11][11];//봄에 살아남은 애들 모임

		//봄
		for (int x = 1; x <= N; x++) {
			for (int y = 1; y <= N; y++) {
				for (int age = 0; age < tree[x][y].size(); age++) {
					//어린애부터 양분을 먹는다.
					if (map[x][y] - tree[x][y][age] >= 0)
					{
						//양분을 먹을 수 있다.
						map[x][y] -= tree[x][y][age]; //자기나이만큼 먹고
						live[x][y].push_back(tree[x][y][age] + 1);//1살 증가
						tree[x][y][age]++; //가을 계산하려면 더해야함

						//양분과 관계없으니 가을로 넘어가자
						//가을
						if (tree[x][y][age] % 5 == 0) {
							//나이가 5배수여야 번식함
							for (int i = -1; i <= 1; i++) {
								for (int j = -1; j <= 1; j++) {
									if (i == 0 && j == 0) //나무의 현재위치임
										continue;
									//경계선 체크
									if ((x + i) < 1 || (x + i) > N || (y + j) < 1 || (y + j) > N)
										continue;
									//새로운 나무 등록 - 여기 바로 등록하면 다음해가 아닌 이번해에 양분을 먹음;;
									live[x+i][y+j].push_back(1);
								}
							}
						}
					}
					else {
						//양분을 먹을 수 없다. - 저장 안함
						dead.push_back({ {x,y},tree[x][y][age] }); //양분될 곳에 저장
					}
				}

			}
		}

		int dlen = dead.size();
		//여름 - 죽은애 영양분 보충
		for (int c = 0; c < dlen; c++)
		{
			//자기 나이의 반으로 추가
			map[dead[c].first.first][dead[c].first.second] += (dead[c].second / 2);
		}

		//겨울 - 나무와 관계없으니 pq안씀
		for (int i = 1; i <= N; i++) { //양분 추가
			for (int j = 1; j <= N; j++) {
				map[i][j] += s2d2[i][j];
			}
		}

		
		//살아남은 나무 저장
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				tree[i][j].clear();
				for (int x = 0; x < live[i][j].size(); x++) {
					tree[i][j].push_back(live[i][j][x]);
				}
				//하는김에 소팅
				sort(tree[i][j].begin(), tree[i][j].end(), cmp);
			}
		}


	}
	//남은 나무의 수 계산
	int total = 0;
	for (int i = 1; i <= N; i++) { //양분 추가
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
	for (int i = 1; i <= N; i++) { //배열 index 1부터 시작
		for (int j = 1; j <= N; j++) {
			cin >> s2d2[i][j];//양분 초기화
			map[i][j] = 5;//땅 초기화
		}
	}
	//나무입력
	for (int i = 1; i <= M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}

	getmoney();

	return 0;
}