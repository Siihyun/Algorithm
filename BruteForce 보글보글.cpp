#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Isexist(int x,int y,char arr[][7],char str[],int i);
bool check;
void find(char arr[][7],char str[]){
	check=false;
	for(int i=1;i<6;i++){
		for(int j=1;j<6;j++){
			if(arr[i][j]==str[0]){
				if(check==true)
					return;
				Isexist(i,j,arr,str,0);
			}
		}
	}
}

void Isexist(int x,int y,char arr[][7],char str[],int i){
	if(check==true)
		return;
	int a,b;
	if(i==strlen(str)-1){
		check=true;		
	}
	for(int a=x-1;a<=x+1;a++){
		for(int b=y-1;b<=y+1;b++){
			if(a==x && b==y)
				continue;
			if(str[i+1]==arr[a][b])
				Isexist(a,b,arr,str,i+1);
		}
	}	
}
int main(void){
	int testcase;
	int numofstr;
	char arr[7][7]={0};
	char str[100];
	scanf("%d",&testcase);
	getchar();
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			arr[i][j]='0';
		}
	}
	while(testcase--){
		for(int i=1;i<6;i++){
			for(int j=1;j<6;j++){
				scanf("%c",&arr[i][j]);
			}
			getchar();
		}
		scanf("%d",&numofstr);
		while(numofstr--){
			scanf("%s",str);
			find(arr,str);
			if(check==true)
				printf("%s YES\n",str);
			else
				printf("%s NO\n",str);
		}
	}
}
