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
			check[input]++; // ���Դ��� üũ
			if (input == 0) { 
				zero++;
				ans[cur]++; // current�� ������
			}
			else if (input == cur) { // current�� ������
				ans[cur]++;  // current�� �����ְ�
				zero = 0; // zero �ʱ�ȭ
			}
			else if (input == next) { // ������ ������
				if (check[cur] == 0) { // cur�� �ǳ� �پ��ٸ�
					zero--; // cur �ڸ� �ϳ� �ʿ��ϴϱ� ���ְ�
					ans[cur] = 0; // cur = 0 ���� ���� (�տ��� ��� �� Ŭ��������
				}
				ans[input]++; // ������ �����ְ�
				ans[input] += zero;
				cur = next; // cur next set
				next++;
				zero = 0;
			}
			else { // � �ǳ� ��
				if (check[cur] == 0) { // ���� ���� �ȳ�������
					zero--; // zero -1
					ans[cur] = 0;
				}
				ans[input]++; // ����� ���ϰ�
				int diff = input - cur - 1;
				zero -= diff; // �ǳ� �ڰ͸�ŭ ����
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