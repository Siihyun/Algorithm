#include<stdio.h>
int main(void){
	int N,M;
	int cnt;
	scanf("%d %d",&N,&M);
	if(N==1)
		cnt=0;
	else if(N==2){
		cnt=(M-1)/2;
		cnt = cnt> 3? 3 : cnt;
	}
	else{
		if(M<=6)
			cnt = M<=4 ? M-1 : 3;
		else
			cnt = M-3;
	}
	printf("%d\n",cnt+1);
	return 0;
}

