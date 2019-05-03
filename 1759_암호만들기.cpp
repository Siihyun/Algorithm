#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <string>
#include <vector>
#include <functional>

#define MAX 20
#define INF 0x7fffffff
int L, C;
using namespace std;
vector<char> v;
bool visited[MAX];
void renew_dfs(int idx,string str) {
	if (str.length() == L) {
		int ja = 0, mo = 0;
		for (int i = 0; i < L; i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') mo++;
			else ja++;
		}
		if (ja < 2 || mo < 1) return;
		cout << str << endl;
		return;
	}
	if (idx >= C) return;
	renew_dfs(idx + 1, str + v[idx]);
	renew_dfs(idx + 1, str);
}
int main() {
	cin >> L >> C;
	v.resize(C);
	for (int i = 0; i < C; i++) {
		scanf(" %c", &v[i]);
	}
	sort(v.begin(), v.end());
	renew_dfs(0,"");
}
