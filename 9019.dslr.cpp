#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<string>
#define MAX 10000
int testcase, src, dst;
using namespace std;
int D(int n) {
	return (2 * n) % 10000;
}
int S(int n) {
	if (n == 0)
		return 9999;
	else return n - 1;
}
int L(int n) {
	int d1, d2, d3, d4;
	d1 = n / 1000;
	d2 = (n / 100) % 10;
	d3 = (n / 10) % 10;
	d4 = n % 10;
	return d2 * 1000 + d3 * 100 + d4 * 10 + d1;
}
int R(int n) {
	int d1, d2, d3, d4;
	d1 = n / 1000;
	d2 = (n / 100) % 10;
	d3 = (n / 10) % 10;
	d4 = n % 10;
	return d4 * 1000 + d1 * 100 + d2 * 10 + d3;
}
int bfs() {
	int d, s, l, r,idx=0;
	int visited[MAX];
	char trace[MAX];
	char answer[MAX+1];
	fill_n(visited, MAX, -1);
	queue<int> q;
	q.push(src);
	visited[src] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		d = D(cur); s = S(cur);
		l = L(cur); r = R(cur);

		if (visited[d]==-1) {
			visited[d] = cur;
			trace[d] = 'D';
			if (d == dst) break;
			q.push(d);
		}
		if (visited[s]==-1) {
			visited[s] = cur;
			trace[s] = 'S';
			if (s == dst)break;
			q.push(s);
			
		}
		if (visited[l]==-1) {
			visited[l] = cur;
			trace[l] = 'L';
			if (l == dst) break;
			q.push(l);
			
		}
		if (visited[r]==-1) {
			visited[r] = cur;
			trace[r] = 'R';
			if (r == dst) break;
			q.push(r);
		}
	}
	
	int before = visited[dst];
	answer[idx++] = trace[dst];
	while (before != src) {
		answer[idx++] = trace[before];
		before = visited[before];
	}
	for (int i = idx - 1; i >= 0; i--)
		printf("%c", answer[i]);
	printf("\n");
	
	return 0;
}
int main() {
	cin >> testcase;
	while (testcase--) {
		scanf("%d %d", &src, &dst);
		bfs();
	}
}