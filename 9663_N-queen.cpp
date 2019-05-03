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
int visited[MAX];
int N, M;

bool possible(int depth,int idx) {
	for (int i = 0; i < depth; i++) {
		if (visited[i] == idx) return false; // 같은 column 
		if (abs(visited[i] - idx) == depth - i ) return false; // 대각선 상
	}
	return true;
}

void nqueen(int depth) {
	if (depth == N) M++;
	for (int i = 0; i < N; i++) {
		if (!possible(depth,i)) continue;
		visited[depth] = i;
		nqueen(depth + 1);
		visited[depth] = 0;
	}
}

int main() {
	cin >> N; // N by N matrix
	nqueen(0);
	cout << M << endl;
}