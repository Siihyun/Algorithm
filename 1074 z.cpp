#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>
#include <cmath>
#define MAX_SIZE 16
#define INF 0x7fffffff
using namespace std;
int row,col,r,c,n,cnt,ans;
void draw_z(int r,int c,int n){
	if(n==0){
		if(row == r && col == c)
			ans = cnt;
		else
			cnt++;
		return;
	}
	
	int len = pow(2,n);
	if(row < r || row >= r+len || col < c || col >= c+len){ // 범위 안에 없으면 재귀 안하고 cnt만 더해줌 
		cnt+=pow(4,n);
		return;
	}
	len = pow(2,n-1);
	draw_z(r,c,n-1);
	draw_z(r,c+len,n-1);
	draw_z(r+len,c,n-1);
	draw_z(r+len,c+len,n-1);
	return; 
}
int main(){
	cin>>n>>row>>col;
	draw_z(0,0,n);
	cout<<ans<<endl;
}
