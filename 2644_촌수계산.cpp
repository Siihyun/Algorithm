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
typedef pair<int, int> K;
int p1, p2,ans=0;
int cnt = 0;
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
		queue<K> Q;
		Q.push(make_pair(start,0));
		visited[start] = true;
		while (!Q.empty()) {
			int cur = Q.front().first;
			int depth = Q.front().second;
			if (cur == p2) {
				ans = depth; break;
			}
			Q.pop();
			for (auto next : adj[cur]) {
				if (!visited[next]) {
					visited[next] = true;
					Q.push(make_pair(next,depth+1));
				}
			}
		}
	}
	void reset_visited() {
		fill_n(visited, MAX, false);
	}
};
int main() {
	int N, E;
	cin >> N;
	Graph G(N);
	cin >> p1 >> p2;
	p1--; p2--;
	cin >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		G.addEdge(a, b);
	}
	G.sortList();
	G.bfs(p1);
	if (ans == 0) ans--;
	cout << ans << endl;
}