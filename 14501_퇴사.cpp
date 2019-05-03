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
		if (dp[i] > dp[i + 1]) dp[i + 1] = dp[i]; // ���� �ִ밪�� ���� �ִ밪���� ������
		if (i + t[i] > N) continue; // ���� �ѱ��
		if (dp[i + t[i]] < dp[i] + p[i]) { // �������� �ϴ°� �̵��̸� 
			dp[i + t[i]] = dp[i] + p[i]; // �ٲ���
		}
	}
	cout << dp[N] << endl;
}