#include<stdio.h>
int main(){
	int N,K,coin[10],cnt=0;
	scanf("%d %d",&N,&K);
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&coin[i]);
	}
	while(K!=0){
		int i;
		for(i = N-1; i >=0 ; i--){
			if(K>=coin[i])
				break;
		}
		K-=coin[i];
		cnt++;
	}
	printf("%d\n",cnt);
}
