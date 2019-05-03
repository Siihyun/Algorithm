#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 1005
#define INF 0x7fffffff
using namespace std;
int testcase, r, c, x, y;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
typedef pair<int, int> P;
char arr[MAX][MAX];
int visited[MAX][MAX];
bool success = false;
queue<P> q;
queue<P> point;

void make_fire() { // make fire
	int size = q.size();
	int nx, ny;
	for (int i = 0; i < size; i++) {
		P fire = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = fire.first + dx[i];
			ny = fire.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (arr[nx][ny] != '#' && arr[nx][ny] != '*') {
				q.push(make_pair(nx, ny));
				arr[nx][ny] = '*';
			}
		}
	}

}
void input() { // make array
	scanf("%d %d", &c, &r);
	for (int i = 0; i < r; i++)
		fill_n(visited[i], c, 0);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == '@') {
				point.push(make_pair(i, j));
				visited[i][j] = 1;
			}
			else if (arr[i][j] == '*')
				q.push(make_pair(i, j));
		}
		getchar();
	}
}
int ans = 0;
int nx, ny;
int main() {
	cin >> testcase;
	while (testcase--) {
		ans = 0;
		while (!q.empty()) q.pop(); // init queue
		while (!point.empty()) point.pop(); // init queue
		input();
		while (!point.empty()) {
			make_fire();
			int size = point.size();
			for (int i = 0; i < size; i++) { // bfs
				P cur = point.front();
				point.pop();
				if (cur.first == 0 || cur.first == r - 1 || cur.second == 0 || cur.second == c - 1) {
					ans = visited[cur.first][cur.second]; break;
				}
				for (int i = 0; i < 4; i++) {
					nx = cur.first + dx[i];	ny = cur.second + dy[i];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
					if (visited[nx][ny] == 0 && arr[nx][ny] == '.') {
						point.push(make_pair(nx, ny));
						visited[nx][ny] = visited[cur.first][cur.second] + 1;
					}
				}
			}
			if (ans > 0) break;
		}
		if (ans == 0)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << ans << endl;
	}
}