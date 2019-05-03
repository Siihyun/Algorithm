#include<iostream>
int main(){
	int testcase;
	int n;
	int S[2][100001]={0};
	cin>>testcase;
	for(int i = 0 ; i < 2 ; i++){
		for(int j = 0 ; j < n ; j++){
			cin>>S[i][j];
		}
	}
	int idx,anti_idx;
	dp[0] = max(S[0][0],S[1][0]);
	int a,b;
	a = S[0][0] + S[1][1];
	b = S[1][0] + S[0][1];
	if(a>b){
		idx = 1;
		anti_idx = 0;
	}
	else if(b<a){
		idx = 0;
		anti_idx = 0;
	}
	else{
		idx = -1;
		anti_idx = -1;
	}
	for(int i = 2 ; i < n; i++){
		int a,b,c;
		a = dp[i-1]+S[anti_idx][i];
		b = dp[i-2]+S[idx][i];
		c = dp[i-2]+S[anti_idx][i];
		if(a>=b && a>=c){
			
		}
	}
}
