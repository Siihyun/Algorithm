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
int N;
int a, b;
int main() {
	cin >> N;
	vector<int> t;
	vector<int> p;
	vector<int> dp(N+1, 0);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		t.push_back(a);
		p.push_back(b);
	}
	for (int i = 0; i < N; i++) {
		if (dp[i] > dp[i + 1]) dp[i + 1] = dp[i];
		if (i + t[i] > N) continue;
		if (dp[i + t[i]] < dp[i] + p[i])
			dp[i + t[i]] = dp[i] + p[i];
	}
	cout << dp[N] << endl;
}