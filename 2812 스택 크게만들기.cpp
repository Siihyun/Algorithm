#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void push(char stack[],int *top,char a){
	(*top)++;
	stack[*top]=a;

}

int main(void){
	char str[500001];	char stack[500001];
	int N,K;	int i=1;	int top=-1;
	
	scanf("%d %d",&N,&K);
	scanf("%s",str);
	int diff = N-K;
	int len = strlen(str);
	push(stack,&top,str[0]);
	
	
	while(K && --N){
		if(stack[top]>str[i])
			push(stack,&top,str[i++]);
		else{
			while(stack[top]<str[i] && top>=0 && K){
				top--; K--;
				}
			push(stack,&top,str[i++]);
			}
		}


	while(i<len)
		push(stack,&top,str[i++]);	
		
	for(int m=0;m<diff;m++)
		printf("%d",stack[m]-'0');
	
	return 0;

}
