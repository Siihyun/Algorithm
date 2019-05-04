#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int isfriend[10][10];
int cnt=0;
void makeline(int taken[],int num);
int main(void){
	int testcase;
	int m,n; int a,b;
	int taken[10]={0};
	memset(taken,0,10);
	cin>>testcase;
	while(testcase--){
		cnt=0;
		cin>>n>>m;
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				isfriend[i][j]=0;
			}
		}
		for(int i=0;i<m;i++){
			cin>>a>>b;
			isfriend[a][b]=1;
			isfriend[b][a]=1;
		}
		makeline(taken,n);
		cout<<cnt<<endl;
		memset(taken,0,10);
	}
	return 0;
}
void makeline(int taken[],int num){
	int freeIdx=-1;
	for(int i=0;i<num;i++){
		if(!taken[i]){
			freeIdx=i;
			break;}
	}
	if(freeIdx==-1){
		cnt++; return;
	}

	for(int j=freeIdx+1;j<num;j++){
			if(!taken[j] && isfriend[freeIdx][j]){
				taken[freeIdx]=1; taken[j]=1;
				makeline(taken,num);
				taken[freeIdx]=0; taken[j]=0;
		}
	
}
	
}
