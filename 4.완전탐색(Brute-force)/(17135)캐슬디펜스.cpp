#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int N, M, D;
int map[16][16];
vector<pair<int, int> > enemy;
vector<int> stack; //arraw의 index를 가진 조합 생성!
int maxE = -1;



void findA(int index)
{
	//종료조건
	if (stack.size() == 3) {
		int total = 0;
		//이 궁수 상태일때, 적이 모두 없어질때까지 반복!

		vector<pair<int, int> > temp_enemy;
		for (int i = 0; i < enemy.size(); i++)//swap
			temp_enemy.push_back(enemy[i]);
		while (!temp_enemy.empty())
		{
			//궁수가 적을 죽일 수 있으면 죽인다. - 맞으면 죽음

			pair<int, int> candy[3] = { { 0,0 }, }; //거리,index
			for (int i = 0; i < 3; i++)//궁수는 3명
			{
				int arrowy = stack[i]; int arrowx = N;
				//죽일 수 있는 모든 적을 보고 가장 가까운것 > 왼쪽에 있는것을 먼저 죽인다.
				for (int j = 0; j < temp_enemy.size(); j++)
				{ 
					int ex = temp_enemy[j].first;
					int ey = temp_enemy[j].second;
					int distance = abs(arrowx - ex) + abs(arrowy - ey);
					if (distance <= D) {
						if (candy[i].first==0)
							candy[i] = make_pair(distance, j);
						else {
							//거리가 가까우면 변경
							if (distance < candy[i].first) {
								candy[i] = make_pair(distance, j);
							}
							//거리가 같고 왼쪽거라면 변경
							else if (distance == candy[i].first) {
								if (temp_enemy[j].second < temp_enemy[candy[i].second].second) {//y값을 비교해야함
									//좀 더 왼쪽거다
									candy[i] = make_pair(distance, j);
								}
								//같거나 오른쪽 꺼면 상관 없음
							}
							//거리가 멀면 상관 없음

						}
					}
				}

			}

			//궁수가 동시에 쏘니까.. 쏜애들 삭제
			int aliveIndex[999] = { 0, };
			for (int i = 0; i < 3; i++) {
				if(candy[i].first)
					aliveIndex[candy[i].second] = 1;
			}

			vector<pair<int, int> > temp2;
			int index = 0;
			for (int i = 0; i < temp_enemy.size(); i++) {
				if (!aliveIndex[i]) {
					temp2.push_back(temp_enemy[i]);
				}
				else {
					//죽은 애들의 자리
					total++;
				}
			}
			temp_enemy.clear();
			for (int i = 0; i < temp2.size(); i++)//남은 적 넣음
				temp_enemy.push_back(temp2[i]);





			//적이 아래로 움직인다. - N+1로가면 죽음
			vector<pair<int, int> > temp;
			for (int i = 0; i < temp_enemy.size(); i++) {
				int nextx = temp_enemy[i].first + 1;
				int nexty = temp_enemy[i].second;
				if (nextx != N) {
					temp.push_back(make_pair(nextx, nexty));
				}
			}

			temp_enemy.clear();
			for (int i = 0; i < temp.size(); i++)//남은 적 넣음
				temp_enemy.push_back(temp[i]);


		}
		//최대 공격회수 비교
		if (total > maxE)
			maxE = total;
			

		stack.pop_back();
		return;
	}

	//진행조건
	for (int i = index + 1; i < M; i++) {
		stack.push_back(i);
		findA(i);
	}

	//끝
	stack.pop_back();
	return;
}
int main()
{
	/*
		격자판 하나에 들어갈 수 있는 적의 최대 수는 1
		N+1에는 성이 있다.
		궁수 3명 - 성에만 배치 가능, 한칸에 최대 1명
					거리가 D 이하인 적 중 가까운 적 공격 가능, 많으면 왼쪽부터
					같은 적이 여러 궁수에게 당할 수 있음
					공격받은 적은 out
					공격이 끝나면 적이 아래로 한칸 이동한다.
					성으로 이동할 경우 게임에서out
					모든 적이 없어지면 게임 종료
		거리 = |r1-r2|+|c1-c2|
		궁수의 공격으로 제거할 수 있는 적의 최대 수
	*/
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j])
				enemy.push_back(make_pair(i, j));
		}
	}


	//조합으로 궁수의 위치를 찾자
	for (int i = 0; i < M; i++) {
		stack.push_back(i);
		findA(i);
	}

	cout << maxE << endl;


	return 0;
}