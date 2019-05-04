#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	int N,K,num;
	int len; int max[3]={0};
	int idx[3]={0};
	char str[500001];
	char flag[500001]={0};
	scanf("%d %d",&N,&K);
	scanf("%s",str);
	int remain = N-K;

	len=strlen(str);
	int range=0; int j=0;
	char str1[500001]={0};
	while(remain){
		
		memset(max,0,12);
		memset(idx,0,12);
	
		for(int i=range;i<len;i++){
			if(max[0]<str[i] && flag[i]==0){
				max[1] = max[0];
				idx[1] = idx[0];
				max[2] = max[1];
				idx[2] = idx[1];
				max[0] = str[i];
				idx[0] = i;
			
			}
		}
	for(int m=0;m<3;m++){
		if(len-idx[m]>=remain){
			range=idx[m]+1;
			remain--;
			str1[j++]=str[idx[m]];
			memset(flag,0,500001);
			break;
			
		}

		else{
			flag[idx[m]]=1;
		}
	}
}
	str1[j+1]=NULL;
	int a = atoi(str1);
	printf("%d\n",a);
}
