/*================================================================*/
/* ť�� 1(���� �丶��) ��� �ְ� bfs ����                         */
/* �湮�� 0(������ �丶��) ��� 1�� �ٲ���                        */
/* bfs ������ �ٽ� �迭 �����ؼ� 0(������ �丶��) ������ ����     */
/* �����ϸ� depth������ ���� �ִ� visited �迭������ max�� ��ȯ   */
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
		if (m < visited[point.first][point.second]) m = visited[point.first][point.second]; // max�� ����
		q.pop();
		for (int i = 0; i < 4; i++) { // ������ �湮�� ��ǥ ���� ��->��->��->�� ����
			int nx = point.first + dx[i];
			int ny = point.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue; // out of range
			if (arr[nx][ny] || visited[nx][ny]) continue; // �̹� �湮���� pass
			arr[nx][ny] = 1;
			visited[nx][ny] = visited[point.first][point.second] + 1;
			q.push(make_pair(nx, ny));
		}
	}
}
bool check() { // �湮 ���� ���� �ִ��� check
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