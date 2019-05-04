#include<cstdio>
#include<iostream>
#include<algorithm>
#include<utility>
/* ������ �̰� ���� �߸��¾� �ʹ� ������ �̻��� Ư�� ������ �����ϸ� ���ٴ°�... ���� ���Ѱ� �ƴ� ����*/
#define MAX 50
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
using namespace std;
int arr[MAX][MAX];
int ans1[MAX][MAX];
bool visited[MAX][MAX];
int dx[4][4] = { { 0,1,0,-1 } ,{ -1,0,1,0 },{ 0,-1,0,1 } ,{ 1,0,-1,0 } };
int dy[4][4] = { { -1,0,1,0 },{ 0,-1,0,1 },{ 1,0,-1,0 } ,{ 0,1,0,-1 } };
int bx[4] = { 1,0,-1,0 };
int by[4] = { 0,-1,0,1 };

int r, c, x, y, dir;
int cnt, flag, ans;
void clean_up(int depth) {
	
	if (!visited[x][y]) {
		visited[x][y] = true;
		ans1[x][y] = ++cnt;
	}
	if (flag) return;
	int nx, ny;
	int new_dir = dir;
	int i;

	for (i = 0; i < 4; i++) {
		nx = x + dx[dir][i];
		ny = y + dy[dir][i];
		new_dir--;
		if (new_dir == -1) new_dir = 3; // rotate
		if (visited[nx][ny]) continue; // already visited
		if (arr[nx][ny]) continue; // if there is wall;
		break;
	}
	if (i == 4) { // need to go back
		int nx = x + bx[dir];
		int ny = y + by[dir];
		if (arr[nx][ny] == 1 || depth == 0) { // ���̰ų� ó���̸� ����
			flag = true;
			ans = depth;
			return;
		}
		x = nx; y = ny;
		clean_up(depth + 1);
	}
	else {
		x = nx; y = ny; // move
		dir = new_dir; // rotate
		clean_up(depth + 1);
	}
}
int main() {
	cin >> r >> c >> x >> y >> dir;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			scanf("%d", &arr[i][j]);
	clean_up(0);
	cout << cnt << endl;
}
