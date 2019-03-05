#include<stdio.h>
#include<queue>
using namespace std;

//�������
int dirx[4] = { -1,0,1,0 };
int diry[4] = { 0,1,0,-1 };

//for BFS
typedef struct dir {
	int x;
	int y;
};
enum col { WHITE, GRAY, BLACK };
col **color; //��� �湮 ����
//�� �ּ� ������ ���� ���ϴ� ���̱� ������ ū ������ �ʱ�ȭ �� �Ѱ�!
int **wall; // (i,j)�� �������� �����ϴ� ���� ��


//input
int N, M;
int **maze;

void BFS()
{
	queue<dir> Q;
	dir start;
	dir current;

	//�ʱ�ȭ
	start.x = 1; start.y = 1;
	Q.push(start);
	wall[1][1] = 0;

	//Q�� ������ �������ų� n,m�� ���������� �����Ѵ�.
	while (!Q.empty())
	{
		//�տ��� �����´�
		current = Q.front();

		//������� üũ & �������� & �׵θ� üũ
		if (current.x == N && current.y == M)
			break;

		for (int i = 0; i < 4; i++) {
			dir next;
			next.x = current.x + dirx[i];
			next.y = current.y + diry[i];
			//�׵θ� �ȿ���
			if (next.x >= 1 && next.x <= N && next.y >= 1 && next.y <= M) {
				if (color[next.x][next.y] == WHITE) {
					int nextwall = 0;
					if (maze[next.x][next.y] == 1) {
						//���� ��쿡 wall++, �鷶�� ���̴� ȸ������
						nextwall = wall[current.x][current.y] + 1;
					}
					else {
						//���� ���� ��� �׳� �������� �ȴ�.
						nextwall = wall[current.x][current.y];
					}
					//�� min�� �����ϱ�
					if (nextwall < wall[next.x][next.y]) {
						wall[next.x][next.y] = nextwall;
					}

					//queue�� �ֱ�
					//printf("%d %d\n", next.x, next.y);
					Q.push(next);
					//�� ����� �ּ� ���� ã�ƾ� �ϱ⿡ ������ ������ �� �־�� �Ѵ�.
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

	//�����Ҵ�
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