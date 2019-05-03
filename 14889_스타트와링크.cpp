#include<iostream>
#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
int arr[25][25];
bool visited[25];
int team[2][25]; // start, link ���� ������ vertex ��ȣ�� ��� �迭
int N, sum, m = 987654321;
int check, cnt, flag;
int get_score(int idx) { // ���� ������ �����ִ� �Լ�
	int score = 0, i = 0, cur;

	while (i < N / 2) { // ���� �� ��ŭ
		cur = team[idx][i]; // ���� ������ row�� ����
		for (int j = 0; j < N / 2; j++) { // ���� �� ��ŭ ������ �����ݴϴ�
			score += arr[cur][team[idx][j]];
		}
		i++;
	}
	return score;
}
void dfs(int depth,int left) {
	if (flag) return; // 0�� ������ �������� �ּ��̹Ƿ� return
	if (left == 0) { // ���� 0�� �̹� �ְ� �����ؼ�  N/2 - 1 �����Դϴ�
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < N; i++) {
			if (visited[i]) team[0][cnt1++] = i; // start ��
			else team[1][cnt2++] = i; // link ��
		}
		int t1 = get_score(0); // score�� ������
		int t2 = get_score(1);
		if (abs(t1 - t2) < m) m = abs(t1 - t2); // m ����
		if (m == 0) flag = 1; // 0�� ������ flag = 1
	}
	if (depth >= N)return;

	visited[depth] = true;
	dfs(depth + 1, left - 1);
	visited[depth] = false;
	dfs(depth + 1, left);
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

	dfs(0, N / 2);
	cout << m << endl;
}