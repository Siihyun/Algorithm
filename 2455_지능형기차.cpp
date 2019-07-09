#include<iostream>
using namespace std;
int main() {
	int ans = 0;
	int m = 0;
	int in, out;
	for (int i = 0; i < 4; i++) {
		scanf("%d %d", &in, &out);
		ans -= in;
		ans += out;
		if (ans > m) m = ans;
	}
	cout << m << endl;
}