#include<iostream>
#include<algorithm>
using namespace std;
int dp[16],t[16],p[16];
int n;
int main(){
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		cin>>t[i]>>p[i];
	}
	for(int i = 1 ; i <= n ; i++){
		printf("dp[%d]Â÷·Ê\n",i);
		for(int j = 1 ; j < i ; j++){
			if(j+t[j] <= i+1){
				if(dp[j]+p[j]>=dp[i]){
					printf("dp[%d] + p[%d] = %d\n",j,j,dp[j]+p[j]);
					dp[i] = max(dp[j]+p[j],dp[i]);
				}
				else
					dp[i] = max(dp[j]+p[j],dp[i]);
				}
			else
				dp[i]= max(dp[j],dp[i]);
			printf("dp[%d]=%d\n",i,dp[i]);
		}
		if(t[i]==1){
			printf("%d %d\n",dp[i],p[i]);
			dp[i]+=p[i];
			printf("==dp[%d]=%d\n",i,dp[i]);
		}
	}
	cout<<dp[n]<<endl;
}
