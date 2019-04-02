#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,L;
int map[101][101];
vector<pair<int, int> > slide; //(ó������ ��, ���� �Ÿ��� ����
int total = 0;

void pass()
{
	bool canGo = true;
	for (int j = 0; j < slide.size() - 1; j++) {
		if (slide[j].first - slide[j + 1].first == 1) {//���ʿ� �ִ°� ��ĭ Ŭ��
			if (slide[j + 1].second >= L) {
				slide[j + 1].second -= L;
			}else {//���� �������� �����°Ŵ� fail
				canGo = false;
				break;
			}
		}
		else if (slide[j].first - slide[j + 1].first == -1) {//�����ʿ� �ִ°� �� ĭ Ŭ��
			if (slide[j].second >= L) {
				slide[j].second -= L;
			}else {
				canGo = false;
				break;
			}
		}
		else if (slide[j].first - slide[j + 1].first == 0) {//���̰� �ȳ��� -> �׳� ������
			continue;
		}
		else {//���̰� 2�̻� ���� -> �� �������
			canGo = false;
			break;
		}

	}
	//���� �������� �ƴ��� �Ǵ�
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

		//���� �����鼭 �ٷ� ó�� �����ϴ�.
		int l = 1;
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] == map[i][j + 1]) {//�ڿ� �Ŷ� ������ l�� ����
				l++; 
				//N������� ������?
				if (j + 1 == N-1) {
					slide.push_back({ map[i][j+1],l });
				}
			}
			else {//�ڿ��Ŷ� �ٸ��� ���
				slide.push_back({ map[i][j],l });
				//N��°�� �ٸ��Ŷ��?
				if (j + 1 == N-1) {
					slide.push_back({ map[i][j + 1],1 });
				}
				l = 1;
			}
		}
		
		pass();
		slide.clear();
	}

	//�� üũ
	for (int i = 0; i < N; i++) {
		int l = 1;
		for (int j = 0; j < N - 1; j++) {
			if (map[j][i] == map[j+1][i]) {//�ڿ� �Ŷ� ������ l�� ����
				l++;
				//N������� ������?
				if (j + 1 == N - 1) {
					slide.push_back({ map[j + 1][i],l });
				}
			}
			else {//�ڿ��Ŷ� �ٸ��� ���
				slide.push_back({ map[j][i],l });
				//N��°�� �ٸ��Ŷ��?
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