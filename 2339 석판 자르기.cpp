#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>
 
#define MAX_SIZE 16
#define GARO 0
#define SERO 1
#define FAIL 0
#define SUCCESS 1
#define INF 0x7fffffff
using namespace std;
int n,pan[25][25];
int cutting(int start_x,int start_y,int end_x,int end_y,int direction) {
	int jewel=0,stone=0,i,j,res1,res2;
	int num = 0;
	for(int i = start_x; i < end_x; i++){
		for(int j = start_y ; j < end_y ; j++){
			if(pan[i][j]==1)
				stone++;
			else if(pan[i][j]==2)
				jewel++;
		}
	}
	num=0;
	if(stone == 0 && jewel == 1)
		return SUCCESS;
	else if(jewel == 0)
		return FAIL;
	stone = 0; jewel = 0;
	
	if(direction == GARO){ // 가로방향 
		for(i = start_x; i < end_x ; i++){
			for(j = start_y ; j < end_y; j++){
				if(pan[i][j]==1)
					stone++;
				else if(pan[i][j]==2)
					jewel++;
			}
			if(stone > 0 && jewel == 0){ //자를 수 있으면 
				res1 = cutting(start_x,start_y,i,end_y,SERO);
				if(res1==0)
					continue;
				res2 = cutting(i+1,start_y,end_x,end_y,SERO);
				if(res1!=0 && res2!=0){
					num+=res1*res2;
				}
			}
			stone = 0 ; jewel = 0;
		}
	}
	else{
		for(i = start_y; i < end_y ; i++){
			for(j = start_x ; j < end_x; j++){
				if(pan[j][i]==1)
					stone++;
				else if(pan[j][i]==2)
					jewel++;
			}
			if(stone > 0 && jewel == 0){
				res1 = cutting(start_x,start_y,end_x,i,GARO);
				if(res1==0)
					continue;
				res2 = cutting(start_x,i+1,end_x,end_y,GARO);			
				if(res1!=0 && res2!=0){
					num+=res1*res2;
				}
			}
			stone = 0; jewel = 0;
		}		
	}
	return num;
}

int main(){
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++)
			cin>>pan[i][j];
	}
	int ans = cutting(0,0,n,n,GARO) + cutting(0,0,n,n,SERO);
	if(ans==0)
		ans--;
	cout<<ans<<endl;
	return 0;
}
