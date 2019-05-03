#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 35
#define INF 0x7fffffff
using namespace std;
int w, h, d;
char building[MAX][MAX][MAX];
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };

typedef struct Point{
	int x;	int y; int z;
	Point(int a, int b, int c) { x = a; y = b; z = c; };
	Point() {};
}point;

int main() {
	point start,cur,end;
	while (1) {
		int visited[MAX][MAX][MAX] = { 0 };
		memset(visited, 0, sizeof(visited));
		scanf("%d %d %d", &d, &w, &h);
		if (d == 0 && w == 0 & h == 0) break;
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%s", building[i][j]);
				for (int k = 0; k < h; k++) {
					if (building[i][j][k] == 'S') start = point(i, j, k);
					if (building[i][j][k] == 'E') end = point(i, j, k);
				}
			}
			getchar();
		}
		queue<point> q;
		q.push(start);
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			if (building[cur.x][cur.y][cur.z] == 'E')
				break;
			for (int i = 0; i < 6; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				int nz = cur.z + dz[i];
				if (nx < 0 || nx >= d || ny < 0 || ny >= w || nz < 0 || nz >= h) continue;
				point tmp = point(nx, ny, nz);
				if (!visited[nx][ny][nz] && (building[nx][ny][nz] == '.' || building[nx][ny][nz] == 'E')) {
					visited[nx][ny][nz] = visited[cur.x][cur.y][cur.z] + 1;
					q.push(tmp);
				}
			}
		}
		if (visited[end.x][end.y][end.z]!=0)
			printf("Escaped in %d minute(s).\n", visited[end.x][end.y][end.z]);
		else
			printf("Trapped!\n");
	}
	
}