#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 500
#define INF 0x7fffffff
int n;
int arr[MAX][MAX];
int res[MAX][MAX];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
using namespace std;
int solve(int x, int y) {
	//	printf("start with x : %d , y : %d depth = %d\n", x, y,depth);
	int m = 0; int tmp = 0;
	if (res[x][y] != -1) {
		//	printf("1 : x : %d y ; %d return %d\n", x, y, res[x][y] + 1);
		return res[x][y];
	}
	for (int i = 0; i < 4; i++) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= n)
			continue;
		if(arr[x][y] < arr[new_x][new_y])
			res[x][y] = max(res[x][y],solve(new_x, new_y)+1);
	}
	//printf("res[%d][%d] = %d\n", x, y, res[x][y]);
//	printf("=======2 : x : %d y : %d return %d\n", x, y, m);
	return res[x][y];

}
int main() {
	cin >> n;
	int m = 0; int tmp = 0;
	for (int i = 0; i < n; i++)
		fill_n(res[i], n, -1);

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			scanf("%d", &arr[i][j]);
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res[i][j] = solve(i, j);
			if (res[i][j] > m) m = res[i][j];
		}
	}
	cout << m  << endl;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	
}