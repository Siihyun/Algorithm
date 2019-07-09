#include<iostream>
using namespace std;
int main() {
	int len = 64;
	int want;
	int cnt = 0;
	scanf("%d", &want);
	while (want) {
		while (len > want) {
			len /= 2;
		}
		want -= len;
		cnt++;
	}
	cout << cnt << endl;
}