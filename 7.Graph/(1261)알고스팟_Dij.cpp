#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;

//�������
int dirx[4] = { -1,0,1,0 };
int diry[4] = { 0,1,0,-1 };

typedef struct brick {
	int nodex;
	int nodey;
	int numBrick;
};

int **flag; //��� �湮 ����
//�� �ּ� ������ ���� ���ϴ� ���̱� ������ ū ������ �ʱ�ȭ �� �Ѱ�!
int **wall; // (i,j)�� �������� �����ϴ� ���� ��

//Heap�� ���� priority_queue STL����
struct cmp {
	bool operator()(brick a, brick b) {
		//��������
		return (a.numBrick > b.numBrick);
	}
};
priority_queue<brick, vector<brick>, cmp> min_heap;

//input
int N, M;
int **maze;

void dijkstra()
{
	//�ʱ�ȭ
	wall[1][1] = 0;
	brick start; 
	start.nodex = 1; start.nodey = 1; start.numBrick = 0;
	min_heap.push(start);

	//pq���鼭 Ž��
	while (!min_heap.empty())
	{
		brick current = min_heap.top();
		min_heap.pop(); //�տ��� ����
		//��������
		if (current.nodex == N && current.nodey == M)
			break;

		if (flag[current.nodex][current.nodey] == 0) {
			//��-�������
			for (int i=0; i < 4; i++)
			{
				brick next;
				next.nodex = current.nodex + dirx[i];
				next.nodey = current.nodey + diry[i];

				//�׵θ� ����� ��
				if (next.nodex < 1 || next.nodex > N || next.nodey < 1 || next.nodey > M)
					continue;

				if (flag[next.nodex][next.nodey] == 0)
				{
					//�湮���� ��常 �湮�Ѵ� �׷��� �ּ��� ���� ��� ���⿡ ������ �ּҰ� �� ���̴�.
					// ���� �վ�� �ϴ°�
					int nextBrick = 0;
					if (maze[next.nodex][next.nodey] == 1) {
						nextBrick = wall[current.nodex][current.nodey] + 1; //�� o
					}
					else {
						nextBrick = wall[current.nodex][current.nodey];//�� x
					}

					// �ּҰ� ����
					if(wall[next.nodex][next.nodey]> nextBrick)
						wall[next.nodex][next.nodey] = nextBrick;
					next.numBrick = nextBrick;
					min_heap.push(next);
					printf("%d %d\n", next.nodex, next.nodey);
					printf("PQ: ");

					priority_queue<brick, vector<brick>, cmp> nextheap = min_heap;
					for (int i = 0; i < nextheap.size(); i++) {
						printf("(%d %d %d) ", nextheap.top().nodex, nextheap.top().nodey, nextheap.top().numBrick);
						nextheap.pop();
					}
					printf("\n");
				}
			}
		}
		flag[current.nodex][current.nodey] = 1; //�� ����� Ž���� ������.
	}

	return;
}
int main()
{

	scanf("%d %d", &M, &N);

	//�����Ҵ�
	maze = (int**)malloc(sizeof(int*)*N);
	wall = (int**)malloc(sizeof(int*)*N);
	flag = (int**)malloc(sizeof(int*)*N);
	for (int i = 1; i <= N; i++) {
		maze[i] = (int *)malloc(sizeof(int)*M);
		wall[i] = (int *)malloc(sizeof(int)*M);
		flag[i] = (int *)malloc(sizeof(int)*M);
	}

	for (int i = 1; i <= N; i++) {
		char input[200];
		scanf("%s", input);
		for (int j = 0; j < M; j++) {
			maze[i][j + 1] = input[j] - '0';
			wall[i][j + 1] = 999;
			flag[i][j + 1] = 0;
		}
	}

	dijkstra();

	printf("%d", wall[N][M]);
	return 0;
}