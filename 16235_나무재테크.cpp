#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;
vector<int> tree[10][10];
int add[10][10];
int seed[10][10];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
int N, M, K, r, c, num,ans;
void spring() {
	int i, j, k;
	int flag = false;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			flag = false; // 양분 끝까지 받았는지 check하는 flag
			int vsize = tree[i][j].size(); 
			for (k = 0; k < vsize; k++) {
				if (seed[i][j] - tree[i][j][k] < 0) { // 양분을 못먹는 경우는 break
					flag = true; break;
				}
				seed[i][j] -= tree[i][j][k]; // 양분 줌
				tree[i][j][k]++; // 나이 + 1
			}
			/* summer 부분 */
			if (flag) {
				int pop = vsize - k; // 죽은 나무 수.
				for (int idx = k; idx < vsize; idx++) 
					seed[i][j] += tree[i][j][idx]/2; // 양분 주자
				while (pop--) tree[i][j].pop_back(); // 죽은애들 다 빼내자
			}
		}
	}
}
void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) { 
			int vsize = tree[i][j].size();
			for (int k = 0; k < vsize; k++) {
				int age = tree[i][j][k]; //현재 tree의 나이
				if (age % 5 != 0) continue;
				for (int l = 0; l < 8; l++) {  // 8방향 나무 추가
					int nx = i + dx[l];
					int ny = j + dy[l];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					tree[nx][ny].push_back(1);
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			sort(tree[i][j].begin(), tree[i][j].end());
}
void winter() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			seed[i][j] += add[i][j];
}

void find_alive_tree() {
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			ans += tree[i][j].size();
}
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		fill_n(seed[i], N, 5);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &add[i][j]);


	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &r, &c,&num);
		tree[r - 1][c - 1].push_back(num);
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			sort(tree[i][j].begin(), tree[i][j].end());
	while (K--) {	
		spring();
		fall();
		winter();
	}
	find_alive_tree();
	cout << ans << endl;
	return 0;
}