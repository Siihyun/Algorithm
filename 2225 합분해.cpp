#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>
 
#define MAX_SIZE 16
#define INF 0x7fffffff
using namespace std;
int n,k,dp[201]={0};
int main(){
   cin>>n>>k;
   dp[k] = 1;
   for(int i = k+1; i <= n ; i++){
      for(int j = 0 ; j < i; j++)
      	dp[i] += dp[j];
    	printf("dp[%d]=%d\n",i,dp[i]);
   }
   cout<<dp[n]<<endl;
}
