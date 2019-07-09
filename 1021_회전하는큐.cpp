#include<iostream>
using namespace std;
int start, arrsize, num, cnt,n,ans,tmp,loopcnt;
int arr[50];
int main() {
	fill_n(arr, 50, 1);
	scanf("%d %d", &arrsize, &num);
	cnt = arrsize;
	while (num--) {
		scanf("%d", &n); n--;
		tmp = 0;
		loopcnt = arrsize; 
		while (start != n) { // 한쪽으로 무작정 돌아봄
			start = (start + 1) % arrsize;
			if (arr[start]) tmp++;
		}
		if (tmp <= cnt / 2) ans += tmp; // 이쪽이 빠르면
		else ans += cnt - tmp; // 반대쪽이 빠르면
		arr[n] = 0; 

		while(arr[start]==0 && loopcnt--) // start 맞춰줌
			start = (start + 1) % arrsize;
		cnt--;
	}
	cout << ans << endl;
}