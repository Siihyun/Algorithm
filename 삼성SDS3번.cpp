#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 505
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int arr[MAX][MAX] = { 0 };
int res[MAX][MAX] = { 0 };
int N;
int dfs(int x, int y) {
	if (res[x][y])
		return res[x][y];
	res[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (arr[x][y] < arr[nx][ny])
			res[x][y] = max(res[x][y], dfs(nx, ny) + 1); // depth + 1
	}
	return res[x][y];
}
int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int M=0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
				res[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				M = max(M, dfs(i, j));
			}
		}

		printf("#%d %d\n", i + 1, M );
	}
	return 0;
}