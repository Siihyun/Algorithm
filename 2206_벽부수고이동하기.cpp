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
/* �ΰ��� ��� ����                                                  */
/* 1. �������� �� ��ǥ�� ���̰� ���� �ո����� ���°��               */
/* 2. �������� �� ��ǥ�� ���� �ƴϰ� �ͺ��� ���� ���                */
/* �ι� ���� �� �ִ� ���� �Ѱ��� ���                                */
/* ó�� �� ���� �������� ���� ���� ��ο���,                         */
/* ���� �������� ���� �ȶ��� ��θ� ã���� �� ��                     */
/* �ᱹ ���� �ִ� ���� ����, �� ������ ��ο����� �ι� ������ �ȵ�.  */
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
	visited[0][0][1] = 1; // 0,0,���ձ� ����
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
			if (arr[nx][ny] == '1' && cur.wall && visited[nx][ny][cur.wall-1]==0) { // ���� ������ �ְ� �� ���� �ո����� ������ push
				visited[nx][ny][cur.wall-1] = visited[cur.x][cur.y][cur.wall] + 1;
				q.push(p(nx, ny, false));
			}
			else if (arr[nx][ny] == '0' && visited[nx][ny][cur.wall]==0) { //���� �ƴϰ� �湮�� ���� �ƴ϶�� push
				visited[nx][ny][cur.wall] = visited[cur.x][cur.y][cur.wall] + 1;
				q.push(p(nx, ny, cur.wall));
			}
		}
	}
	printf("-1\n");
}