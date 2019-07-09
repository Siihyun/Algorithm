#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int M[1001];
int v[5];
int N, L;
double ans = 0.0;
double K[20] = { 0.0, 1.53, 1.97 ,2.39 ,2.68 ,2.94 ,3.17 ,3.21 ,3.09 ,2.75 ,2.43,
				 2.02, 1.51, 1.19, 0.76, 0.43, 0.21, 0.17, 0.13, 0.11 };
double res[1010];
void find(int idx, int left, int depth) {
	if (idx > N + 7) return;
	if (left == 0) {
		//	printf("======select end=======\n");
	/*	for (int m = 0; m < depth; m++)
			printf("%d ", v[m]);
		printf("\n\n");
		*/
		double sum = 0;
		int diff, j = 0;
		for (int i = 0; i < depth; i++) {
			//	printf("%d ", v[i]);
			
			if (depth == 2) {
				sum = res[v[0]];
				j = v[0];
				i = 1;
			}
			
			for (; j < v[i] && j < N; j++) {
				diff = min(v[i] - j , 19);
				sum += M[j] * K[diff];
			}
			if (depth == 1) res[v[0]] = sum;
		}
		/*
		if (sum > ans) {
			printf("idx : %d\n", idx);
			for (int i = 0; i < depth; i++)
				printf("기둥 번호 : %d\n", v[i]);
			printf("\n\n");
		}
		*/
		ans = max(sum, ans);
		//	printf("ans = %.2lf\n", ans);
		//	printf("=======================\n\n");
		return;
	}
	v[depth] = idx;
	find(min(N+7,idx + 7), left - 1, depth + 1); // 현재 index 고름
	v[depth] = 0;
	find(idx + 1, left, depth); // 안고름
}
int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int tmp;
		ans = 0;
		scanf("%d %d", &N, &L);
		for (int i = 0; i < N; i++)
			scanf("%d", &M[i]);
		for (int i = 0; i < N; i++) {
			scanf("%d", &tmp);
			M[i] *= tmp;
			res[i] = 0;
		}
		int temp;
		if (N % 7 == 0) temp = N / 7;
		else temp = N / 7 + 1;
		find(7, min(temp,L), 0);
		printf("#%d %.2lf\n", i + 1, ans);
		//for (int i = 0; i < N+7; i++)
		//	printf("%.2lf\n", res[i]);
	}
	return 0;
}