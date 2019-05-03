#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>
#include <string>
#define MAX 1000005
#define INF 0x7fffffff
using namespace std;
int F, S, G, U, D;
string str = "use the stairs";
int visited[MAX];
queue<int> q;
void bfs() {
	fill_n(visited, MAX, INF);
	int stair[2];
	stair[0] = U; stair[1] = -D;
	q.push(S);
	visited[S] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < 2; i++) {
			int p = cur + stair[i];
			if (p<=0 || p>F) continue; // out of range
			if (visited[cur] + 1 < visited[p]) {
				visited[p] = visited[cur] + 1;
				q.push(p);
			}
		}
	}
}
int main() {
	cin >> F >> S >> G >> U >> D; // F -> ÃÑ Ãþ¼ö  / S -> ÇöÀç /   G -> ¸ñÀûÁö /
	bfs();
	if (visited[G]!=INF) cout << visited[G]-1 << endl;
	else cout << str << endl;
	return 0;
}