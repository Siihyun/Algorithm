#include<iostream>
#include<cstring> 
#include<algorithm> 
using namespace std;
int arr[100][100] = {0};
int sol[100][100] = {0};
int main(){
	int testcase;
	int line;
	cin>>testcase;
	while(testcase--){
		memset(arr,0,sizeof(arr)); // 원래 배열 
		memset(sol,0,sizeof(sol)); // solution array 
		cin>>line;
		for(int i = 0 ; i < line ; i++){
			for(int j = 0; j <= i ; j++){
				cin>>arr[i][j];
			}
		}
		for(int i = 0; i < line; i++)
			sol[line-1][i] = arr[line-1][i]; // 마지막줄은 그대로 채움 
		while(line-1>=0){
			for(int i = 0; i <line; i++){
				sol[line-2][i] = max(sol[line-1][i],sol[line-1][i+1]) + arr[line-2][i]; // 밑에줄에서 큰 수 + 현재 idx 
			}	
			line--; // 아래서부터 위로 올라감 
		}
		cout<<sol[0][0]<<endl;
	}
}	
