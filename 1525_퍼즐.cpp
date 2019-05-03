#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int change[4] = { -3, 3, -1, 1 };
set<string> visited;
string start = "";
string dest = "123456780";
queue<string> q;
void bfs() {
	int result = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			string cur = q.front();
			q.pop();
			if (cur == dest) {
				cout << result << endl;
				return;
			}
			int zero = 0;
			while (cur[zero] != '0') zero++;
			int r = zero / 3;
			int c = zero % 3;

			for (int i = 0; i < 4; i++) {
				int nx = r + dx[i];
				int ny = c + dy[i];
				if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

				string next = cur;
				swap(next[zero], next[zero + change[i]]);

				if (visited.find(next) == visited.end()) {
					visited.insert(next);
					q.push(next);
				}
			}
		}
		result++;
	}
	cout << -1 << endl;
	return;
}
int main() {
	for (int i = 0; i < 9; i++) {
		int tmp;
		cin >> tmp;
		start += tmp + '0'; 
	}
	visited.insert(start);
	q.push(start);
	bfs();
}