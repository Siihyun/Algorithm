#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#define RIGHT 1
#define LEFT -1
#define INF 987654321
/* ��Ʈ��ŷ�� row ������ �ѱ��, i = 0���� �ƴ� ���� row���� �� �� �ֵ��� ���� ���ؾߵ�!!!!*/
using namespace std;
bool arr[30][10];
int dir[30][10];
bool flag;
int N, M, H, a, b, ans = INF;

void make_result(int ladder) {

	for (int j = 0; j < N; j++) {
		int idx = j; // j��° ��ٸ� ź��
		for (int i = 0; i < H; i++) {
			if (arr[i][idx]==0) continue;
			if (idx - 1 >= 0) { // ���� ���� ������ ����
				if (arr[i][idx - 1] && dir[i][idx] == LEFT) {
					idx--; continue;
				}
			}
			if (idx + 1 < N) { // ������ ���� ������ ����
				if (arr[i][idx + 1] && dir[i][idx] == RIGHT) {
					idx++; continue;
				}
			}
		}
		if (idx != j) return; // ���� �����µ� ��� Ʋ���� �ٷ� return
	}
	ans = min(ans, ladder);

}
void make_map(int row,int ladder) {
	make_result(ladder);
	if (ladder == 3) return;
	for (int i = row; i < H; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j]) continue; // �̹� ��ٸ� �ְ�
			if (j == N-1) continue; // ĭ�� ������ĭ�̶� ������
			if (j + 1 < N) {
				if (arr[i][j + 1]) continue; // �����ʿ� ������ ������
			}
			arr[i][j] = true; arr[i][j + 1] = true;
			dir[i][j] = RIGHT; dir[i][j + 1] = LEFT;
			make_map(i,ladder+1);
			arr[i][j] = false; arr[i][j + 1] = false;
			dir[i][j] = 0; dir[i][j + 1] = 0;
		}
	}
}
int main() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		a--; b--;
		arr[a][b] = 1; arr[a][b + 1] = 1;
		dir[a][b] = RIGHT; dir[a][b + 1] = LEFT;
	}
	make_map(0,0);
	if (ans == INF) ans = -1;
	cout << ans << endl;
}