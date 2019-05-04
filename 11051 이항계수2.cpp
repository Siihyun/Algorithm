#include<iostream>
int dp[1001][1001];
int n,k;
using namespace std;
int main(){
	cin>>n>>k;
	dp[1][0] = 1; dp[1][1]= 1;
	for(int i = 2 ; i <= n ; i++){
		for(int j = 0 ; j <= i ; j++){
			if(j == 0 || j == i)
				dp[i][j] = j;
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			if(dp[i][j]>=10007)
				dp[i][j]%=10007;
		}
	}
	cout<<dp[n][k]<<endl;
}
