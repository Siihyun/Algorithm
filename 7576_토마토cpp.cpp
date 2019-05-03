/*================================================================*/
/* 큐에 1(익은 토마토) 모두 넣고 bfs 시작                         */
/* 방문한 0(안익은 토마토) 모두 1로 바꿔줌                        */
/* bfs 끝나고 다시 배열 조사해서 0(안익은 토마토) 있으면 실패     */
/* 성공하면 depth정보를 갖고 있는 visited 배열에서의 max값 반환   */
/*================================================================*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 1001
#define INF 0x7fffffff
using namespace std;
int r, c, testcase,m=0;
int arr[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
typedef pair<int, int> p;
queue<p> q;

void bfs() {
	while (!q.empty()) {
		p point = q.front();
		if (m < visited[point.first][point.second]) m = visited[point.first][point.second]; // max값 갱신
		q.pop();
		for (int i = 0; i < 4; i++) { // 다음에 방문할 좌표 구함 하->상->좌->우 순서
			int nx = point.first + dx[i];
			int ny = point.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue; // out of range
			if (arr[nx][ny] || visited[nx][ny]) continue; // 이미 방문한점 pass
			arr[nx][ny] = 1;
			visited[nx][ny] = visited[point.first][point.second] + 1;
			q.push(make_pair(nx, ny));
		}
	}
}
bool check() { // 방문 안한 점이 있는지 check
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 0)
				return false;
		}
	}
	return true;
}
int main() {
	cin >> c >> r;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}
	bfs();
	if (check()) cout << m << endl;
	else cout << "-1" << endl;
	return 0;
}