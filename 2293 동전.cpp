#include<iostream>
#include<cstring>
using namespace std;
int main(){
   int n,k;
   cin>>n>>k;
   int a[101] = {0};
   int dp[100001];
   int p;
   for(int i = 0 ; i < 100001 ; i++)
		dp[i] = 123456789;
   dp[0] = 0;
   while(n--){
		cin>>p;
		for(int i = p; i <= k; i++){
			if(dp[i] > dp[i-p]+1)
				dp[i] = dp[i-p]+1;
		}
   }
   if(dp[k]<123456789)
   	cout<<dp[k]<<endl;
	else
		cout<<-1<<endl;
   /*
   for(int i = 0 ; i < n ; i++){
      cin>>a[i];
      dp[a[i]] = 1;
   }
   int tmp;
   for(int i = 1; i <=k; i++){
      for(int j = 0; j < n ; j++){
         if(a[j] <= i && dp[j]!= 100001 && dp[i-a[j]]!= 100001 ){
            tmp = dp[i-a[j]]+dp[a[j]];
            if(dp[i]> tmp)
            	dp[i] = tmp;
            }
      }
   }
   if(dp[k] == 123456789)
   	dp[k] = -1;
   cout<<dp[k]<<endl;
   cin>>k;
   */
}
