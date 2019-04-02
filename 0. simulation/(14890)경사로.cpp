#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,L;
int map[101][101];
vector<pair<int, int> > slide; //(처음시작 값, 같은 거리를 저장
int total = 0;

void pass()
{
	bool canGo = true;
	for (int j = 0; j < slide.size() - 1; j++) {
		if (slide[j].first - slide[j + 1].first == 1) {//왼쪽에 있는게 한칸 클때
			if (slide[j + 1].second >= L) {
				slide[j + 1].second -= L;
			}else {//경사로 못놓으면 못가는거니 fail
				canGo = false;
				break;
			}
		}
		else if (slide[j].first - slide[j + 1].first == -1) {//오른쪽에 있는게 한 칸 클때
			if (slide[j].second >= L) {
				slide[j].second -= L;
			}else {
				canGo = false;
				break;
			}
		}
		else if (slide[j].first - slide[j + 1].first == 0) {//차이가 안날때 -> 그냥 지나감
			continue;
		}
		else {//차이가 2이상 날때 -> 길 못만든다
			canGo = false;
			break;
		}

	}
	//길이 가능한지 아닌지 판단
	if (canGo) {
		total++;
	}

	return;
}
int main()
{
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}

		//행은 들어오면서 바로 처리 가능하다.
		int l = 1;
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] == map[i][j + 1]) {//뒤에 거랑 같으면 l만 증가
				l++; 
				//N번재까지 같으면?
				if (j + 1 == N-1) {
					slide.push_back({ map[i][j+1],l });
				}
			}
			else {//뒤에거랑 다르면 등록
				slide.push_back({ map[i][j],l });
				//N번째가 다른거라면?
				if (j + 1 == N-1) {
					slide.push_back({ map[i][j + 1],1 });
				}
				l = 1;
			}
		}
		
		pass();
		slide.clear();
	}

	//열 체크
	for (int i = 0; i < N; i++) {
		int l = 1;
		for (int j = 0; j < N - 1; j++) {
			if (map[j][i] == map[j+1][i]) {//뒤에 거랑 같으면 l만 증가
				l++;
				//N번재까지 같으면?
				if (j + 1 == N - 1) {
					slide.push_back({ map[j + 1][i],l });
				}
			}
			else {//뒤에거랑 다르면 등록
				slide.push_back({ map[j][i],l });
				//N번째가 다른거라면?
				if (j + 1 == N - 1) {
					slide.push_back({ map[j + 1][i],1 });
				}
				l = 1;
			}
		}
		pass();
		slide.clear();
	}

	
	cout << total << endl;

	return 0;
}