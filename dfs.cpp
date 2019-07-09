#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 1000
#define INF 0x7fffffff
using namespace std;
class Graph {
public :
	vector<vector<int>> adj;
	bool visited[MAX];
	Graph() {
		fill(visited, visited + MAX, false);
	}
	Graph(int N) {
		adj.resize(N);
		fill(visited, visited + MAX, false);
	}
	void sortList(int N) {
		for (int i = 0; i < N; i++)
			sort(adj[i].begin(), adj[i].end());
	}
	void dfs(int start) {
		if (visited[start])
			return;
		int cur = start;
		visited[cur] = true;
		printf("%d is visited\n", cur);
		for (auto p : adj[cur]) {
			if(!visited[p]) dfs(p);
		}
	}
};
int main() {
	int V, E;
	cin >> V >> E;
	Graph graph(V);
	for (int i = 0; i < E; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		graph.adj[s].push_back(e);
		graph.adj[e].push_back(s);
	}
	graph.sortList(V);
	graph.dfs(0);
}