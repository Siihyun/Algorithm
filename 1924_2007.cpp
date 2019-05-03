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
	int calendar[13];
	calendar[1] = 31;
	calendar[2] = 28;
	calendar[3] = 31;
	calendar[4] = 30;
	calendar[5] = 31;
	calendar[6] = 30;
	calendar[7] = 31;
	calendar[8] = 31;
	calendar[9] = 30;
	calendar[10] = 31;
	calendar[11] = 30;
	calendar[12] = 31;
	int x, y;
	int num = 0;
	cin >> x >> y;
	for (int i = 1; i < x; i++)
		num += calendar[i];
	num += y;
	switch (num % 7) {
	case 0 :
		cout << "SUN" << endl; break;
	case 1:
		cout << "MON" << endl; break;
	case 2:
		cout << "TUE" << endl; break;
	case 3:
		cout << "WED" << endl; break;
	case 4:
		cout << "THU" << endl; break;
	case 5:
		cout << "FRI" << endl; break;
	case 6:
		cout << "SAT" << endl; break;
	}

}