#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 10005
#define INF 0x7fffffff
int n, m, u, v;
int cnt = 0;
int M = 0;
bool visited[MAX];
int check[MAX] = { 0 };
using namespace std;
int main() {
	fill_n(check, MAX, 0);
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		fill_n(visited, MAX, false);
		queue<int> q;
		if (adj[i].size() == 0) continue;
		cnt++;
		q.push(i);
		visited[i] = true;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (auto k : adj[cur]) {
				if (!visited[k]) {
					visited[k] = true;
					cnt++;
					q.push(k);
				}
			}
		}
		if (M < cnt) 
			M = cnt;
		check[i] = cnt;
		cnt = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == M)
			printf("%d ", i);
	}
}