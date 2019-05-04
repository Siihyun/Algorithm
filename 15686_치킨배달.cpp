#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
typedef struct C{
	C(int a, int b, bool check) {
		x = a; y = b; valid = check;
	}
	int x;
	int y;
	bool valid;
}k;
typedef pair<int, int> p;
vector<k> chicken;
vector<p> house;
int arr[50][50];
int N, M, ans = 987654321;
int house_size, chicken_size;

void cal() {
	int num = 0;

	for (int i = 0; i < house_size; i++) {
		int dist = 987654321;
		int hx = house[i].first;
		int hy = house[i].second;
		for (int j = 0; j < chicken_size; j++) {
			if (chicken[j].valid == 0) continue;
			int cx = chicken[j].x;
			int cy = chicken[j].y;
			dist = min(dist, abs(hx - cx) + abs(hy - cy));
		}
		num += dist;
	}
	ans = min(ans, num);
}
void comb(int idx, int sub) {
	if (sub == 0) {
		cal();
		return;
	}
	if (idx >= chicken_size) return;
	chicken[idx].valid = false;
	comb(idx + 1, sub - 1);
	chicken[idx].valid = true;
	comb(idx + 1, sub);
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)
				house.push_back(make_pair(i, j));
			else if (arr[i][j] == 2) 
				chicken.push_back(k(i, j, 1));
		}
	}
	house_size = house.size();
	chicken_size = chicken.size();
	comb(0, chicken_size - M);
	cout << ans << endl;
}