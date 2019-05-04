#include<iostream>
#include<cstring>
using namespace std;
int arr[9][16] = {0};
int clock[16] = {0};
int check1[16] = {0};
int cnt = -1;
int realcheck = -1;
void solve(int a,int num){
	if(realcheck == 0)
		return;
	cnt = -1;
	cout<<a<<"번째 버튼 선택!"<<endl; 
	cout<<"num = "<<num<<endl;
	for(int i = 0; i< 16 ; i++)
		cout<<clock[i]<<' ';
	cout<<endl;
	for(int i = 0; i < 16 ; i++){
		if(check1[i]==4)
			return;
	}
	for(int i = 0 ; i < 16 ; i++){
		if(clock[i]!=0){
			cnt = 1;
			break;
		}
	}
	if(cnt == -1){
		realcheck = 0;
		cout<<num<<endl;
		return;
	}
	int check = -1;
	for(int i = 0 ; i <= 9 ; i++){
		if(realcheck == 0)
			return;
//		cout<<"i = "<<i<<endl;
		check = -1;
		for(int j = 0 ; j < 16 ; j++){
			clock[j] -= arr[i][j];
		}
		
		
	//	cout<<"arr"<<endl;
		for(int j = 0 ; j < 16 ; j++){
//			cout<<clock[j]<<' ';
		}
	//	cout<<endl;
		for(int j = 0; j < 16 ; j++){
			if(clock[j]<0)
				check = 1;
		}
		if(check==-1){
	//		cout<<"in "<<i<<endl;
			check1[i]++;
			solve(i,num+1);
		}
		for(int j = 0; j < 16; j++)
			clock[j] += arr[i][j];
		
	}
	
}
int main(void){
	arr[0][0] = 1; arr[0][1] = 1; arr[0][2] = 1;
	arr[1][3] = 1; arr[1][7] = 1; arr[1][9] = 1; arr[1][11] = 1;
	arr[2][4] = 1; arr[2][10] = 1; arr[2][14] = 1; arr[2][15] = 1;
	arr[3][0] = 1; arr[3][4] = 1; arr[3][5] = 1; arr[3][6] = 1; arr[3][7] = 1;
	arr[4][6] = 1; arr[4][7] = 1; arr[4][8] = 1; arr[4][10] = 1; arr[4][12] = 1;
	arr[5][0] = 1; arr[5][2] = 1; arr[5][14] = 1; arr[5][15] = 1;
	arr[6][3] = 1; arr[6][14] = 1; arr[6][15] = 1;
	arr[7][4] = 1; arr[7][5] = 1; arr[7][7] = 1; arr[7][14] = 1; arr[7][15] = 1;
	arr[8][1] = 1; arr[8][2] = 1; arr[8][3] = 1; arr[8][4] = 1; arr[8][5] = 1;
	arr[9][3] = 1; arr[9][4] = 1; arr[9][5] = 1; arr[9][9] = 1; arr[9][13] = 1;
 	int testcase;
	cin>>testcase;
	while(testcase--){
		realcheck = -1;
		memset(check1,0,16);
		for(int i = 0 ; i < 16; i++){
			cin>>clock[i];
			if(clock[i]==12)
				clock[i] = 0;
			else
				clock[i]/= 3;
	//		cout<<clock[i]<<' ';
		}
	//	cout<<endl;
		solve(0,0);
	}
}
