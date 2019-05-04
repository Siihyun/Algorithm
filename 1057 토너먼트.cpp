#include<iostream>
using namespace std;
int main(){
	int N,a,b,cnt=1;
	cin>>N>>a>>b;
	while(N!=1){
		N-= N/2;
		printf("a : %d b : %d\n",a,b);
		if(a-b == 1 || a-b == -1){
			int lower = a>b ? b : a;
			if(lower%2 == 1){
				printf("%d\n",cnt);
				return 0;
			}
		}
		cnt++;
		a-=a/2;
		b-=b/2;
		if(a==0) 
			a = 1;
		if(b==0)
			b = 1;
	}
	printf("-1\n");
	return 0;
}
