#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 10000
#define INF 0x7fffffff
using namespace std;
int main() {
	int tmp, score=0;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &tmp);
		if (tmp < 40)
			tmp = 40;
		score += tmp;
	}
	cout << score / 5 << endl;
}