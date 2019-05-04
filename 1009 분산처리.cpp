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
int main(){
	long long testcase,a,b;
	cin>>testcase;
	while(testcase--){
		cin>>a>>b;
		int num = a;
		while(--b){
			num*=a;
			num%=10;
		}
		num%=10;
		if(num==0)
			num=10;
		cout<<num<<endl;
	}
}
