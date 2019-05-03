#include<cstdio>
#include<iostream>
#include<algorithm>
#include<utility>

#define MAX 50
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
using namespace std;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[4][4] = { { 0,1,0,-1 } ,{ -1,0,1,0 }, { 0,-1,0,1 } , { 1,0,-1,0 } };
int dy[4][4] = { { -1,0,1,0 }, { 0,-1,0,1}, { 1,0,-1,0 } , { 0,1,0,-1 } };
int bx[4] = {1,0,-1,0};
int by[4] = {0,-1,0,1};

int r, c, x, y, dir;
int cnt,flag,ans;
void clean_up(int depth) {
	if (flag) return;
	int nx, ny;
	int new_dir = dir;
	int i;

	printf("x : %d y : %d, depth : %d \n", x, y,depth);

	for (i = 0; i < 4; i++) {
		nx = x + dx[dir][i];
		ny = y + dy[dir][i];
		new_dir--;
		if (new_dir == -1) new_dir = 3; // rotate
		if (visited[nx][ny]) continue; // already visited
		if (arr[nx][ny]) continue; // if there is wall
		break;
	}
	if (i == 4) { // need to go back
		dir++;
		if (dir == 4) dir = 0;
		int nx = x + bx[dir];
		int ny = y + by[dir];
		if (arr[nx][ny]==1 || depth == 0) { // 벽이거나 처음이면 못감
			flag = true;
			ans = depth;
	//		printf("no where to go\n");
			return;
		}
		x = nx; y = ny;
		printf("go back\n");
		clean_up(depth + 1);
	}
	else { 
		x = nx; y = ny; // move
		dir = new_dir;
		visited[nx][ny] = true;
		clean_up(depth + 1);
	}
}
int main() {
	cin >> r >> c >> x >> y >> dir;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			scanf("%d", &arr[i][j]);
	visited[x][y] = true;
	clean_up(0);
	cout << ans << endl;
}
