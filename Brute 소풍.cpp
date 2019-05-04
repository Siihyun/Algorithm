#include<iostream>
#include<cstring>
using namespace std;

int arr[10][10]={0};
int num,numofFriends;
int cnt = 0;



void find_friends(int idx,int *flag){
	
	int check = -1;
	int n;
	for(n = 0; n<num; n++){
		if(!flag[n]) {
			check = n;
			break;
		}
	}
	if(check == -1){
		cnt++; return;
	}
	for(int i = check+1; i< num; i++){
		if(arr[check][i] && !flag[i] && !flag[check]){
			flag[i] = 1;
			flag[check] = 1;
			find_friends(0,flag);
			flag[i] = 0;
			flag[check] = 0;
		}
	}	
}
int main(){
	int testcase;
	cin>>testcase;
	
	while(testcase--){
		int flag[10]={0};
		for(int i =0;i<10;i++)
			flag[i] = 0;
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				arr[i][j]=0;
			}
		}
		cin>>num>>numofFriends;	
		cnt = 0;
		
		for(int i = 0; i < numofFriends ; i++){
			int a,b;
			cin>>a>>b;
			arr[a][b] = 1;
			arr[b][a] = 1;
	}
		find_friends(0,flag);
		cout<<cnt<<endl;
	}
}
