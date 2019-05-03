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
int n,arr[1001],tmp,dp[1001];
int main(){
	cin>>n;
	for(int i = 0 ; i < n ; i++)
		dp[i]=1;
	for(int i = 0 ; i < n ; i++)
		cin>>arr[i];
	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j < i ; j++){
			if(arr[j] > arr[i]){
				tmp = dp[j]+1;
				if(tmp > dp[i])
					dp[i] = tmp;
			}
		}
	}
	int max = dp[0];
	for(int i = 0 ; i < n ; i++){
		if(max < dp[i])
			max = dp[i];
	}
	cout<<max<<endl;
}
