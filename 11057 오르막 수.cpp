#include<iostream>
using namespace std;
int dp[1000];
int main(){
	int N;
	cin>>N;
	dp[1] = 10;
	dp[2] = 55;
	int tmp = 11;
	int tmp1 = 100;
	for(int i = 4; i <= N; i++){
		cout<<dp[i-1]*10<<"-"<<tmp*55<<"= "<<endl;
		dp[i] = 10* tmp1 -55 * tmp;
		tmp *= 10;
		tmp +=1;
		tmp1 *=10;
	}
	cout<<dp[N]<<endl;
}
