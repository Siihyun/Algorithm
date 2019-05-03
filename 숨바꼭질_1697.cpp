#include <iostream>
#include <queue>

using namespace std;
int N, K;
#define MAX 100001
int visited[100005] = { 0 };
queue<int> q;
int main()
{
	cin >> N >> K;
	q.push(N);
	visited[N] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		if (cur == K) break;
		q.pop();
		if (cur - 1 >= 0 && visited[cur - 1] == 0) {
			q.push(cur - 1);
			visited[cur - 1] = visited[cur] + 1;
		}
		if (cur + 1 < MAX && visited[cur + 1] == 0) {
			q.push(cur + 1);
			visited[cur + 1] = visited[cur] + 1;
		}
		if (cur * 2 < MAX && visited[cur * 2] == 0) {
			q.push(cur * 2);
			visited[cur * 2] = visited[cur] + 1;
		}
	}
	cout << visited[K] - 1 << endl;
	return 0;
}