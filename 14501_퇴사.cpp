#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 20
#define INF 0x7fffffff
using namespace std;
int N;
int a, b;
int main() {
	cin >> N;
	vector<int> t;
	vector<int> p;
	vector<int> dp(MAX, 0);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		t.push_back(a);
		p.push_back(b);
	}
	for (int i = 0; i < N; i++) {
		if (dp[i] > dp[i + 1]) dp[i + 1] = dp[i]; // 오늘 최대값이 어제 최대값보다 작으면
		if (i + t[i] > N) continue; // 범위 넘기면
		if (dp[i + t[i]] < dp[i] + p[i]) { // 오늘일을 하는게 이득이면 
			dp[i + t[i]] = dp[i] + p[i]; // 바꿔줌
		}
	}
	cout << dp[N] << endl;
}