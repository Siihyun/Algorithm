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
int N, S,ans;
int arr[MAX];
bool visited[MAX];
using namespace std;
void dfs(int left,int start,int num) {
	if (left == 0) return;
	for (int i = start; i < N; i++) {
		if (visited[i]) continue;
		if (num - arr[i] == 0 && left == 1) {
			ans++;  continue;
		}
		visited[i] = true;
		dfs(left - 1, i+1,num - arr[i]);
		visited[i] = false;
	}
}
int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= N; i++) {
		dfs(i, 0, S);
		fill_n(visited, MAX, false);	
	}
	cout << ans << endl;
}