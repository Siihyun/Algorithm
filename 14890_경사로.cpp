#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
int N, L,ans;
int arr[105][105];
bool fail_flag1;
bool fail_flag2;
int main() {
	cin >> N >> L;
	
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			scanf("%d", &arr[i][j]);

	int i, j, k;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - 1; j++) {
			if (abs(arr[i][j] - arr[i][j + 1]) > 1) {
				fail_flag2 = true; break; // 높이차 2 이상
			}
			if (arr[i][j] == arr[i][j + 1]) continue; // 높이 같음
			if (abs(arr[i][j] - arr[i][j + 1])) { // 높이차 1
				int standard = arr[i][j + 1];
				for (k = j + 1; k < j + L; k++) {
					if (k >= N) fail_flag1 = true;
					if (arr[i][k] != standard) fail_flag1 = true;
				}
				if (fail_flag1) {
					fail_flag2 = true;  break;
				}
				j = k - 1;
			}
		}
		if (!fail_flag2) ans++;
		fail_flag1 = 0; fail_flag2 = 0;
	}
	cout << ans << endl;
}