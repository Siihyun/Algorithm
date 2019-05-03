#include<iostream>
#include<cstring>
#include<algorithm>
int testcase,n;
int A[501],sum[501];
int dp[501][501];
using namespace std;
int score(int start,int end){
	if(dp[start][end]!=0x3f3f3f3f)
		return dp[start][end];
	else if(end-start==1)
		return dp[start][end] = A[start]+A[end];
	else if(start == end)
		return dp[start][end] = 0;
	for(int mid = start; mid < end; mid++){
		int left = score(start,mid);
		int right = score(mid+1,end);
		dp[start][end] = min(left+right,dp[start][end]);
	}
	//printf("dp[%d][%d]=%d\n",start,end,dp[start][end]);
	return dp[start][end]+= sum[end]-sum[start-1];
}
int main(){
	cin>>testcase;
	while(testcase--){
		memset(dp,0x3f,sizeof(dp));
		memset(A,0,sizeof(A));
		memset(sum,0,sizeof(sum));
		cin>>n;
		sum[0] = 0;
		for(int i = 1 ; i <= n ; i++){
			cin>>A[i];
			sum[i] += sum[i-1] + A[i];
			//printf("sum[%d] = %d\n",i,sum[i]);
		}
		int ans = score(1,n);
		cout<<ans<<endl;
	}
}
