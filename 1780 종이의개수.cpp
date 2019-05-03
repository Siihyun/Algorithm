#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>
 
#define MAX_SIZE 16
#define INF 0x7fffffff
using namespace std;
int n,arr[3],cache[2200][2200];
void find(int x,int y,int size){
	int check = cache[x][y];
	if(size==1){
		arr[check+1]++;
		return;
	}
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j++){
			if(check!=cache[x+i][y+j]){
				for(int k = 0; k < 3; k++){
					for(int l = 0 ; l < 3 ; l++){
						find(x+k*(size/3),y+l*(size/3),size/3);
					}
				}
				return;
			}
		}
	}
	arr[check+1]++;
	return;
}
int main(){	
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++)
			cin>>cache[i][j];
	}
	find(0,0,n);
	for(int i = 0; i < 3; i++)
		cout<<arr[i]<<endl;
}
