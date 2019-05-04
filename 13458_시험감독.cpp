#include<cstdio>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
int N, A, B, C;
long long v[1000000];
int main() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &v[i]);
		
	}
	cin >> B >> C; // B : 총 감독관 , C ; 부 감독관
	long long ans = N;
	for (int i = 0; i < N; i++) {
		v[i] -= B;
		if (v[i] <= 0) continue;
		ans += v[i] / C;
		if (v[i] % C != 0)  ans++;
	}
	cout << ans << endl;
}