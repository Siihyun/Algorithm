#include<cstdio>
#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;

int dir[8];
int x[8];
int y[8];
int num, r, c, cctv_num;
int arr[8][8];
int copy_arr[8][8];
int cnt,ans = 987654321; 

void make_map(int idx) {
	int num = arr[x[idx]][y[idx]];
	int cur_x = x[idx];
	int cur_y = y[idx];
	
	if (num == 1) {
		if (dir[idx] == 0) {
			for (int ny = y[idx]; ny < c; ny++) {
				if (copy_arr[cur_x][ny] == 6) break;
				if (copy_arr[cur_x][ny] == 0) {
					copy_arr[cur_x][ny] = -1;
				}
			}
		}
		
		else if (dir[idx] == 1) {
			for (int ny = y[idx]; ny >= 0; ny--) {
				if (copy_arr[cur_x][ny] == 6) break;
				if (copy_arr[cur_x][ny] == 0) copy_arr[cur_x][ny] = -1;
			}
		}
		
		else if (dir[idx] == 2) {
			for (int nx = x[idx]; nx >=0; nx--) {
				if (copy_arr[nx][cur_y] == 6) break;
				if (copy_arr[nx][cur_y] == 0) copy_arr[nx][cur_y] = -1;
			}
		}
		
		else {
			for (int nx = x[idx]; nx < r; nx++) {
				if (copy_arr[nx][cur_y] == 6) break;
				if(copy_arr[nx][cur_y]==0) copy_arr[nx][cur_y] = -1;
			}
		}
		
	}
	
	else if (num == 2) {
		if (dir[idx] == 0) {
			for (int ny = cur_y; ny < c; ny++) {
				if (copy_arr[cur_x][ny] == 6) break;
				if (copy_arr[cur_x][ny] == 0) copy_arr[cur_x][ny] = -1;
			}
			for (int ny = cur_y; ny >=0 ; ny--) {
				if (copy_arr[cur_x][ny] == 6) break;
				if (copy_arr[cur_x][ny] == 0) copy_arr[cur_x][ny] = -1;
			}
		}
		else{
			for (int nx = cur_x; nx < r; nx++) {
				if (copy_arr[nx][cur_y] == 6) break;
				if (copy_arr[nx][cur_y] == 0) copy_arr[nx][cur_y] = -1;
			}
			for (int nx = cur_x; nx >= 0; nx--) {
				if (copy_arr[nx][cur_y] == 6) break;
				if (copy_arr[nx][cur_y] == 0) copy_arr[nx][cur_y] = -1;
			}
		}
	}

	else if (num == 3) {
		if (dir[idx] == 0) {
			for (int nx = x[idx]; nx >= 0; nx--) {
				if (copy_arr[nx][cur_y] == 6) break;
				if (copy_arr[nx][cur_y] == 0) copy_arr[nx][cur_y] = -1;
			}
			for (int ny = y[idx]; ny < c; ny++) {
				if (copy_arr[cur_x][ny] == 6) break;
				if (copy_arr[cur_x][ny] == 0) copy_arr[cur_x][ny] = -1;
			}
		}
		else if (dir[idx] == 1) {
			for (int nx = x[idx]; nx < r; nx++) {
				if (copy_arr[nx][cur_y] == 6) break;
				if (copy_arr[nx][cur_y] == 0) copy_arr[nx][cur_y] = -1;
			}
			for (int ny = y[idx]; ny < c; ny++) {
				if (copy_arr[cur_x][ny] == 6) break;
				if (copy_arr[cur_x][ny] == 0) copy_arr[cur_x][ny] = -1;
			}
		}
		else if (dir[idx] == 2) {
			for (int nx = x[idx]; nx < r; nx++) {
				if (copy_arr[nx][cur_y] == 6) break;
				if (copy_arr[nx][cur_y] == 0) copy_arr[nx][cur_y] = -1;
			}
			for (int ny = y[idx]; ny >= 0; ny--) {
				if (copy_arr[cur_x][ny] == 6) break;
				if (copy_arr[cur_x][ny] == 0) copy_arr[cur_x][ny] = -1;
			}
		}
		else {
			for (int nx = x[idx]; nx >= 0; nx--) {
				if (copy_arr[nx][cur_y] == 6) break;
				if (copy_arr[nx][cur_y] == 0) copy_arr[nx][cur_y] = -1;
			}
			for (int ny = y[idx]; ny >= 0; ny--) {
				if (copy_arr[cur_x][ny] == 6) break;
				if (copy_arr[cur_x][ny] == 0) copy_arr[cur_x][ny] = -1;
			}
		}
	}

	else if (num == 4) {
		if (dir[idx] == 0) {
			for (int nx = x[idx]; nx >= 0; nx--) {
				if (copy_arr[nx][cur_y] == 6) break;
				if (copy_arr[nx][cur_y] == 0) copy_arr[nx][cur_y] = -1;
			}
			for (int ny = cur_y; ny < c; ny++) {
				if (copy_arr[cur_x][ny] == 6) break;
				if (copy_arr[cur_x][ny] == 0) copy_arr[cur_x][ny] = -1;
			}
			for (int ny = cur_y; ny >= 0; ny--) {
				if (copy_arr[cur_x][ny] == 6) break;
				if (copy_arr[cur_x][ny] == 0) copy_arr[cur_x][ny] = -1;
			}
		}
		else if (dir[idx] == 1) {
			for (int nx = cur_x ; nx < r; nx++) {
				if (copy_arr[nx][cur_y] == 6) break;
				if (copy_arr[nx][cur_y] == 0) copy_arr[nx][cur_y] = -1;
			}
			for (int nx = cur_x; nx >= 0; nx--) {
				if (copy_arr[nx][cur_y] == 6) break;
				if (copy_arr[nx][cur_y] == 0) copy_arr[nx][cur_y] = -1;
			}
			for (int ny = y[idx]; ny < c; ny++) {
				if (copy_arr[cur_x][ny] == 6) break;
				if (copy_arr[cur_x][ny] == 0) copy_arr[cur_x][ny] = -1;
			}
		}
		else if (dir[idx] == 2) {
			for (int nx = x[idx]; nx < r; nx++) {
				if (copy_arr[nx][cur_y] == 6) break;
				if (copy_arr[nx][cur_y] == 0) copy_arr[nx][cur_y] = -1;
			}
			for (int ny = cur_y ; ny < c; ny++) {
				if (copy_arr[cur_x][ny] == 6) break;
				if (copy_arr[cur_x][ny] == 0) copy_arr[cur_x][ny] = -1;
			}
			for (int ny = cur_y ; ny >= 0; ny--) {
				if (copy_arr[cur_x][ny] == 6) break;
				if (copy_arr[cur_x][ny] == 0) copy_arr[cur_x][ny] = -1;
			}
		}
		else {
			for (int nx = cur_x; nx < r; nx++) {
				if (copy_arr[nx][cur_y] == 6) break;
				if (copy_arr[nx][cur_y] == 0) copy_arr[nx][cur_y] = -1;
			}
			for (int nx = cur_x; nx >= 0; nx--) {
				if (copy_arr[nx][cur_y] == 6) break;
				if (copy_arr[nx][cur_y] == 0) copy_arr[nx][cur_y] = -1;
			}
			for (int ny = y[idx]; ny >= 0; ny--) {
				if (copy_arr[cur_x][ny] == 6) break;
				if (copy_arr[cur_x][ny] == 0) copy_arr[cur_x][ny] = -1;
			}
		}
	}

	else {
		for (int nx = cur_x; nx < r; nx++) {
			if (copy_arr[nx][cur_y] == 6) break;
			if (copy_arr[nx][cur_y] == 0) copy_arr[nx][cur_y] = -1;
		}
		for (int nx = cur_x; nx >= 0; nx--) {
			if (copy_arr[nx][cur_y] == 6) break;
			if (copy_arr[nx][cur_y] == 0) copy_arr[nx][cur_y] = -1;
		}
		for (int ny = cur_y; ny < c; ny++) {
			if (copy_arr[cur_x][ny] == 6) break;
			if (copy_arr[cur_x][ny] == 0) copy_arr[cur_x][ny] = -1;
		}
		for (int ny = cur_y; ny >= 0; ny--) {
			if (copy_arr[cur_x][ny] == 6) break;
			if (copy_arr[cur_x][ny] == 0) copy_arr[cur_x][ny] = -1;
		}
	}
}
void copy_map() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			copy_arr[i][j] = arr[i][j];
}
void cal() {
	int check = 0;
	copy_map();
	cnt++;
	for(int i = 0 ; i < cctv_num; i++)
		make_map(i);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (copy_arr[i][j] == 0) check++;
		}
	}
	ans = min(ans, check);
}
void dfs(int idx) {
	if (idx == cctv_num) {
		cal();
		return;
	}

	if (arr[x[idx]][y[idx]] == 2) { // 2번 카메라는 방향 2개
		for (int i = 0; i < 2; i++) {
			dfs(idx + 1);
			dir[idx]++;
		}
		dir[idx] -= 2;
	}

	else if (arr[x[idx]][y[idx]] == 5) // 5번 방향 1개
		dfs(idx + 1);

	else { // 나머지 방향 4개
		for (int i = 0; i < 4; i++) {
			dfs(idx + 1);
			dir[idx]++;
		}
		dir[idx] -= 4;
	}
}
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] > 0 && arr[i][j] < 6) {
				x[cctv_num] = i;
				y[cctv_num++] = j;
			}
		}
	}
	dfs(0);
	cout << ans << endl;
}