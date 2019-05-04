#include<iostream>
#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
int arr[25][25];
bool visited[25];
int team[2][25]; // start, link 팀의 구성원 vertex 번호를 담는 배열
int N, sum, m = 987654321;
int check, cnt, flag;
int get_score(int idx) { // 팀의 점수를 구해주는 함수
	int score = 0, i = 0, cur;

	while (i < N / 2) { // 팀원 수 만큼
		cur = team[idx][i]; // 현재 팀원의 row로 가서
		for (int j = 0; j < N / 2; j++) { // 팀원 수 만큼 점수를 더해줍니다
			score += arr[cur][team[idx][j]];
		}
		i++;
	}
	return score;
}
void dfs(int depth, int idx) {
	if (flag) return; // 0인 정답이 나왔으면 최소이므로 return
	if (depth == N / 2 - 1) { // 정점 0을 이미 넣고 시작해서  N/2 - 1 까지입니다
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < N; i++) {
			if (visited[i]) team[0][cnt1++] = i; // start 팀
			else team[1][cnt2++] = i; // link 팀
		}
		int t1 = get_score(0); // score를 구해줌
		int t2 = get_score(1);
		if (abs(t1 - t2) < m) m = abs(t1 - t2); // m 갱신
		if (m == 0) flag = 1; // 0이 나오면 flag = 1
	}

	for (int i = idx; i < N; i++) { // 팀 구하는 dfs
		if (i == idx) continue;
		if (visited[i]) continue;
		visited[i] = true;
		dfs(depth + 1, i);
		visited[i] = false;
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

	visited[0] = true;
	dfs(0, 0);
	cout << m << endl;
}