#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>

#define MAX 10000
#define INF 0x7fffffff
using namespace std;
int main() {
	int a, b, c;
	int num[10] = { 0 };
	cin >> a >> b >> c;
	int res = a * b * c;
	while (res != 0) {
		num[res % 10]++;
		res /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << num[i] << endl;
}