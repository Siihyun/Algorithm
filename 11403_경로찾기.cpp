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
	void dfs(int start, int cur) {
		if (visited[cur])
			return;
		visited[cur] = true;
		for (int i = 0; i < size; i++) {
			if(adj[cur][i]) {
				arr[start][i] = 1;
				if(!visited[i])
					dfs(start, i);
			}
		}
	}
};
int main() {
	int N, road;
	cin >> N;
	Graph graph(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &road);
			graph.adj[i].push_back(road);
		}
	}
	for (int i = 0; i < N; i++) {
		graph.dfs(i, i);
		graph.setVisited(N);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}