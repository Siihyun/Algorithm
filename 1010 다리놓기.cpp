#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int testcase,N,M;
	int cache[31][31];
	cin>>testcase;
	while(testcase--){
		cin>>N>>M;
		cache[1][0] = 1;
		cache[1][1] = 1;
		for(int i = 2 ; i <= M ; i++){
			for(int j = 0 ; j <= i ; j++){
				if(j==0 || j==i){
					cache[i][j] = 1;
				}
				else{
					cache[i][j] = cache[i-1][j-1] + cache[i-1][j];
				}
			}
		}
		cout<<cache[M][N]<<endl;
	}
	return 0;
}
