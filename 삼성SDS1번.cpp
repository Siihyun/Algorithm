#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	for(int j = 0 ; j < testcase ; j++){
		int ans[10001] = { 0 };
		int check[10001] = { 0 };
		int input, zero = 0, cur = 1, next = 2;
		int N, K;
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++) {
			scanf("%d", &input);
			check[input]++; // 나왔는지 체크
			if (input == 0) { 
				zero++;
				ans[cur]++; // current에 더해줌
			}
			else if (input == cur) { // current가 나오면
				ans[cur]++;  // current에 더해주고
				zero = 0; // zero 초기화
			}
			else if (input == next) { // 다음게 나오면
				if (check[cur] == 0) { // cur을 건너 뛰었다면
					zero--; // cur 자리 하나 필요하니까 빼주고
					ans[cur] = 0; // cur = 0 으로 만듬 (앞에가 비면 더 클수가없음
				}
				ans[input]++; // 다음거 더해주고
				ans[input] += zero;
				cur = next; // cur next set
				next++;
				zero = 0;
			}
			else { // 몇개 건너 뜀
				if (check[cur] == 0) { // 현재 것이 안나왔으면
					zero--; // zero -1
					ans[cur] = 0;
				}
				ans[input]++; // 현재거 더하고
				int diff = input - cur - 1;
				zero -= diff; // 건너 뛴것만큼 뺴줌
				ans[cur] -= diff;
				ans[input] += zero;
				cur = input;
				next = cur + 1;
				zero = 0;
			}
		}
		if (next != K+1) ans[cur] -= K - next + 1;
		int M = 0;
		for (int i = 1; i <= N; i++) 
			M = max(M, ans[i]);
		
		printf("#%d %d\n",j+1,M);
	}
	return 0;
}