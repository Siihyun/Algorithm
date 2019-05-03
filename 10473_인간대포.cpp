#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX_SIZE 16
#define MAX 100
#define INF 0x7fffffff
using namespace std;
typedef pair<double, double> P;
typedef pair<double, int> G;
vector<G> adj[MAX];
double cur_x, cur_y, dst_x, dst_y;
int num;
double dijkstra(int S, int E) {
	if (S == E)
		return 0;
	vector<double> dist(MAX,987654321.0);
	bool visited[100] = { 0 };
	priority_queue< G, vector<G>, greater<G>> PQ;
	dist[S] = 0;
	PQ.push(G(dist[S], S));

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
			int next = p.second;
			double d = p.first;
			if (dist[next] > dist[cur] + d) {
				dist[next] = dist[cur] + d;
				PQ.push(G(dist[next], next));
			}
		}
	}
	return dist[E];
}
int main() {
	vector<P> point;
	cin >> cur_x >> cur_y >> dst_x >> dst_y;
	cin >> num;
	point.push_back(P(cur_x, cur_y));
	for (int i = 0; i < num; i++) {
		double x, y;
		cin >> x >> y;
		point.push_back(P(x, y));
	}
	point.push_back(P(dst_x, dst_y));
	for (int i = 0; i < num+2; i++) {
		for (int j = i + 1; j < num+2; j++) {
			double distance = sqrt(pow(point[i].first - point[j].first, 2) + pow(point[i].second - point[j].second, 2));
			double time = 2.0;
			if (i == 0 ) {
				time = distance / 5.0;
			}
			else {
				distance -= 50;
				if (distance < 0) distance *= -1;
				time += distance / 5.0;
			}
			adj[i].push_back(G(time, j));
			adj[j].push_back(G(time, i));
		}
	}
	cout << dijkstra(0, num + 1) << endl;
}