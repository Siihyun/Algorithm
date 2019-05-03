#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>
#define MAX 15
#define INF 0x7fffffff
using namespace std;
bool a[20];
bool visited[15][15];
int N,M;
void make_visited(int x,int y) {
	int t = x, s = y;
	for (int i = 0; i < N; i++) { // 1ÀÚ
		visited[x][0] = 1;
		visited[0][y] = 1;
	}
	while (t > 0 || s > 0) {
		t--; s--;
	}
	for (int i = t, j = s; i < N && j < N; i++, j++)
		visited[i][j] = 1;
	t = x; s = y;
	while (t > 0 || s < N) {
		t--; s++;
	}
	for (int i = t, j = s; i < N && j >= 0; i++, j--)
		visited[i][j] = 1;
}
void init_visited() {
	for (int i = 0; i < N; i++)
		fill_n(visited, MAX, 0);
}
void nqueen(int depth) {
	if (depth == N) {
		M++;  return;
	}
	for (int i = 0; i < N; i++) {
		if (visited[depth][i]) continue;
		make_visited(depth,i);
		nqueen(depth + 1);
		init_visited();
	}
}
int main() {
	cin >> N; // N by N matrix
	nqueen(0);
	cout << M << endl;
}
