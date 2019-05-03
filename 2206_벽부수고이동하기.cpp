#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>
/*===================================================================*/
/* 두가지 경우 있음                                                  */
/* 1. 다음으로 갈 좌표가 벽이고 벽이 뚫린적이 없는경우               */
/* 2. 다음으로 갈 좌표가 벽이 아니고 와보지 않은 경우                */
/* 두번 지날 수 있는 점은 한가지 경우                                */
/* 처음 그 점을 지날때는 벽을 뚫은 경로였고,                         */
/* 새로 지날때는 벽을 안뚫은 경로를 찾았을 때 뿐                     */
/* 결국 벽이 있던 벽이 없던, 그 각각의 경로에서의 두번 접근은 안됨.  */
/*================================================================== */
#define MAX 1001
#define INF 0x7fffffff
using namespace std;
char arr[MAX][MAX];
int visited[MAX][MAX][2];
int r, c;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
typedef struct POINT {
	int x;
	int y;
	bool wall;
	POINT(int a, int b, bool c) {
		x = a; y = b; wall = c;
	}
}p;
queue<p> q;

int main() {
	int nx, ny;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		scanf("%s", arr[i]);
	q.push(p(0, 0, true));
	visited[0][0][1] = 1; // 0,0,벽뚫기 가능
	while (!q.empty()) {
		p cur = q.front();
		if (cur.x == r - 1 && cur.y == c - 1) {
			printf("%d\n", visited[cur.x][cur.y][cur.wall]);
			return 0;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = cur.x + dx[i];
			ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (arr[nx][ny] == '1' && cur.wall && visited[nx][ny][cur.wall-1]==0) { // 벽을 뚫을수 있고 그 벽이 뚫린적이 없으면 push
				visited[nx][ny][cur.wall-1] = visited[cur.x][cur.y][cur.wall] + 1;
				q.push(p(nx, ny, false));
			}
			else if (arr[nx][ny] == '0' && visited[nx][ny][cur.wall]==0) { //벽이 아니고 방문한 적이 아니라면 push
				visited[nx][ny][cur.wall] = visited[cur.x][cur.y][cur.wall] + 1;
				q.push(p(nx, ny, cur.wall));
			}
		}
	}
	printf("-1\n");
}