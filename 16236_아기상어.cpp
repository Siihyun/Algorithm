#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
/* 위 , 왼쪽 우선 이라고 해서 방향배열인 dx,dy로 해결할 수 없음. 배열 다 돌아서 찾아야함*/
/* 바로 bfs인지 깨닫지 못한거 반성하자....dfs 뻘짓...*/
using namespace std;
typedef pair<int, int> p;

p shark;
int arr[20][20];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int N, depth,cnt;
int shark_size = 2;
int check = 2;
p fail(-1, -1);

p bfs(p start) {

	bool visited[20][20] = { false };
	int ans[20][20] = { 0 };
	queue<p> q;
	p cur;
	int save = depth;
	q.push(start);
	visited[start.first][start.second] = true;
	int qsize;
	while (!q.empty()) {
		qsize = q.size();
		depth++;
		for (int i = 0; i < qsize; i++) {
			cur = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = cur.first + dx[j];
				int ny = cur.second + dy[j];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue; // range
				if (visited[nx][ny]) continue; // visit check
				if (arr[nx][ny] > shark_size) continue; // 못지나감
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny)); // q에 push
				if (arr[nx][ny] == 0) continue; // 0이면 걍 지나가자
				if (arr[nx][ny] < shark_size) ans[nx][ny] = 1; // 0이 아니면 먹을 수 있으면 먹자
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (ans[i][j]) {
					check--; // for size increase
					if (check == 0) {
						shark_size++;
						check = shark_size;
					}
					arr[i][j] = 9; // 먹는 새끼
					arr[start.first][start.second] = 0; // 내 원래 위치
					start.first = i; start.second = j; // renew shark's pos
					return start;
				}
			}
		}
	}
	depth = save;
	return fail;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 9)	shark.first = i, shark.second = j;
		}
	}
	while (1) {
		shark = bfs(shark);
		if (shark == fail) break;
	}
	cout << depth << endl;

}