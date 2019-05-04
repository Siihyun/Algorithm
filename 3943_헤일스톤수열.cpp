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
	int testcase,M;
	cin >> testcase;
	while (testcase--) {
		int num;
		scanf("%d", &num);
		M = num;
		while (num != 1) {
			if (num % 2 == 0)
				num /= 2;
			else
				num = num * 3 + 1;
			if (num > M)
			
				
				M = num;
		}
		printf("%d\n", M);
	}
}