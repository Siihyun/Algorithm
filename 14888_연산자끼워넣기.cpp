#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
// 걍 연산자 하나씩 추가하면서 ㄱㄱ
using namespace std;
int N;
char oper[4] = { '+','-','*','/' };
int opernum[4],tmp;
int M = -987654321;
int m = 987654321;
vector<char> op;
vector<int> a;
void cal() {
	int num = a[0];
	for (int i = 1; i < N; i++) {
		if (op[i - 1] == '*') 
			num *= a[i];
		else if (op[i - 1] == '/')
			num /= a[i];
		else if (op[i - 1] == '+')
			num += a[i];
		else
			num -= a[i];
	}
	M = max(M, num);
	m = min(m, num);
	return;
}
void dfs(int depth) {
	if (depth == N - 1)
		cal();
	for (int i = 0; i < 4; i++) {
		if (opernum[i]) {
			opernum[i]--;
			op.push_back(oper[i]);
			dfs(depth + 1);
			opernum[i]++;
			op.pop_back();
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	for (int i = 0; i < 4; i++)
		scanf("%d", &opernum[i]);
	dfs(0);
	cout << M << endl << m << endl;
	return 0;
}