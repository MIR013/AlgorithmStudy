#include<stdio.h>
#include<queue>
using namespace std;

//상우하좌
int dirx[4] = { -1,0,1,0 };
int diry[4] = { 0,1,0,-1 };

//for BFS
typedef struct dir {
	int x;
	int y;
};
enum col { WHITE, GRAY, BLACK };
col **color; //노드 방문 여부
//★ 최소 벽돌의 수를 구하는 것이기 떄문에 큰 값으로 초기화 해 둘것!
int **wall; // (i,j)에 가기위해 깨야하는 벽의 수


//input
int N, M;
int **maze;

void BFS()
{
	queue<dir> Q;
	dir start;
	dir current;

	//초기화
	start.x = 1; start.y = 1;
	Q.push(start);
	wall[1][1] = 0;

	//Q가 완전히 없어지거나 n,m에 도착했을때 정지한다.
	while (!Q.empty())
	{
		//앞에거 가져온다
		current = Q.front();

		//상우하좌 체크 & 종료조건 & 테두리 체크
		if (current.x == N && current.y == M)
			break;

		for (int i = 0; i < 4; i++) {
			dir next;
			next.x = current.x + dirx[i];
			next.y = current.y + diry[i];
			//테두리 안에서
			if (next.x >= 1 && next.x <= N && next.y >= 1 && next.y <= M) {
				if (color[next.x][next.y] == WHITE) {
					int nextwall = 0;
					if (maze[next.x][next.y] == 1) {
						//벽일 경우에 wall++, 들렀던 곳이니 회색으로
						nextwall = wall[current.x][current.y] + 1;
					}
					else {
						//벽이 없을 경우 그냥 지나가면 된다.
						nextwall = wall[current.x][current.y];
					}
					//★ min값 저장하기
					if (nextwall < wall[next.x][next.y]) {
						wall[next.x][next.y] = nextwall;
					}

					//queue에 넣기
					//printf("%d %d\n", next.x, next.y);
					Q.push(next);
					//★ 여기는 최소 값을 찾아야 하기에 여러번 접근할 수 있어야 한다.
					//color[next.x][next.y] = GRAY; 	
				}
			}

		}

		//pop
		color[current.x][current.y] = BLACK;
		Q.pop();

	}

	return;
}
int main()
{

	scanf("%d %d", &M, &N);

	//동적할당
	maze = (int**)malloc(sizeof(int*)*N);
	wall = (int**)malloc(sizeof(int*)*N);
	color = (col**)malloc(sizeof(col*)*N);
	for (int i = 1; i <= N; i++) {
		maze[i] = (int *)malloc(sizeof(int)*M);
		wall[i] = (int *)malloc(sizeof(int)*M);
		color[i] = (col *)malloc(sizeof(int)*M);
	}

	for (int i = 1; i <= N; i++) {
		char input[101];
		scanf("%s", input);
		for (int j = 0; j < M; j++) {
			maze[i][j + 1] = input[j] - '0';
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			wall[i][j] = 999;
			color[i][j] = WHITE;
		}
	}

	BFS();

	printf("%d", wall[N][M]);
	return 0;
}