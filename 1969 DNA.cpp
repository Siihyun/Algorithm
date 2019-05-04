#include<stdio.h>
int main(){
	int N,M;
	char str[1000][51];
	int check[26]={0}, max = 0, max_k = 0, k = 0 , hd = 0;
	char sol[1000];
	scanf("%d %d",&N,&M);
	for(int i = 0 ; i < N ; i++)
		scanf("%s",str[i]);
	
	for(int i = 0 ; i < M ; i++){
		for(int j = 0 ; j < N ; j++){
			int tmp = (int)str[j][i]-65;
			check[tmp]++;
		}
		for(k = 0 ; k < 26; k++){
			if(max < check[k]){
				max = check[k];
				max_k = k;
			}
			check[k]=0;
		}
		hd+= N-max;
		sol[i] = max_k+'A';
		max = 0;
	}
	for(int i = 0 ; i < M ; i++)
		printf("%c",sol[i]);
	printf("\n");
	printf("%d\n",hd);
	return 0;
}
