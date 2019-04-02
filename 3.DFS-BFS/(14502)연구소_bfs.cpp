#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N, M;
int map[9][9];//(1,1)���� ����
vector<pair<int, int> > virus; //���̷������� vector�� �־�ΰ� ���ɴ�.
vector<pair<int, int> >wall;//���� ĥ �� �ִ� �� 
vector<int> stack;//ũ��� 3���� ����!! -> wall�� index�� ����Ѵ�.
int maxSafe = -1;
int dirx[4] = { 0,1,0,-1 }; //�����»�
int diry[4] = { 1,0,-1,0 };

/*
void print(int table[][9])
{
	int safe = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			printf("%2d", table[i][j]);
		}
		printf("\n");
	}
	return;
}
*/
int checkSafe(int table[][9])
{
	int safe = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!table[i][j]) {
				safe++;
			}
		}
	}
	return safe;
}
void spread(int r, int c, int table[][9], int visited[][9])//BFS
{
	queue<pair<int, int> > bfs;
	bfs.push(make_pair(r, c));
	visited[r][c] = 1;

	while (!bfs.empty())
	{
		pair<int, int> nextone = bfs.front();
		bfs.pop();

		//��,��,��,�� Ȯ�� - �湮���ϰ� 0�� ���� ������!!
		for (int dir = 0; dir < 4; dir++) {
			int nextx = nextone.first + dirx[dir];
			int nexty = nextone.second + diry[dir];
			//�׵θ� �˻�
			if (nextx <= 0 || nextx > N || nexty <= 0 || nexty > M)
				continue;
			if (table[nextx][nexty] == 0 && visited[nextx][nexty]==0) {
				//���� �� �ִ� ��
				bfs.push(make_pair(nextx, nexty));
				visited[nextx][nexty] = 1;
				table[nextx][nexty] = 2;
			}
		}
	}

	return;
}
void lab(int index)
{
	//��������
	if(stack.size()==3)
	{
		/*
		for (int i = 0; i < stack.size(); i++)
		{
			printf("%d ", stack[i]);
		}
		printf("\n");
		*/
		

		int temp[9][9]; int visited[9][9] = { 0 };
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				temp[i][j] = map[i][j];
			}
		}
		//���� �����
		for (int i = 0; i < stack.size(); i++)
		{
			temp[wall[stack[i]].first][wall[stack[i]].second] = 1;
		}

		//���̷����� ��Ʈ����
		for (int x = 0; x < virus.size(); x++) {
			spread(virus[x].first, virus[x].second, temp, visited);
		}
		/*
		if (stack[0] == 0 && stack[1] == 4 && stack[2] == 16)
			print(temp);
		*/
		//���������� �ִ밪�� ���Ѵ�.
		int a = checkSafe(temp);
		if (maxSafe < a)
			maxSafe = a;
		

		stack.pop_back();
		return;
	}

	//��������
	for (int i = index+1; i < wall.size(); i++) {
		stack.push_back(i);
		lab(i);
	}

	stack.pop_back();
	return;
}
int main()
{
	/*
		���̷����� ���������� ��: BFS
		���� ����� ���: ����Ž�� -> n�� �۱⶧���̴�!.
		����� ���� 3���� �־������� for�� 3���ᵵ �� �ٵ� �׳� ��͸� �ᵵ ����
		����� ���� ��� �ߺ��� �ȵǹǷ� ������ �ƴ� �� ����.
		...
		-> ���: �̰� ���⼭ �����ɷ��� �������� ������ ����...
	*/
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back(make_pair(i, j));//���̷��� ���
			else if (map[i][j]==0)
				wall.push_back(make_pair(i, j));//�� ���
		}
	}

	for (int i = 0; i < wall.size(); i++) {
		stack.push_back(i);
		lab(i);
	}
	
	cout << maxSafe << endl;

	return 0;
}