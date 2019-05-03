#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>
using namespace std;
#define MAX_SIZE 16
#define MAX_VERTAX 20000
#define INF 0x7fffffff
typedef pair<int, int> P;

int main() {
	int V, E, K;
	vector<P> adj[MAX_VERTAX];
	scanf("%d %d %d", &V, &E, &K);
	K--;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u - 1].push_back(P(v - 1, w));
	}
	int dist[MAX_VERTAX];
	fill(dist, dist + V, INF);
	bool visited[MAX_VERTAX] = { false };
	priority_queue< P, vector<P>, greater<P>> PQ;

	dist[K] = 0;
	PQ.push(P(dist[K], K));
	while (!PQ.empty()) {
		int cur;
		do {
			cur = PQ.top().second;
			PQ.pop();
		}while (!PQ.empty() && visited[cur]);

		if(visited[cur])
			break;
		visited[cur] = true;
		for (auto &p : adj[cur]) {
			int next = p.first;
			int d = p.second;
			if (dist[next] > dist[cur] + d) {
				dist[next] = dist[cur] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}
	for (int i = 0; i < V; i++) {
		if (dist[i] == INF) puts("INF");
		else printf("%d\n", dist[i]);
	}
	return 0;
}