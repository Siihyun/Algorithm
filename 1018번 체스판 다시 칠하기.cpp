#include<iostream>
using namespace std;
int main(){
	char black[8][8] = {{'B','W','B','W','B','W','B','W'}, {'W','B','W','B','W','B','W','B'}, {'B','W','B','W','B','W','B','W'} , 	{'W','B','W','B','W','B','W','B'} , 
	{'B','W','B','W','B','W','B','W'} , {'W','B','W','B','W','B','W','B'} , {'B','W','B','W','B','W','B','W'} ,{'W','B','W','B','W','B','W','B'}};
	char white[8][8] = {{'W','B','W','B','W','B','W','B'}, {'B','W','B','W','B','W','B','W'} , 	{'W','B','W','B','W','B','W','B'} , 
	{'B','W','B','W','B','W','B','W'} , {'W','B','W','B','W','B','W','B'} , {'B','W','B','W','B','W','B','W'} ,{'W','B','W','B','W','B','W','B'}, {'B','W','B','W','B','W','B','W'}};
	int N,M,B_cnt,W_cnt;
	char check[50][50];
	cin>>N>>M;
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < M ; j++){
			scanf("%c",&check[i][j]);
			if(check[i][j] == '\n')
				j--;
			}
	}

	int sol = 987654321;
	for(int i = 0 ; i <= N - 8 ; i++){
		for(int j = 0 ; j <= M -8 ; j++){
			B_cnt = W_cnt = 0;
			for(int k = 0 ; k < 8 ; k++){
				for(int l = 0 ; l < 8 ; l++){
					if(check[i+k][j+l]==black[k][l]){
						W_cnt++;
					}
					else
						B_cnt++;
				}
			}
			int tmp = W_cnt <= B_cnt ? W_cnt : B_cnt;
			if(sol> tmp)
				sol = tmp;
		}
	}
	cout<<sol<<endl;
	
}
