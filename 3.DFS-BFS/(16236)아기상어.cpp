#include<iostream>
#include<algorithm>
#include<queue>
#include<stdio.h>

using namespace std;

typedef struct shark {
	int row;
	int col;
	int size; //���� ũ��
	int swim; //�̵��Ÿ�
};
struct cmp {
	bool operator()(shark t, shark u) {
		return t.swim < u.swim; // min heap
	}
};
int N;
int map[21][21];
int isVisited[21][21] = { 0, }; // �Ʊ�� �湮�ߴ��� ���θ� ���� �ּҰ��̹Ƿ� ���� ���ʿ� ����
shark baby; // ���� ������ ��
int dirx[4] = { -1,0,0,1 };//���¿���
int diry[4] = { 0,-1,1,0 };
int ate = 0; //�Ծ��� ����� ��
bool isescape = 0;

void printmap()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void BFS()
{
	while (1)
	{
		//bfs - �Ʊ�� ����� ������ �ٽ� ������(baby�� ���� ������ ��)
		shark candy; //�ĺ���! - ���ؾ��ҵ�..
		candy.swim = 0;
		//queue clear - ���⼭ �����ϸ� �ڵ� clear����...?
		queue<shark> pq; //�̷��� �Ÿ� ª�� �� ���� ������...?
		//isVisited clear
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				isVisited[i][j] = 0;
			}
		}
		pq.push(baby); // init push
		isescape = 0;
		isVisited[baby.row][baby.col] = 0;//�Ʊ����ڸ��� ������

		//printf("-------------\n");
		//printmap();

		while (!pq.empty()) {
			//pop
			shark now = pq.front();
			pq.pop();

			//now�� �ĺ����� �־����� ������ �� ���� -> �ĺ��ִ¾� �԰� ������
			if (now.swim >= candy.swim && candy.swim!=0) {
				//�����ġ�� ��ȯ
				map[candy.row][candy.col] = 9;
				map[baby.row][baby.col] = 0;
				//����⸦ �Ծ��� -> baby�ٽþ��� + break + ���� 0����
				baby.row = candy.row; baby.col = candy.col;
				baby.swim = candy.swim;

				ate++;
				//���� ���� ����⸦ �Ծ����� ũ�� Ŀ��
				if (ate == baby.size) {
					baby.size++;
					ate = 0;//�ٽ� 0����
				}
				isescape = 1;
				break; //�̷� ���� for���� ��������....!
			}


			//�����Ͽ� + �׵θ� + ����⸦ ���� ������ �� �ִ��� = pq�� �ֱ�
			for (int dir = 0; dir < 4; dir++) {
				int nextx = now.row + dirx[dir];
				int nexty = now.col + diry[dir];
				//�׵θ�
				if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= N)
					continue; //�׳� ������
				//0�� ��� �۷� ����
				if (map[nextx][nexty] == 0 && !isVisited[nextx][nexty]) {
					shark new_next;
					new_next.row = nextx; new_next.col = nexty;
					new_next.size = now.size; new_next.swim = now.swim + 1; //��ĭ �̵���!
					pq.push(new_next);
					isVisited[nextx][nexty] = 1;
				}
				//1~6�ΰ�� -> �ڱ� ������� Ȯ��
				if (map[nextx][nexty] > 0 && map[nextx][nexty] < 7 && !isVisited[nextx][nexty]) {
					//ũ�Ⱑ ������ ũ��
					if (baby.size < map[nextx][nexty])//�̰� baby���ص� ���� �ʳ�
					{
						continue; //����
					}
					//ũ�Ⱑ ����
					else if (baby.size == map[nextx][nexty] && !isVisited[nextx][nexty]) {
						//������ ���µ� ������ 0�� �Ȱ���
						shark new_next;
						new_next.row = nextx; new_next.col = nexty;
						new_next.size = now.size; new_next.swim = now.swim + 1; //��ĭ �̵���!
						pq.push(new_next);
						isVisited[nextx][nexty] = 1;
					}
					//ũ�Ⱑ �۴�
					else if (now.size > map[nextx][nexty] && !isVisited[nextx][nexty])
					{
						//�ϴ� �ĺ��� �ְ� ��
						//�ĺ��� �ƹ��͵� ������ ���� ����
						if (candy.swim == 0) {
							candy.row = nextx; candy.col = nexty;
							candy.size = now.size;
							candy.swim = now.swim + 1;
							isVisited[nextx][nexty] = 1;
							pq.push(candy);//�ϴ� �־��..
						}
						else {
							//���ʿ� �ĺ��� ū�� �� ���� �� ����
							if (candy.swim == now.swim + 1) { //�� 1ĭ �� �ֵ��� ���ϱ�
								//���� ��� ��->������ ����
								if (nextx < candy.row) {
									//���ο°� ���� �ִ� - �� �ĺ���
									candy.row = nextx; candy.col = nexty;
									candy.size = now.size;
									candy.swim = now.swim + 1;
									isVisited[nextx][nexty] = 1;
									pq.push(candy);
								}
								else if (nextx == candy.row) {
									//���ο°� ���� �ڸ��� �ִ�
									if (nexty < candy.col) {
										//������ �ִ°� ���� - �� �ĺ���
										candy.row = nextx; candy.col = nexty;
										candy.size = now.size;
										candy.swim = now.swim + 1;
										isVisited[nextx][nexty] = 1;
										pq.push(candy);
									}
									else {
										//�����ʿ� �ִ� - �ĺ��� �ȳ���
									}
								}
								else {
									//���ο°� �Ʒ��� �ִ�. - �ĺ��� �ȳ���
								}
							}
							else {
								//���� ���� �� ����
								printf("error!\n");
							}
						}

					}
				}

			}
			//Ż��
			if (isescape)
				break;
		}
		// bfs�� �������� queue�� ��������� ���̻� �� ���� ���ٴ� ��
		// �ٵ� ����⸦ �ȸԾ���� ��
		if (pq.empty() && !isescape) {
			printf("%d\n", baby.swim);
			break;
		}

	}

	return;
}
int main()
{
	scanf("%d", &N);
	//input
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				//�Ʊ��� ó�� ��ġ ����
				baby.row = i; baby.col = j;
				baby.size = 2; baby.swim = 0;
			}
		}
	}
	BFS();
	return 0;
}