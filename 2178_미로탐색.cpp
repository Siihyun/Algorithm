#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 105
#define INF 0x7fffffff
int w, h;
using namespace std;
typedef pair<int, int> P;
bool maze[MAX][MAX];
int visited[MAX][MAX] = {0};
int ans;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main() {
	cin >> w >> h;
	for (int i = 0; i < w; i++) fill_n(visited[i], h, false);
	char str[101];
	queue<P> q;
	for (int i = 0; i < w; i++) {
		scanf("%s", str);
		for (int j = 0; j < h; j++) {
			maze[i][j] = str[j]-'0';
		}
	}
	q.push(make_pair(0,0));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (x == w - 1 && y == h - 1) {
			ans = visited[x][y];
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx > w || ny > h) continue;
			if (!visited[nx][ny] && maze[nx][ny]) {
				visited[nx][ny] = visited[x][y]+1;
				q.push(make_pair(nx,ny));
			}
		}
	}
	cout << ans+1 << endl;

}