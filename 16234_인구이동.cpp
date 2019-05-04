#include<iostream>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<queue>
/* bfs , dfs 둘다 이용 해봄. 확실히 dfs가 깔끔하고 빠르다 */
using namespace std;
int arr[50][50];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool visited[50][50];

typedef pair<int, int> p;
queue<p> q;
int N, L, R, diff,depth,ans;
int sum;

/*
void dfs(int x,int y) {
	visited[x][y] = true;
	q.push(make_pair(x, y));
	sum += arr[x][y];
	depth++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (visited[nx][ny]) continue;
		diff = abs(arr[x][y] - arr[nx][ny]);
		if (diff < L || diff > R) continue;
		dfs(nx, ny);
	}
}
*/
bool bfs(int x,int y) {
	queue<p> q;
	queue<p> saveq;
	q.push(make_pair(x, y));
	saveq.push(make_pair(x, y));
	visited[x][y] = true;
	int sum = arr[x][y];
	int cnt = 1;
	bool bfs_flag = false;
	while (!q.empty()) {
		int qsize = q.size();
		p cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny]) continue;
			diff = abs(arr[cur.first][cur.second] - arr[nx][ny]);
			if (diff < L || diff > R) continue;
			visited[nx][ny] = true;
			bfs_flag = true;
			sum += arr[nx][ny];
			q.push(make_pair(nx, ny));
			saveq.push(make_pair(nx, ny));
			cnt++;
		}
	}
	int man = sum / cnt;
	while (!saveq.empty()) {
		int x_idx = saveq.front().first;
		int y_idx = saveq.front().second;
		arr[x_idx][y_idx] = man;
		saveq.pop();
	}
	return bfs_flag;
}
bool flag = false;

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	int true_flag;
	while (1) {
		flag = false;
		for (int i = 0; i < N; i++) // visited 초기화
			fill_n(visited[i], N, false);
		for (int i = 0; i < N; i++) { // 국경 열기 시도
			for (int j = 0; j < N; j++) {
				if (visited[i][j]) continue;
				if (bfs(i, j)) flag = true;
			}
		}
		if (!flag) break;
		ans++;
	}
	
	/*
	while (1) {
		flag = false;
		for (int i = 0; i < N; i++) // visited 초기화
			fill_n(visited[i], N, false); 
		for (int i = 0; i < N; i++) { // 국경 열기 시도
			for (int j = 0; j < N; j++) {
				if (visited[i][j]) continue;
				depth = 0; sum = 0; // 초기화
				dfs(i, j);
				if (depth == 1) {
					q.pop();
					continue;
				}
				flag = true;
				int man = sum / depth;
				while (!q.empty()) {
					p cur = q.front();
					q.pop();
					arr[cur.first][cur.second] = man;
				}
			}
		}
		if (flag == false) break;
		ans++;
	}
	*/
	cout << ans << endl;
}
