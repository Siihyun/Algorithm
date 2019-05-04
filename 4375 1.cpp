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
int check,num;
int main(){
	while((check = scanf("%d",&num))!=EOF){
		int k = 1;
		int cnt = 1;
		int mul = 10;
		while(k%num!=0){
			k%=num;
			mul%=num;
			k*=mul;
			k%=num;
			k+=(1%num);
			cnt++;
		}
		printf("%d\n",cnt);
	}
	
}
