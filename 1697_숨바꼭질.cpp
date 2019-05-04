#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX_SIZE 16
#define INF 0x7fffffff
using namespace std;
bool check[100001] = { 0 };
int Min = INF;
void find(int a, int b, int cnt) {
	if (b < 0 || b>100000)
		return;
	if (check[b])
		return;
	check[b] = true;
	//printf("a : %d b : %d cnt : %d\n", a, b, cnt);
	if (a == b) {
		if (cnt < Min)
			Min = cnt;
		printf("Min changed to %d\n", Min);
		return;
	}
	find(a, 2 * b, cnt + 1);
	find(a, b - 1, cnt + 1);
	find(a, b + 1, cnt + 1);
}
int main() {
	int a, b;
	cin >> a >> b;
	find(a, b, 1);
	cout << Min << endl;
}