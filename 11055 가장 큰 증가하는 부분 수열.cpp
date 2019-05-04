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
int A[1000],sum[1000],n,test;
int main(){
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>A[i];
	}
	sum[0] = A[0];
	for(int i = 1 ; i < n ; i++){
		test = 0;
		for(int j = 0 ; j < i ; j++){
			if(A[j] < A[i]){
				if(sum[j] > test)
					test = sum[j];
			}
		}
		sum[i] = test + A[i];
	//	printf("sum[%d] = %d\n",i,sum[i]);
	}
	int M = sum[0];
	for(int i = 1 ; i < n ; i++){
		if(sum[i]>M)
			M = sum[i];
	}
	cout<<M<<endl;
}
