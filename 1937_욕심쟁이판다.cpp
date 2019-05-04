#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 500
#define INF 0x7fffffff
int n;
int arr[MAX][MAX];
int res[MAX][MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

using namespace std;
int solve(int x, int y, int standard, int depth) {
	int m = 0; int tmp;
	if (x < 0 || y < 0 || x>=n || y>=n) 
		return depth - 1;
	if (arr[x][y] < standard) 
		return depth - 1;
	if (res[x][y] != -1)
		return res[x][y] + depth;
	//printf("4방향 시작\n");
	res[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		res[x][y] = max(res[x][y], solve(new_x, new_y, arr[x][y], depth + 1) - depth);
	}
	//	printf("4방향 종료\n");
	return res[x][y];

}
int main() {
	cin >> n;
	int m = 0; int tmp = 0;
	for (int i = 0; i < n; i++)
		fill_n(res[i], n, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//	printf("i : %d , j : %d\n", i, j);
			if (res[i][j] == -1) {
				res[i][j] = solve(i, j, -1, 0);
			}
			if (res[i][j] > m) m = res[i][j];

		}
	}
	cout << m + 1 << endl;
	/*
	for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	printf("%d ", res[i][j]);
	}
	printf("\n");
	}
	*/
}