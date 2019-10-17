#include<stdio.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;

int N, L, R;
int A[101][101];
bool isMove = false; //�α��̵� �ߴ���...?
int dirx[4] = { -1,0,1,0 };
int diry[4] = { 0,1,0,-1 };


void printAll(int arr[][101])
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("======================\n");
	return;
}
void movePeople(int r,int c, int visited[][101])//�α��̵�
{
	//�̰� ���� ����°� ��ü�� bfs�� �ϰ� �����¿� �� ����
	queue<pair<int, int> > queue;
	vector<pair<int, int> > stack;//�̰� �� �����Ҷ� ����� ��
	int sum = 0;

	queue.push(make_pair(r, c));
	stack.push_back(make_pair(r, c));
	visited[r][c] = 1;
	sum = A[r][c];

	while (!queue.empty()) 
	{
		int nowx = queue.front().first;
		int nowy = queue.front().second;
		queue.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nextx = nowx + dirx[dir];
			int nexty = nowy + diry[dir];
			if (nextx <= 0 || nextx > N || nexty <= 0 || nexty > N) continue; //����̻�
			if (visited[nextx][nexty]) continue; //�̹� �湮�� ��
			//������ �� �� �ִٸ� ó��
			int diff = abs(A[nowx][nowy] - A[nextx][nexty]);
			if (diff >= L && diff <= R) {
				visited[nextx][nexty] = 1;
				stack.push_back(make_pair(nextx, nexty));
				queue.push(make_pair(nextx, nexty));
				sum += A[nextx][nexty];
			}
		}

	}
	//�α��̵�
	if (stack.size() > 1)
	{
		int average = int(sum / stack.size());
		vector<pair<int, int> >::iterator iter;
		for (iter = stack.begin(); iter != stack.end(); iter++) {
			A[iter->first][iter->second] = average;
		}
		isMove = true;
	}


	return;
}
int main()
{
	/*
	N: ����ũ��
	A: �α���

	*/
	//����
	int visited[101][101] = { 0 };
	int result = -1;//�α��̵� �߻� Ƚ�� - ó���� �ݵ�� ���� ������ -1

	//�Է�
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	do {
		//�α��̵� - bfs
		//printAll(A);

		//�ʱ�ȭ
		isMove = false;
		memset(visited, 0, sizeof(visited));

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!visited[i][j])
					movePeople(i, j, visited);
			}
		}
		result++;
	} while (isMove);

	//���
	cout << result << endl;

	return 0;
}