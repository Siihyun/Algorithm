#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int arr[100][100]={0};
	int mem[100][100]={0};
	int M = 0;
	int n,m;
	cin>>n>>m;
	for(int i = 1 ; i <= n; i++){
		for(int j = 1 ; j <= m ; j++)
			cin>>arr[i][j];
	}
	for(int i = 1; i <= m; i++)
		mem[0][i] = arr[0][i]; // copy first line
	for(int i = 1; i <= n; i++){
		for(int j = 1 ; j <= m ; j++){
			M = max(mem[i-1][j],mem[i-1][j-1]);
			M = max(M,mem[i][j-1]);
			mem[i][j] = M + arr[i][j];
		}
	}

	cout<<mem[n][m]<<endl;
	return 0;
}

