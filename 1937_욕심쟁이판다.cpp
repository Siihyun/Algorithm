#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 501
#define INF 0x7fffffff
using namespace std;

int n;
int arr[MAX][MAX];
int res[MAX][MAX];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int dfs(int x, int y) {
	if (res[x][y]) 
		return res[x][y];
	res[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i], next_y = y + dy[i];
		if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n) // beyond limit
			continue;
		if (arr[x][y] < arr[next_x][next_y])
			res[x][y] = max(res[x][y], dfs(next_x, next_y) + 1); // depth + 1
	}
	return res[x][y];
}

int main() {
	int res = 0;
	cin>>n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			res = max(res, dfs(i, j));

	cout << res << endl;

	return 0;
}