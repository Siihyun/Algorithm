#include<iostream>
#include<cstring>
int dp[101][10];
int n,ans=0;
const int MAX = 1000000000;
using namespace std;
int main(){
	cin>>n;
	memset(dp,0,sizeof(dp));
	for(int i = 1 ; i < 10 ; i++)
		dp[1][i] = 1;
	for(int i = 2 ; i <= n ; i++){
		for(int j = 0 ; j < 10 ; j++){
			if(j==0)
				dp[i][j] = dp[i-1][1];
			else if(j==9)
				dp[i][j] = dp[i-1][8];
			else
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
			if(dp[i][j]>=MAX)
				dp[i][j]%=MAX;
		}
	}
	for(int i = 0 ; i < 10 ; i++){
		ans += dp[n][i];
		if(ans >= MAX)
			ans%=MAX;
		}
	cout<<ans<<endl;
	return 0;
}
