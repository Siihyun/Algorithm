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
#define INF 0xffffffffffff
typedef pair<int, int> P;
vector<P> adj[MAX_VERTAX];
int V, E;
long long S, F;
long long dijkstra(int S, int E) {
	if (S == E)
		return 0;
	vector<long long> dist(MAX_VERTAX, INF);
	vector<bool> visited(MAX_VERTAX, 0);
	priority_queue< P, vector<P>, greater<P>> PQ;
	dist[S] = 0;
	PQ.push(P(dist[S], S));

	while (!PQ.empty()) {
		int cur;
		do {
			cur = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[cur]);

		if (visited[cur])
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
	return dist[E];
}
int main() {
	int X;
	scanf("%d %d %d", &V, &E, &X);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u - 1].push_back(P(v - 1, w));
		//adj[v - 1].push_back(P(u - 1, w));
	}
	
	long long m = 0;
	X--; 
	for (int i = 0; i < V; i++) {
		long long t = dijkstra(i, X) + dijkstra(X, i);
		if (m < t)
			m = t;
	}
	printf("%lld\n", m);
	return 0;
}