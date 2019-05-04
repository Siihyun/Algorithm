#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAX_SIZE 100

using namespace std;
 
int coin[MAX_SIZE];
int dp[10001];
 
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
 
    for(int i = 0; i < n; i++) scanf("%d", coin + i);
 
    dp[0] = 1;
 
    for(int i = 0; i < n; i++) // 동전개수 
    {
        for(int j = 1; j <= k; j++) // k 
        {
            if(j - coin[i] >= 0) dp[j] += dp[j - coin[i]];
        }
    }
    for(int i = 1 ; i <=k ; i++) 
    	printf("dp[%d] = %d\n",i,dp[i]);
    printf("%d\n", dp[k]);
    
    return 0;
}

