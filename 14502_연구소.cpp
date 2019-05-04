#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 9
#define INF 0x7fffffff
using namespace std;
int arr[MAX][MAX], r, c, m = 0;
int cmp[MAX][MAX];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
typedef pair<int, int> p;

void copy_array() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cmp[i][j] = arr[i][j];
	return;
}
int bfs() {
	queue<p> q;
	int visited[MAX][MAX];
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (cmp[i][j] == 2)
				q.push(make_pair(i, j));
		}
	}

	while(!q.empty()){
		p cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (visited[nx][ny]) continue;
			if (cmp[nx][ny] == 0) {
				cmp[nx][ny] = 2;
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (cmp[i][j] == 0) cnt++;
		}
	}
	return cnt;
}
int main() {

	memset(arr, 0, sizeof(arr));
	scanf("%d %d", &r, &c);
	
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			scanf("%d", &arr[i][j]);
	copy_array();
	for (int r1 = 0; r1 < r; r1++) {
		for (int c1 = 0; c1 < c; c1++) {
			if (cmp[r1][c1] != 0) continue;
			for (int r2 = r1; r2 < r; r2++) {
				for (int c2 = 0; c2 < c; c2++) {
					if (r1 == r2 && c2 <= c1) continue;
					if (cmp[r2][c2] != 0) continue;
					for (int r3 = r2; r3 < r; r3++) {
						for (int c3 = 0; c3 < c; c3++) {
							if (r2 == r3 && c3 <= c2) continue;
							if (cmp[r3][c3] != 0) continue;
							cmp[r1][c1] = 1;
							cmp[r2][c2] = 1;
							cmp[r3][c3] = 1;
							int tmp = bfs();
							if (m < tmp) m = tmp;
							copy_array();
						}
					}
				}
			}
		}
	}
	cout << m << endl;
}