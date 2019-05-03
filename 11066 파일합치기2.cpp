#include<iostream>
#include<cstring>
#include<algorithm>
int testcase,n,i,j,k;
int A[501],sum[501];
int dp[501][501];
using namespace std;

int main(){
	cin>>testcase;
	while(testcase--){
		memset(dp,0,sizeof(dp));
		memset(A,0,sizeof(A));
		memset(sum,0,sizeof(sum));
		cin>>n;
		sum[0] = 0;
		for(int i = 1 ; i <= n ; i++){
			cin>>A[i];
			sum[i] = sum[i-1]+A[i];
			printf("sum[%d]= %d\n",i,sum[i]);
		}
		//for(i = 1 ; i < n ; i++){
			for(j = 1 ; k+j <=n ; j++){
				for(k = 1 ; j+k <= n; k++){
					if(j==1){
						dp[k][j+k] = sum[j+k]-sum[k-1];
					}
					else{
						dp[k][j+k] = 
						min(dp[k+1][j+k]+sum[j+k]-sum[k-1],
						dp[k][j+k-1]+sum[j+k]-sum[k-1]);
						printf("%d+%d-%d = %d\n",dp[k+1][j+k],sum[j+k],sum[k-1],dp[k+1][j+k]+sum[j+k]-sum[k-1]);
						printf("%d+%d-%d = %d\n",dp[k][j+k-1],sum[j+k],sum[k-1],dp[k][j+k-1]+sum[j+k]-sum[k-1]);
					}
					printf("dp[%d][%d] = %d\n",k,j+k,dp[k][j+k]);
				}
				k=0;
			}
			printf("i++\n");
		//}
		cout<<dp[1][n]<<endl;
	}
}
