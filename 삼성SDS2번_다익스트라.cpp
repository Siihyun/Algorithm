#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
#define MAX_VERTAX 90001
#define INF 1000
typedef pair<int, int> P;

int main() {
	int V, E, K,testcase,cost;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		int N;
		int dist[MAX_VERTAX]; // 답
		vector<P> adj[MAX_VERTAX]; // 거리정보
		int even = 0, odd = 0;
		scanf("%d", &N);
		for (int i = 0; i < N*N; i++) {
			scanf("%d", &cost);
			if (i == 0) {
				if (cost % 2 == 0) even++;
				else odd++;
			}
			if (cost % 2 == 0) cost = 1;
			else cost = INF;

			if (i % N != 0) adj[i - 1].push_back(P(i, cost)); // 왼쪽
			if (i % N != N - 1) adj[i + 1].push_back(P(i, cost)); // 오른쪽
			if (i >= N) adj[i - N].push_back(P(i, cost)); // 위쪽
			if (i + N < N * N) adj[i + N].push_back(P(i, cost)); // 아래쪽
		}

		V = N * N; // 정점 개수
		K = 0; // 도착점
		fill(dist, dist + V, 987654321); // 거리배열 초기화
		bool visited[MAX_VERTAX] = { false }; 
		priority_queue< P, vector<P>, greater<P>> PQ;

		dist[K] = 0;
		PQ.push(P(dist[K], K));
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
		even += dist[N*N - 1] % 1000;
		odd += dist[N*N - 1] / 1000;

		printf("#%d %d %d\n", i + 1, odd,even);
	}
	return 0;
}