// ������...�ʹ� ������ ����.... �� Ǯ�� ������... 5�� �� ���� �ϴ� ��ǥ...
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
	for (int i = 0; i < MAX; i++) {  // row�� ��� �� ĭ�� ���ؼ� �ؾ��� , �ᱹ ä��� ���� ĭ : arr[depth][i]
		if (arr[depth][i]) continue;
		bool check[9];
		memset(check, false, sizeof(check));
		for (int j = 0; j < MAX; j++) { // ���� , ���� , ���簢�� ���� check ������
			check[arr[depth][j]] = 1;
			check[arr[j][i]] = 1;
			int x = (depth / 3) * 3 + j / 3;
			int y = (i / 3) * 3 + j % 3;
			check[arr[x][y]] = 1;
			for (int k = 0; k < MAX; k++) { // check�迭 ���鼭 ���ɼ� �ִ� k �־��
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