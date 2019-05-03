#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 305
#define INF 0x7fffffff
using namespace std;
int r, c, testcase,arraysize;
int arr[MAX][MAX];
int dx[8] = { -2,2,-1,1,-2,2,-1,1 };
int dy[8] = { 1,1,2,2,-1,-1,-2,-2 };
int visited[MAX][MAX];
typedef pair<int, int> p;
queue<p> q;
p s,e;
int bfs() {
	q.push(s);
	visited[s.first][s.second] = 1;
	while (!q.empty()) {
		p point = q.front();
		if (point.first == e.first && point.second == e.second) return visited[e.first][e.second];
		q.pop();
		for (int i = 0; i < 8; i++) { 
			int nx = point.first + dx[i];
			int ny = point.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= arraysize || ny >= arraysize) continue; // out of range
			if (visited[nx][ny]!=0) continue; // 이미 방문한점 pass
			visited[nx][ny] = visited[point.first][point.second] + 1;
			q.push(make_pair(nx, ny));
		}
	}
	return -1;
}
int main() {
	cin >> testcase;
	while (testcase--) {
		while (!q.empty()) q.pop();
		scanf("%d %d %d", &arraysize,&c,&r);
		for (int i = 0; i < arraysize; i++)
			fill_n(visited[i], arraysize, false);
		s = make_pair(c, r);
		scanf("%d %d", &c, &r);
		e = make_pair(c, r);
		printf("%d\n",bfs()-1);
	}
	return 0;
}