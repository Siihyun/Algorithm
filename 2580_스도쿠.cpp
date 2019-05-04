// 스도쿠...너무 어려울것 같다.... 다 풀수 있을까... 5시 반 안이 일단 목표...
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

#define MAX 9
#define INF 0x7fffffff
using namespace std;
typedef pair<int, int> p;
vector<p> v;
int arr[MAX][MAX];
int v_size;
bool flag;
void print_arr() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}

}
bool possible(int x, int y, int n) { // arr[x][y] = n 가능한지 검사
	bool check[MAX+1];
	fill_n(check, MAX + 1, false);
	for (int i = 0; i < MAX; i++) {
		check[arr[x][i]] = 1; // row check
		check[arr[i][y]] = 1; // col check
	}
	int nx = (x / 3) * 3;
	int ny = (y / 3) * 3;
	for (int i = nx; i < nx + 3; i++) { // diagonal check 
		for (int j = ny; j < ny + 3; j++)
			check[arr[i][j]] = 1;
	}
	if (check[n]) return false;
	return true;
}
void sudoku(int depth) {
	if (flag) return;
	if (depth == v_size) {
		print_arr();
		flag = true;
		return;
	}
	for (int i = 0; i < MAX; i++) {
		int x = v[depth].first;
		int y = v[depth].second;
		if (possible(x, y, i+1)) {
			arr[x][y] = i+1;
			sudoku(depth + 1);
			arr[x][y] = 0;
		}
	}
}
int main() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0)
				v.push_back(make_pair(i, j));
		}
	}
	v_size = v.size();
	sudoku(0);
}