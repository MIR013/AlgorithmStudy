#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;

//상우하좌
int dirx[4] = { -1,0,1,0 };
int diry[4] = { 0,1,0,-1 };

typedef struct brick {
	int nodex;
	int nodey;
	int numBrick;
};

int **flag; //노드 방문 여부
//★ 최소 벽돌의 수를 구하는 것이기 떄문에 큰 값으로 초기화 해 둘것!
int **wall; // (i,j)에 가기위해 깨야하는 벽의 수

//Heap을 위해 priority_queue STL구현
struct cmp {
	bool operator()(brick a, brick b) {
		//내림차순
		return (a.numBrick > b.numBrick);
	}
};
priority_queue<brick, vector<brick>, cmp> min_heap;

//input
int N, M;
int **maze;

void dijkstra()
{
	//초기화
	wall[1][1] = 0;
	brick start; 
	start.nodex = 1; start.nodey = 1; start.numBrick = 0;
	min_heap.push(start);

	//pq보면서 탐색
	while (!min_heap.empty())
	{
		brick current = min_heap.top();
		min_heap.pop(); //앞에서 종료
		//종료조건
		if (current.nodex == N && current.nodey == M)
			break;

		if (flag[current.nodex][current.nodey] == 0) {
			//비교-상우하좌
			for (int i=0; i < 4; i++)
			{
				brick next;
				next.nodex = current.nodex + dirx[i];
				next.nodey = current.nodey + diry[i];

				//테두리 벗어나는 것
				if (next.nodex < 1 || next.nodex > N || next.nodey < 1 || next.nodey > M)
					continue;

				if (flag[next.nodex][next.nodey] == 0)
				{
					//방문안한 노드만 방문한다 그래도 최소인 곳만 골라서 가기에 최종도 최소가 될 것이다.
					// 벽을 뚫어야 하는가
					int nextBrick = 0;
					if (maze[next.nodex][next.nodey] == 1) {
						nextBrick = wall[current.nodex][current.nodey] + 1; //벽 o
					}
					else {
						nextBrick = wall[current.nodex][current.nodey];//벽 x
					}

					// 최소값 선택
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
		flag[current.nodex][current.nodey] = 1; //이 노드의 탐색은 끝났다.
	}

	return;
}
int main()
{

	scanf("%d %d", &M, &N);

	//동적할당
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