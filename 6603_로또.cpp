#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
bool check[20];
int n, tmp;
void select(int idx, int choice, int size) {
	if (choice == 6) {
		for (int i = 0; i < size; i++) {
			if (check[i]) printf("%d ", v[i]);
		}
		printf("\n");
	}
	if (idx >= size || choice >= 6) return;

	check[idx] = true;
	select(idx + 1, choice + 1, size);
	check[idx] = false;
	select(idx + 1, choice, size);
	return;
}
int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) return 0;
		while (n--) {
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());
		select(0, 0, v.size());
		v.clear();
		printf("\n");
	}
}