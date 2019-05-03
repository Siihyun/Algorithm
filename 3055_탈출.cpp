#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 55
#define INF 0x7fffffff
using namespace std;
int testcase, r, c, x, y,ans=0,nx,ny;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int visited[MAX][MAX];
char arr[MAX][MAX];
typedef pair<int, int> P;
queue<P> q;
queue<P> point;
void make_water() { // make water
	int size = q.size();
	int nx, ny;
	for (int i = 0; i < size; i++) {
		P water = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = water.first + dx[i];
			ny = water.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (arr[nx][ny] != 'X' && arr[nx][ny] != '*' && arr[nx][ny] != 'D') {
				q.push(make_pair(nx, ny));
				arr[nx][ny] = '*';
			}
		}
	}

}
void input() { // make array
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++)
		fill_n(visited[i], c, 0);
	getchar();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%c", &arr[i][j]);
			if (arr[i][j] == 'S') {
				point.push(make_pair(i, j));
				visited[i][j] = 1;
			}
			else if (arr[i][j] == '*')
				q.push(make_pair(i, j));
		}
		getchar();
	}
}
int main() {
	input();
	while (!point.empty()) {
		make_water();
		int size = point.size();
		for (int i = 0; i < size; i++) { // bfs
			P cur = point.front();
			point.pop();
			if (arr[cur.first][cur.second] == 'D'){
				printf("%d\n", visited[cur.first][cur.second]-1); return 0;
			}
			for (int i = 0; i < 4; i++) {
				nx = cur.first + dx[i];	ny = cur.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
				if (visited[nx][ny] == 0 && (arr[nx][ny] == '.' || arr[nx][ny] == 'D')) {
					point.push(make_pair(nx, ny));
					visited[nx][ny] = visited[cur.first][cur.second] + 1;
				}
			}
		}
	}
	cout << "KAKTUS" << endl;
}
