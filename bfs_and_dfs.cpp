#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 10000
#define INF 0x7fffffff
using namespace std;
class Graph {
public:
	int N;
	vector<vector<int>> adj;
	bool visited[MAX] = { false };

	Graph(int n) {
		N = n;
		adj.resize(n);
	}
	void sortList() {
		for (int i = 0; i < N; i++)
			sort(adj[i].begin(), adj[i].end());
	}
	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void bfs(int start) {
		queue<int> Q;
		Q.push(start);
		visited[start] = true;
		while (!Q.empty()) {
			int cur = Q.front();
			Q.pop();
			printf("%d ", cur + 1);
			for (auto next : adj[cur]) {
				if (!visited[next]) {
					visited[next] = true;
					Q.push(next);
				}
			}
		}
	}
	void reset_visited() {
		fill_n(visited, MAX, false);
	}
	void dfs(int start) {
		if (visited[start])
			return;
		visited[start] = true;
		printf("%d ", start + 1);
		for (auto next : adj[start]) {
			if (!visited[next]) {
				dfs(next);
			}
		}
	}
};
int main() {
	int N, V, M;
	cin >> N >> M >> V;
	Graph G(N);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		G.addEdge(a, b);
	}

	G.sortList();
	G.dfs(V-1);
	G.reset_visited();
	printf("\n");
	G.bfs(V-1);

}