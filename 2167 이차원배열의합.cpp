#include<iostream>
int A[301][301],dp[301][301];
int n,m,testcase;
int i,j,x,y;
using namespace std;
int main(){
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++)
			cin>>A[i][j];
	}
	dp[1][1] = A[1][1];
	for(int i = 2 ; i <= m ; i++)
		dp[1][i] += dp[1][i-1]+A[1][i];
	for(int i = 2 ; i <= n ; i++)
		dp[i][1] += dp[i-1][1]+A[i][1];
	for(int i = 2 ; i <= n ; i++){
		for(int j = 2 ; j <= m ; j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]+A[i][j];
		}
	}
	cin>>testcase;
	while(testcase--){
		cin>>i>>j>>x>>y;
		cout<<dp[x][y]-dp[x][j-1]-dp[i-1][y]+dp[i-1][j-1]<<endl;
	}
}
