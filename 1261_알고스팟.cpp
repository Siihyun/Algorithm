#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX_VERTAX 10001
#define INF 0x7fffffff
using namespace std;
int n, m;
typedef pair<int, int> P;
vector<P> adj[MAX_VERTAX];
bool cmp(const P &a, const P &b) {
	if (b.second >= b.first)
		return true;
	else
		return false;
}

int dijkstra(int S, int E) {
	if (S == E)
		return 0;
	vector<int> dist(MAX_VERTAX, INF);
	bool visited[MAX_VERTAX] = { 0 };
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
	cin >> m >> n;
	getchar();
	char arr[101][101];
	int target;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &arr[i][j]);
		}
		getchar();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int idx = i * m + j;
			if (i - 1 >= 0) {
				target = (i - 1) * m + j;
				adj[idx].push_back(P(target, arr[i - 1][j] - '0'));
			}
			if (i + 1 < n) {
				target = (i + 1) * m + j;
				adj[idx].push_back(P(target, arr[i + 1][j] - '0'));
			}
			if (j - 1 >= 0) {
				target = i * m + j - 1;
				adj[idx].push_back(P(target, arr[i][j - 1] -'0'));
			}
			if (j + 1 < m) {
				target = i * m + j + 1;
				adj[idx].push_back(P(target, arr[i][j + 1] - '0'));
			}
		}
	}
	cout << dijkstra(0, n*m - 1) << endl;
	return 0;
}