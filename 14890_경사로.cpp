#include<cstdio>
#include<iostream>
#include<utility>
#include<algorithm>
#define MAX 100

using namespace std;

int arr[MAX][MAX];
int visited[MAX][MAX]; // slope�� �������� 1, �ƴϸ� 0
int N, L,ans;
int i, j, k;
bool slope(int dir) {
	if (dir == -1) { // arr[i][j+1]���� �ڷγ�����
		if (j + L >= N) return false; // slope ���ٰ�����
		int standard = arr[i][j + 1]; 
		for (int k = j + 1; k <= j + L; k++) {
			if (arr[i][k] != standard || visited[i][k]) return false;
		}

		for (int k = j + 1; k <= j + L; k++) {
			visited[i][k] = 1;
		}
		return true;
	}
	else { // arr[i][j] ���� ������ ������
		if (j - L < -1) return false;
		int standard = arr[i][j];
		for (int k = j ; k > j - L ; k--) {
			if (arr[i][k] != standard || visited[i][k]) return false;
		}
		for (int k = j; k > j - L; k--) {
			visited[i][k] = 1;
		}
		return true;
	}
}

bool slope2(int dir) {

	if (dir == 1) { // ������ŭ , arr[j+1][i]���� �Ʒ��� ���ƾ���
		if (j + L >= N) return false; // slope ���ٰ�����
		int standard = arr[j+1][i];
		for (int k = j + 1; k <= j + L; k++) {
			if (arr[k][i] != standard || visited[k][i]) return false;
		}

		for (int k = j + 1; k <= j + L; k++) {
			visited[k][i] = 1;
		}
		return true;
	}
	else { // �Ʒ�����ŭ , arr[j][i]���� ���γ��ƾ���
		if (j - L < -1) return false;
		int standard = arr[j][i];
		for (int k = j ; k > j - L; k--) {
			if (arr[k][i] != standard || visited[k][i]) return false;
		}
		for (int k = j ; k > j - L; k--) {
			visited[k][i] = 1;
		}
		return true;
	}
}
int main() {
	cin >> N >> L;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	//puts("====================����=====================");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N-1; j++) {
			if (abs(arr[i][j] - arr[i][j + 1]) > 1) break; // ���� 1 �̻��̸� ����
			if (arr[i][j] == arr[i][j + 1]) continue;
			int diff = arr[i][j+1] - arr[i][j];
			if (slope(diff) == false) break;
		}
		if (j == N - 1) {
			ans++;
		//	printf("line : %d\n", i);
		}
	}
	for (i = 0; i < N; i++)
		fill_n(visited[i], N, false);
	//puts("====================����=====================");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - 1; j++) {
			if (abs(arr[j][i] - arr[j + 1][i]) > 1) break; // ���� 1 �̻��̸� ����
			if (arr[j][i] == arr[j+1][i]) continue;
			int diff = arr[j][i] - arr[j+1][i]; // 1�̸� ������ŭ
			if (slope2(diff) == false) break;
		}
		if (j == N - 1) {
			ans++;
		//	printf("line : %d\n", i);
		}
	}

	cout << ans << endl;
}