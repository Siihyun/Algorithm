#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 100001
#define INF 0x7fffffff
using namespace std;
stack<int> st;
int arr[MAX];
int res = 0, tmp2 = 0, tmp = 0;
bool check = false;

int main() {
	int testcase, n;
	cin >> testcase;
	while (testcase--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			arr[i] = tmp - 1;
		}
		bool visited[MAX] = { false };
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				int next = arr[i];
				if (visited[next])
					continue;
				visited[i] = true;
				st.push(i);
				while (!visited[next]) {
					visited[next] = true;
					st.push(next);
					next = arr[next];
				}
				while (!st.empty()) {
					if (st.top() == next) {
						tmp2++;
						check = 1;  
						break;
					}
					tmp2++;
					st.pop();
				}
				while (!st.empty()) 
					st.pop();
			}
			if (check) {
				check = false;
				res += tmp2;
			}
			tmp2 = 0;
		}
		cout << n - res << endl;
		res = 0;
	}
	return 0;
}