#include<iostream>
using namespace std;
char arr[20][20];
int H,W;
int cnt = 0;
bool check1(int i,int j){
	if(i+1>=H || j+1>=W)
		return false;
	if(arr[i][j]=='.' && arr[i][j+1]=='.' && arr[i+1][j+1]=='.')
		return true;
	else
		return false;
}
bool check2(int i,int j){
	if(i+1>=H || j+1>=W)
		return false;
	if(arr[i][j]=='.' && arr[i][j+1]=='.' && arr[i+1][j]=='.')
		return true;
	else
		return false;
}
bool check3(int i,int j){
	if(i+1>=H || j+1>=W)
		return false;
	if(arr[i][j]=='.' && arr[i+1][j]=='.' && arr[i+1][j+1]=='.')
		return true;
	else
		return false;
}
bool check4(int i,int j){
	if(i+1>=H || j==0)
		return false;
	if(arr[i][j]=='.' && arr[i+1][j]=='.' && arr[i+1][j-1]=='.')
		return true;
	else
		return false;
}
void fill(){
	int check = -1;
	int i,j;
	int a,b;
	for(i = 0; i < H ; i++){
		for(j = 0; j < W; j++){
				if(arr[i][j]=='.'){
					check = 0;
					break;
				}
		}
		if(!check)
			break;
	}

	if(check== -1){
		cnt++;
		return;
	}
	a = i;
	b = j;
//	for(int i = 0; i < H-1 ; i++){
//		for(int j = 0; j < W; j++){

			if(check1(i,j)){
				arr[i][j] = '#';
				arr[i][j+1] = '#';
				arr[i+1][j+1] = '#';
				fill();
				arr[i][j] = '.';
				arr[i][j+1] = '.';
				arr[i+1][j+1] = '.';
			}
			if(check2(i,j)){
				arr[i][j] = '#';
				arr[i][j+1] = '#';
				arr[i+1][j] = '#';
				fill();
				arr[i][j] = '.';
				arr[i][j+1] = '.';
				arr[i+1][j] = '.';
			}
			if(check3(i,j)){
				arr[i][j] = '#';
				arr[i+1][j] = '#';
				arr[i+1][j+1] = '#';
				fill();
				arr[i][j] = '.';
				arr[i+1][j] = '.';
				arr[i+1][j+1] = '.';
			}
			if(check4(i,j)){
				arr[i][j] = '#';
				arr[i+1][j] = '#';
				arr[i+1][j-1] = '#';
				fill();
				arr[i][j] = '.';
				arr[i+1][j] = '.';
				arr[i+1][j-1] = '.';
	}
}
int main(){
	
	int testcase;
	int check;
	cin>>testcase;
	while(testcase--){
		for(int i = 0; i < H ; i++){
			for(int j = 0; j < W; j++){
				arr[i][j]=0;
			}
		}
		cnt = 0; 
		check = -1;
		cin>>H>>W;
		for(int i = 0; i < H ; i++){
			for(int j = 0; j < W; j++){
				cin>>arr[i][j];
			}
		}
		fill();
		cout<<cnt<<endl;
		}
	return 0;
}
	

