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
char arr[MAX][MAX];
int visited[MAX][MAX][2];
int r, c;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
typedef pair<int, int> p;
queue<p> q;
void show_map() {
	printf("\n\n");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			printf("%d ", visited[i][j]);
		printf("\n");
	}
	printf("\n\n");
}
int main() {
	int nx, ny;
	printf("%d\n", sizeof(nx));
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		scanf("%s", arr[i]);
	q.push(make_pair(0, 0));
	visited[0][0][0] = 1;
	while (!q.empty()) {
		p cur = q.front();
		if (cur.first == r - 1 && cur.second == c - 1) {
			printf("%d\n", min(visited[cur.first][cur.second][0], visited[cur.first][cur.second][1]));
			return 0;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cur.first + dx[i];
			ny = cur.first + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (visited[nx][ny][0] == 0) {
				if (arr[nx][ny] == '1' && cur.wall) {
					visited[nx][ny] = visited[cur.x][cur.y] + 1;
					q.push(p(nx, ny, false));
				}
				else if (arr[nx][ny] == '0') {
					visited[nx][ny] = visited[cur.x][cur.y] + 1;
					if (cur.wall) trace[nx][ny] = true;
					q.push(p(nx, ny, cur.wall));
				}
			}
			else { // 벽을 부술수 있을때만 기회줌
				if (!cur.wall || arr[nx][ny] == '1') continue;
				if (trace[nx][ny]) continue;
				if (nx == ex.x && ny == ex.y) continue;
				visited[nx][ny] = visited[cur.x][cur.y] + 1;
				q.push(p(nx, ny, true));
			}
		}
		ex.x = cur.x; ex.y = cur.y;
	}
	printf("-1\n");
}