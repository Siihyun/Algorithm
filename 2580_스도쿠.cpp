// 스도쿠...너무 어려울것 같다.... 다 풀수 있을까... 5시 반 안이 일단 목표...
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 9
#define INF 0x7fffffff
using namespace std;
int arr[MAX][MAX];
void sudoku(int depth) {
	for (int i = 0; i < MAX; i++) {  // row의 모든 빈 칸에 대해서 해야함 , 결국 채우고 싶은 칸 : arr[depth][i]
		if (arr[depth][i]) continue;
		bool check[9];
		memset(check, false, sizeof(check));
		for (int j = 0; j < MAX; j++) { // 가로 , 세로 , 직사각형 정보 check 만들자
			check[arr[depth][j]] = 1;
			check[arr[j][i]] = 1;
			int x = (depth / 3) * 3 + j / 3;
			int y = (i / 3) * 3 + j % 3;
			check[arr[x][y]] = 1;
			for (int k = 0; k < MAX; k++) { // check배열 보면서 가능성 있는 k 넣어보자
				if (check[k]) continue;
				check[k] = 1;
				arr[depth][i] = k;
				sudoku(depth + 1);
				arr[depth][i] = 0;
			}
		}
	}
}
int main() {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			scanf("%d", &arr[i][j]);
	sudoku(0);
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			printf("%d", arr[i][j]);
}