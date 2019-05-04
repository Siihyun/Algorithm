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
			flag = false; // ��� ������ �޾Ҵ��� check�ϴ� flag
			int vsize = tree[i][j].size(); 
			for (k = 0; k < vsize; k++) {
				if (seed[i][j] - tree[i][j][k] < 0) { // ����� ���Դ� ���� break
					flag = true; break;
				}
				seed[i][j] -= tree[i][j][k]; // ��� ��
				tree[i][j][k]++; // ���� + 1
			}
			/* summer �κ� */
			if (flag) {
				int pop = vsize - k; // ���� ���� ��.
				for (int idx = k; idx < vsize; idx++) 
					seed[i][j] += tree[i][j][idx]/2; // ��� ����
				while (pop--) tree[i][j].pop_back(); // �����ֵ� �� ������
			}
		}
	}
}
void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) { 
			int vsize = tree[i][j].size();
			for (int k = 0; k < vsize; k++) {
				int age = tree[i][j][k]; //���� tree�� ����
				if (age % 5 != 0) continue;
				for (int l = 0; l < 8; l++) {  // 8���� ���� �߰�
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