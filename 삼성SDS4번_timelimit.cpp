#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 305
using namespace std;
typedef struct pos {
	pos(int a, int b, int c, int d) {
		first = a;
		second = b;
		wall = c;
		depth = d;
	}
	int first;
	int second;
	int wall;
	int depth;
}p;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int arr[MAX][MAX] = { 0 };
int visited[MAX][MAX] = { 0 };
int N;

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
				visited[i][j] = -1;
			}
		}
		int nx, ny;
		queue<p> q;
		int depth = 0;
		int M = 987654321;
		q.push(pos(0, 0, 0, 1)); // x , y , wall , depth
		visited[0][0] = 0;
		int flag = arr[N - 1][N - 1] % 2;
		while (!q.empty()) {
			p cur = q.front();
			q.pop();
			if (cur.wall - flag >= M) continue;
			if (cur.first == N - 1 && cur.second == N - 1) { // 도착
				if (cur.wall < M) { // 최소 홀수 개수 갱신!
					M = cur.wall;
					depth = cur.depth - M;
				}
				if (M == 0) break;
			}
			for (int i = 0; i < 4; i++) {
				nx = cur.first + dx[i];
				ny = cur.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue; // out of range
				if (visited[nx][ny] != -1 && (cur.wall >= visited[nx][ny])) continue; // 온 점인데 홀수를 더 적게 통과해서 옴
				visited[nx][ny] = cur.wall; // 내가 홀수를 이만큼 통과해서 여기 왔어!
				if (arr[nx][ny] % 2 == 1)
					q.push(pos(nx, ny, cur.wall + 1, cur.depth + 1));
				else
					q.push(pos(nx, ny, cur.wall, cur.depth + 1));
			}
		}
		printf("#%d %d %d\n", i + 1, M, depth);
	}
	return 0;
}