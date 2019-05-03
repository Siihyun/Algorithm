#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 10001
#define INF 0x7fffffff
using namespace std;
int main() {
	int N, X,tmp;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		if (tmp < X)
			printf("%d ", tmp);
	}
}