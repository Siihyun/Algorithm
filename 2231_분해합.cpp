#include<iostream>
using namespace std;
int N,ans,res,tmp;
int main() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		tmp = i;
		ans = i;
		while (tmp) {
			ans += tmp % 10;
			tmp /= 10;
		}
		if (ans == N) {
			res = i;
			break;
		}
	}
	cout << res << endl;
}