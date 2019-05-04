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
	int A, B, C;
	printf("%d\n", sizeof(A));
	cin >> A >> B >> C;
	printf("%d\n", (A + B) % C);
	printf("%d\n", (A%C + B % C) % C);
	printf("%d\n", (A*B) % C);
	printf("%d\n", (A%C * B%C) % C);
	return 0;
}