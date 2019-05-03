#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 25
#define INF 0x7fffffff
int N, S, ans,sum;
int arr[MAX];
bool visited[MAX];
using namespace std;
void dfs(int idx) {
	if (idx == N) return;
	if (sum + arr[idx] == S) ans++;
	dfs(idx + 1);
	sum += arr[idx];
	dfs(idx + 1);
	sum -= arr[idx];
}
int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	dfs(0);
	cout << ans << endl;
}