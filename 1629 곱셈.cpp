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
long long num,num1;
long long a,b,c;

long long power(long long a,long long b){ // to get a value for a of bth power
	if(b == 0)
		return 1;
	else if(b%2==0){
		num = power(a,b/2);
		num%= c;
		return (num * num) %c;
	}
	else{
		num = power(a,b/2);
		num = (num%c) * (num%c);
		num%=c;
		return (a*num)%c;
	}
}
int main(){	
	cin>>a>>b>>c;
	cout<<power(a,b)<<endl;
}
