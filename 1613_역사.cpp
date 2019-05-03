#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 405
#define INF 0x7fffffff
using namespace std;
int V, E,testcase;
vector<vector<int>> adj(MAX);
bool bfs(int start, int end) {
	queue<int> q;
	bool visited[MAX] = { false };
	visited[start] = true;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		if (cur == end) return true;
		q.pop();
		for (auto p : adj[cur]) {
			if (visited[p]) continue;
			visited[p] = true;
			q.push(p);
		}
	}
	return false;
}
int main() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u - 1].push_back(v - 1);
	}
	for (int i = 0; i < V; i++)
		sort(adj[i].begin(),adj[i].end());
	cin >> testcase;

	while (testcase--) {
		int start, end;
		scanf("%d %d", &start, &end);
		if (bfs(start-1, end-1)) printf("-1\n");
		else if (bfs(end-1, start-1)) printf("1\n");
		else printf("0\n");
	}
	return 0;
}