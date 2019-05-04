#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;
int arr[500][500];
int x[19][4] = { {0,-1,-2,0},{0,-1,-1,-1},{0,0,1,2},{0,0,0,-1},{0,0,-1,-2},{0,0,0,1},{0,0,1,2},{0,1,1,1},{0,0,1,1},{0,1,1,2},{0,0,-1,-1},{0,0,1,1},{0,-1,-1,-2},{0,0,0,0},{0,1,2,3},{0,0,0,-1},{0,1,1,2},{0,0,0,1},{0,-1,0,1} };
int y[19][4] = { {0,0,0,1} ,{0,0,1,2} ,{0,1,1,1} ,{0,1,2,2} ,{0,1,1,1} ,{0,1,2,2} ,{0,1,0,0} ,{0,0,1,2} ,{0,1,0,1} ,{0,0,1,1} ,{0,1,1,2} ,{0,1,1,2} ,{0,0,1,1} ,{0,1,2,3} ,{0,0,0,0} ,{0,1,2,1} ,{0,0,1,0} ,{0,1,2,1} ,{0,1,1,1} };
int r, c;
int n;
int tmp, ans;
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			scanf("%d", &arr[i][j]);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			for (int m = 0; m < 19; m++) {
				tmp = 0;
				for (n = 0; n < 4; n++) {
					int nx = i + x[m][n];
					int ny = j + y[m][n];
					if (i == 3 && j == 2 && m == 4) {
						printf("nx : %d , ny : %d\n", nx, ny);
					}
					if (nx < 0 || ny < 0 || nx >= r || ny >= c) break; // 다음모양
					tmp += arr[nx][ny];
				}
				if (n == 4) { // 모양을 제대로 놓은 경우
					ans = max(ans, tmp);
				}
			}
		}
	}
	cout << ans << endl;
}
