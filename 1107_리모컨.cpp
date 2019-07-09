#include<iostream>
using namespace std;
bool channel[10];
int N, cnt, tmp, save, len;
int ans, arr[100];
void solve(int depth, int num, int len) {
	if (depth == len) {
		ans+= 
	}
	if (channel[num]) {
		ans++;
		len++;
		solve(depth + 1, arr[len], len);
	}
	else {
		if (channel[(num+1)%10]) solve(depth + 1, arr[len + 1], len + 1);
		if (num == 0) num = 9;
		else num--;
		if (channel[num]) solve(depth + 1, arr[len + 1], len + 1);
	}
}
int main() {
	fill_n(channel, 10, 1);
	cin >> N >> cnt;
	save = N;
	while (cnt--) {
		cin >> tmp;
		channel[tmp] = 0;
	}
	while (save) {
		arr[len] = save % 10;
		len++;
		save /= 10;
	}
	solve(0,len%10,len);
}