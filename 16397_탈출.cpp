#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#define MAX 100000
using namespace std;
int N, T, G,cnt,check,idx,sub;
int visited[MAX];
queue<int> q;
int make_num(int n) {
	n *= 2; cnt = 0; check = n;
	while (check) {
		check /= 10;
		cnt++;
	}
	sub = pow(10, cnt-1);
	return n - sub;
}
int main() {
	cin >> N >> T >> G; // N -> src , T -> testcase , G-> dst
	fill_n(visited, MAX, -1);
	q.push(N);
	visited[N] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == G) break; // find sol
		if (cur * 2 < MAX) idx = make_num(cur); // make index
		if (visited[cur] >= T) continue; // depth is more than T
		if (cur+1 < MAX && visited[cur + 1] == -1) { // push button A
			q.push(cur + 1);
			visited[cur + 1] = visited[cur] + 1;
		}
		if (cur*2 < MAX && visited[idx] == -1) { // push button B
			q.push(idx);
			visited[idx] = visited[cur] + 1;
		}
	}
	if (visited[G] == -1) cout << "ANG" << endl; // fail
	else cout << visited[G] << endl;
	return 0;
}