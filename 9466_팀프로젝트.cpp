#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 100000
#define INF 0x7fffffff
using namespace std;
stack<int> st;
int arr[MAX];
int res = 0;
//bool visited[MAX] = { 0 };
bool check[MAX] = { 0 };
bool dfs(int start,bool visited[]) {
	//	printf("start : %d\n", start);
	if (visited[start]) {
		if (start == arr[start]) {
			check[start] = true;
			return false;
		}
		return true;
	}
	visited[start] = true;
	if (dfs(arr[start], visited)) 
		check[start] = true;
	return false;
}
int main() {
	int testcase, n;
	cin >> testcase;
	while (testcase--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int tmp;
			scanf("%d", &tmp);
			arr[i] = tmp - 1;
		}
		//		printf("\n\n========================\n");
		//		for (int i = 0; i < n; i++)
		//			printf("%d ", arr[i]);
		//		printf("\n");
		for (int i = 0; i < n; i++) {
			bool visited[MAX] = { 0 };
			if (!visited[i]) {
				dfs(i,visited);
			}
		}
	//	printf("%d\n", n - res);
	//	res = 0;
		int num = 0;
		for (int j = 0; j < n; j++) {
			if (!check[j])
				num++;
		}
		printf("%d\n", num);
	}
}