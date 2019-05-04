#include<iostream>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<queue>
#define MAX 10
using namespace std;
char arr[10][10];
bool red[10][10];
bool blue[10][10];
bool red_flag, blue_flag;
int red_depth, blue_depth;
int red_dir = 987654321 , blue_dir = 123456789;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
typedef struct t{
	t(int a,int b,int c,int d) {
		rx = a;
		ry = b;
		bx = c;
		by = d;
	}
	int rx;
	int ry;
	int bx;
	int by;
}point;
typedef pair<int, int> p;
queue<p> rq;
queue<p> bq;
queue<point> q;
int r, c,rx,ry,bx,by;
int res_blue = 123456789, res_red = 987654321;
bool red_end_flag = false;
bool blue_end_flag = false;
int depth;
void show_map() {
	printf("===================================\n");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			printf("%c ", arr[i][j]);
		printf("\n");
	}
	printf("===================================\n\n");
};
bool push_flag;
void bfs() { // red_first
	blue[bx][by] = true;	
	red[rx][ry] = true;
	q.push(point(rx, ry, bx, by));

	while (!q.empty()) {
		bool r_push_flag = false , b_push_flag = false;
		if (depth > MAX) break;
		if (red_end_flag && blue_end_flag) break;		
		int q_size = q.size();
		point cur = q.front();
		q.pop();
		depth++;
		for (int i = 0; i < q_size; i++) {
			int save_rx = rx;
			int save_ry = ry;
			int save_bx = bx;
			int save_by = by;
			for (int j = 0; j < 4; j++) { // 4방향 탐색
				printf("%d번째 방향 시작\n", j);
				bool b_way = true;
				bool r_way = true;
				int b_nx = cur.bx + dx[j];
				int b_ny = cur.by + dy[j];
				int r_nx = cur.rx + dx[j];
				int r_ny = cur.ry + dy[j];
				while (1) {
					if (arr[b_nx][b_ny] != '.') { // range check
						b_way = false;
						b_nx -= dx[j];
						b_ny -= dy[j];
					}
					/*
					else { // map upgrade
						arr[bx][by] = '.';
						arr[b_nx][b_ny] = 'B';
					}
					*/
					if (arr[r_nx][r_ny] != '.') { 
						r_way = false;
						r_nx -= dx[j];
						r_ny -= dy[j];
					}
					/*
					else {
						arr[rx][ry] = '.';
						arr[r_nx][r_ny] = 'R';
					}
					*/
					printf("빨간 구슬 : %d %d , ", r_nx, r_ny);
					printf("r way : %d, visited : %d\n", r_way, red[r_nx][r_ny]);
					printf("파란 구슬 : %d %d , ", b_nx, b_ny);
					printf("b way : %d, visited : %d\n", b_way, blue[r_nx][r_ny]);
					show_map();
					if (b_way == 0 && r_way == 0) {
						printf("둘다 못가\n");
						arr[r_nx][r_ny] = '.';
						arr[b_nx][b_ny] = '.';
						arr[save_rx][save_ry] = 'R';
						arr[save_bx][save_by] = 'B';
						break; // 둘다 못감
					}
					bx = b_nx; by = b_ny;
					rx = r_nx; ry = r_ny;
					if (red[r_nx][r_ny] && blue[b_nx][b_ny]) {
						arr[r_nx][r_ny] = '.';
						arr[b_nx][b_ny] = '.';
						arr[save_rx][save_ry] = 'R';
						arr[save_bx][save_by] = 'B';
						printf("둘다 여기 와봤어\n");
						break; // 둘다 가본곳 아닌면 가야돼
					}
					if (b_way) {
						if (arr[b_nx][b_ny] == 'B') { // 가능하면 한번 더가자!
							blue[b_nx][b_ny] = true;
							b_push_flag = true;
							b_nx += dx[j];
							b_ny += dy[j];
						}
						else if (arr[b_nx][b_ny] == 'O') { // 목적지 도착
							blue[bx][by] = true;
							blue_dir = j;
							blue_end_flag = true;
							res_blue = depth;
							b_push_flag = false;
							b_way = false;
							arr[bx][by] = '.';
						}
						else b_way = false;
					}
					if (r_way) {
						if (arr[r_nx][r_ny] == 'R') {
							red[r_nx][r_ny] = true;
							b_push_flag = true;
							r_nx += dx[j];
							r_ny += dy[j];
						}
						else if (arr[r_nx][r_ny] == 'O') {
							red[rx][ry] = true;
							red_end_flag = true;
							res_red = depth;
							push_flag = false;
							r_way = false;
							red_dir = j;
							arr[rx][ry] = '.';
						}
						else r_way = false;
					}
				}
				if (r_push_flag == 0 && b_push_flag == 0) continue; // 둘다 못움직이면 continue
				/*
				if (r_push_flag) {
					r_nx -= dx[j]; r_ny -= dy[j];
				}
				if (b_push_flag){
					b_nx -= dx[j]; b_ny -= dy[j];
				}
				*/
				q.push(point(r_nx, r_ny, b_nx, b_ny));
				b_push_flag = false;
				r_push_flag = false;
			}
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)  // map 만들기
			scanf("%s", arr[i]);

	for (int i = 0; i < r; i++) { // 구슬 좌표 찾기
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'R') {
				rx = i;
				ry = j;
			}
			else if (arr[i][j] == 'B') {
				bx = i;
				by = j;
			}
		}
	}
	bfs();
	printf("red 결과 : %d , blue 결과 : %d\n", res_red, res_blue);
	if (res_red == res_blue && red_dir == blue_dir) res_red = -1;
	if (res_red == 987654321) res_red = -1;
	cout << res_red << endl;

}