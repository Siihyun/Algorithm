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
int main() {
	int N;
	int cnt = 0;
	cin >> N;
	while (N > 0) {
		if (N == 3 || N == 6 || N == 9 || N == 12) {
			cnt += N / 3;
			break;
		}
		else {
			N -= 5;
			cnt++;
		}
	}
	if (N < 0)
		cnt = -1;
	cout << cnt << endl;
}