#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stack>
int cnt=0;
using namespace std;
char arr[101][101]; // road arr
int visited[100][100]; // check if arr[i][j] is visited 
int dx[4] = {-1,1,0,0}; // directions for x
int dy[4] = {0,0,-1,1}; // directions for y
int n;
vector<int> list; // store the size of each component
void dfs(int x,int y,char check) {
	visited[x][y]++;
	cnt++;
	int a,b;
	for(int k = 0 ; k < 4 ; k++){
		a = x+dx[k]	, b = y+dy[k];
		if(a >= n || b >= n || a < 0 || b < 0)
			continue;
		if(arr[a][b] == check && visited[a][b]==0){
			visited[a][b]++;
			dfs(a,b,check);
		}
	}
}
int main(){
	int N;
	int x,y;
	char check; 
	cin>>N;
	n = N;
	for(int i = 0; i < N ; i++){
		for(int j = 0 ; j < N ; j++)
			visited[i][j] = 0;
	}
	for(int i = 0 ; i < N; i ++)
			scanf("%s",&arr[i]);

	for(int i = 0; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			check = arr[i][j];
			if(visited[i][j]==0){
				cnt = 0;
				dfs(i,j,check);
				list.push_back(cnt);
					}					
				}	
			}
	printf("%d ",list.size());
	list.clear();
	for(int i = 0; i < N ; i++){
		for(int j = 0 ; j < N ; j++)
			if(arr[i][j] == 'R')
				arr[i][j] = 'G';
	}
	for(int i = 0; i < N ; i++){
		for(int j = 0 ; j < N ; j++)
			visited[i][j] = 0;
	}
	cnt = 0;
	for(int i = 0; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			check = arr[i][j];
			if(visited[i][j]==0){
				cnt = 0;
				dfs(i,j,check);
				list.push_back(cnt);
					}					
				}	
			}
	printf("%d",list.size());
}
