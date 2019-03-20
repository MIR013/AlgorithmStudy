//#include<stdio.h>
//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//int N, M, K;
//int map[11][11]; //땅의 상태
//int s2d2[11][11]; //채워지는 양분
//
//typedef struct tree {
//	//현재시간을 저장한다면?
//	int row;
//	int col;
//	int age; //저장되어있는거랑 나오는건 순서가 다름...!
//};
//struct cmp {
//	bool operator()(tree t, tree u) {
//		return t.age > u.age;//오름차순
//	}
//};
//priority_queue<tree,vector<tree>,cmp> live; //살아있는 나무 모집
//
//
//void getmoney()
//{
//	//나무 하나당 사계절을 보내개 짰는데 그게 아니라 나무 여러개가 계절로 계속 가야함;;
//	for (int time = 0; time < K; time++)
//	{
//		//pq라서 중간에 넣으면 드갔던애가 또나옴
//		queue<tree> season; //사계절 지나면서 살아있는애들 모음
//		queue<tree> dead; //사계절 지나면서 죽은 애들 모음
//
//		//각 계절마다 queue를 돌면서 나무를 모두 확인한다.
//		int checknum = live.size();
//		//봄
//		for (int c = 0; c < checknum; c++)
//		{
//
//			tree check = live.top();
//			live.pop();
//			//봄
//			if (map[check.row][check.col] - check.age >= 0) { //pq에 의해 어린애가 먼저 도니까 먼저 먹음
//				map[check.row][check.col] -= check.age; //자기 나이만큼 양분을 먹고
//				check.age++;//나이가 1증가
//
//				//안죽었으니 바로 가을로 가자 - 양분이랑은 관계없어서 가능
//				if (check.age % 5 == 0) {
//					//나이가 5배수여야 번식함
//					for (int i = -1; i <= 1; i++) {
//						for (int j = -1; j <= 1; j++) {
//							if (i == 0 && j == 0) //나무의 현재위치임
//								continue;
//							//경계선 체크
//							if ((check.row + i) < 1 || (check.row + i) > N || (check.col + j) < 1 || (check.col + j) > N)
//								continue;
//							tree baby;
//							baby.row = check.row + i;
//							baby.col = check.col + j;
//							baby.age = 1;
//							season.push(baby); //새로운 나무 등록
//						}
//					}
//				}
//
//				season.push(check);//살아있는애
//			}
//			else {
//				//양분이 부족하다 - 죽음
//				dead.push(check);
//			}
//			
//		}
//		//pq덮어쓰기
//		int slen = season.size();
//		for (int i = 0; i < slen; i++)
//		{
//			live.push(season.front());
//			season.pop();
//		}
//		
//
//		int dlen = dead.size();
//		//여름 - 죽은애 영양분 보충
//		for (int c = 0; c < dlen; c++)
//		{
//			tree d = dead.front();
//			dead.pop();
//			map[d.row][d.col] += (d.age / 2); //자기 나이의 반으로 추가
//		}
//		
//
//		//겨울 - 나무와 관계없으니 pq안씀
//		for (int i = 1; i <= N; i++) { //양분 추가
//			for (int j = 1; j <= N; j++) {
//				map[i][j] += s2d2[i][j];
//			}
//		}
//
//	}
//	//남은 나무의 수는 queue의 수
//	cout << live.size();
//
//	return;
//}
//int main()
//{
//
//	cin >> N >> M >> K;
//	for (int i = 1; i <= N; i++) { //배열 index 1부터 시작
//		for (int j = 1; j <= N; j++) {
//			cin >> s2d2[i][j];//양분 초기화
//			map[i][j] = 5;//땅 초기화
//		}
//	}
//	//나무입력
//	for (int i = 1; i <= M; i++) {
//		int x, y, z;
//		cin >> x >> y >> z;
//		tree init;
//		init.row = x; init.col = y;
//		init.age = z;
//		live.push(init);
//	}
//
//	getmoney();
//
//	return 0;
//}