#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int N, M, K;//배열크기, 심은 나무 수, 년수
int A[101][101];//추가할 양분 정보
int energy[101][101];//현재 양분정보
vector<int> tree[11][11]; //저장된 나무 정보, 나이를 가진다.

void springSum()
{
	vector<int> liveTree[11][11];
	vector<int> deadTree[11][11];

	//나무가 소팅된 채로 있어야 한다.(작은 나무부터 양분 줘야 함)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].size() > 1) {
				sort(tree[i][j].begin(), tree[i][j].end());
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			vector<int>::iterator iter;
			for (iter = tree[i][j].begin(); iter != tree[i][j].end(); iter++) {
				//아무것도 없으면 안돌겠지
				int age = *iter;
				if (energy[i][j] >= age) {//양분줄 수 있으면 준다.
					energy[i][j] -= age;
					liveTree[i][j].push_back(*iter + 1);
				}
				else {//쥬금
					deadTree[i][j].push_back(age);
				}
			}

		}
	}
	//살아남은 나무로 스왑
	swap(tree, liveTree);

	//여름
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			vector<int>::iterator iter;
			for (iter = deadTree[i][j].begin(); iter != deadTree[i][j].end(); iter++) {
				energy[i][j] += int((*iter) / 2);
			}
		}
	}


	return;
}
void atum()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			vector<int>::iterator iter;
			for (iter = tree[i][j].begin(); iter != tree[i][j].end(); iter++) {
				if (*iter % 5 == 0) {
					//나이가 5의 배수라면 번식!
					for (int r = i - 1; r <= i + 1; r++) {
						for (int c = j - 1; c <= j + 1; c++) {
							if (r == i && c == j) continue; //자기자신
							if (r <= 0 || r > N || c <= 0 || c > N) continue; //바깥
							tree[r][c].push_back(1);//나무추가
						}
					}

				}
			}
		}
	}
	return;
}
void wint()
{

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			energy[i][j] += A[i][j];//양분추가
		}
	}
	return;
}
int main()
{
	/*
		N이 10 이하인거 보니까..
		M개의 나무
		땅은 처음에 양분이 5로 시작
		계절
		 > 봄: 자신의 나이만큼 양분 먹기 + 나이 1 증가
		 (한칸에 여러 나무가 있으면 나이가 어린 나무부터 양분을 먹음.
		 양분 못먹으면 바로 사망)
		 > 여름: 봄에 죽은 나무가 양분으로 변화(죽은나무나이/2), 소수점 버림
		 > 가을: 5의배수 나이인 나무는 인접한 8개의 칸에 나이가 1인 나무 생성
		 > 겨울: s2d2가 양분 추가(input으로 주어짐)

		K년 후 나무의 개수는?
	*/
	//입력
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			energy[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int r, c, age;
		cin >> r >> c >> age;
		tree[r][c].push_back(age);
	}

	//K년간 성장!
	while (K > 0) {
		//봄+여름
		springSum();
		//가을
		atum();
		//겨울
		wint();

		K--;
	}
	//살아있는 나무 개수 출력
	int result = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			vector<int>::iterator iter;
			for (iter = tree[i][j].begin(); iter != tree[i][j].end(); iter++) {
				result++;
			}
		}
	}
	cout << result << endl;

	return 0;
}