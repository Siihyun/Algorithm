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
		while (start != n) { // �������� ������ ���ƺ�
			start = (start + 1) % arrsize;
			if (arr[start]) tmp++;
		}
		if (tmp <= cnt / 2) ans += tmp; // ������ ������
		else ans += cnt - tmp; // �ݴ����� ������
		arr[n] = 0; 

		while(arr[start]==0 && loopcnt--) // start ������
			start = (start + 1) % arrsize;
		cnt--;
	}
	cout << ans << endl;
}