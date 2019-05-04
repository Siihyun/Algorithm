#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 100
#define INF 0x7fffffff
using namespace std;
vector<int> isThereRoad;
int arr[MAX][MAX] = { 0 };
bool visited[MAX][MAX] = { 0 };
class Graph {
public:
	vector<vector<int>> adj;
	bool visited[MAX];
	int size;
	Graph() {
		fill(visited, visited + MAX, false);
	}
	Graph(int N) {
		adj.resize(N);
		size = N;
		fill(visited, visited + MAX, false);
	}
	void setVisited(int N) {
		fill(visited, visited + N, false);
	}
	void sortList(int N) {
		for (int i = 0; i < N; i++)
			sort(adj[i].begin(), adj[i].end());
	}
	void dfs(int cur,int standard) {
		if (visited[cur])
			return;
		visited[cur] = true;
		for (int i = 0; i < size; i++) {
			if (adj[cur][i] > standard && !visited[i]) {
				printf("visit %d\n", i);
				dfs(i, standard);
			}
		}
		for (int i = 0; i < size; i++) {
			if (!visited[i]) {
				printf("new dfs started!\n");
				dfs(i, standard);
			}
		}
	}
};
int main() {
	int N, road,M;
	M = 0;
	cin >> N;
	Graph graph(N);
	for (int i = 0; i <= N+1; i++) {
		for (int j = 0; j <= N+1; j++)
			arr[i][j] = -1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
//	for (int i = 0; i < M; i++) {
		graph.dfs(0, 4);
//		graph.setVisited(N);
//	}

}