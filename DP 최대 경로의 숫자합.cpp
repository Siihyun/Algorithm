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
		memset(arr,0,sizeof(arr)); // ���� �迭 
		memset(sol,0,sizeof(sol)); // solution array 
		cin>>line;
		for(int i = 0 ; i < line ; i++){
			for(int j = 0; j <= i ; j++){
				cin>>arr[i][j];
			}
		}
		for(int i = 0; i < line; i++)
			sol[line-1][i] = arr[line-1][i]; // ���������� �״�� ä�� 
		while(line-1>=0){
			for(int i = 0; i <line; i++){
				sol[line-2][i] = max(sol[line-1][i],sol[line-1][i+1]) + arr[line-2][i]; // �ؿ��ٿ��� ū �� + ���� idx 
			}	
			line--; // �Ʒ������� ���� �ö� 
		}
		cout<<sol[0][0]<<endl;
	}
}	
