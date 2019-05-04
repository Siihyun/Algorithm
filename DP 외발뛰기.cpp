#include<iostream>
#include<cstring>
using namespace std;
int game[100][100];
int memo[100][100];
int n;
int solve(int i,int j){
//	cout<<"i = "<<i<<' '<<"j = "<<j<<endl;
	if(i>=n || j>=n) // out of range
		return -1;
	if(memo[i][j]==0) // this way is already failed
		return -1;
	if(memo[i][j]==1) // this way is already succeeded
		return 1;
	if(i == n-1 && j == n-1)
		return 1;
	int cnt = game[i][j];
	int ret;
	ret = solve(i+cnt,j);
	/*
	ret = solve(i,j+cnt) || solve(i+cnt,j);
	if(ret == 1){
		memo[i][j] = 1;
		return 1;
	}
	*/
	if(ret == 1){
		memo[i][j] = 1;
		return 1;
	}
	ret = solve(i,j+cnt);
	if(ret == 1){
		memo[i][j] = 1;
		return 1;
	}
	memo[i][j] = 0;
	return -1;
}
	
int main(){
	int testcase;
	cin>>testcase;
	while(testcase--){
		memset(game,0,sizeof(game));
		memset(memo,-1,sizeof(memo));
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0; j < n ; j++)
				cin>>game[i][j];
		}
		int sol = solve(0,0);
		if(sol == 1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
