#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <string>
#include <vector>
#include <functional>
#define MAX 20
#define INF 0x7fffffff
char arr[MAX][MAX];
int R, C, M;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
bool alphabet[26];
using namespace std;
void dfs(int x, int y, int depth) {
	if (depth > M) M = depth;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
		int idx = arr[nx][ny] - 'A';
		if (alphabet[idx]) continue;
		alphabet[idx] = true;
		dfs(nx, ny, depth + 1);
		alphabet[idx] = false;
	}
}
int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		scanf("%s", arr[i]);
	alphabet[arr[0][0] - 'A'] = true;
	dfs(0,0,1);
	cout << M << endl;
}