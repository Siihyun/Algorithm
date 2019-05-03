#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[100][100]; // road arr
int result[100][100];
int visited[100][100]; // check if arr[i][j] is visited 
int dx[4] = {-1,1,0,0}; // directions for x
int dy[4] = {0,0,-1,1}; // directions for y
void dfs(int x,int y,int line){ 
	visited[x][y]++;
	cnt++;
	int a,b;
	for(int k = 0 ; k < 4 ; k++){
		a = x+dx[k]	, b = y+dy[k];
		if(a >= N || b >= N || a < 0 || b < 0)
			continue;
		if(arr[a][b] == 1){
			for(int i = 0 ; i < N ; i++){
				if(arr[a][i])
					result[line][b] = 1;
			}
			if(visited[a][b]==0){
				visited[a][b]++;
				dfs(a,b,line);
			}
		}
	}
}
int main(){
	int N;
	cin>>N;
//	int arr[N][N];
	vector<int> graph[N];
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]){
				graph[i].push_back(j);
			}
		}
	}
	for(int i = 0; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			if(arr[i][j] == 1 && visited[i][j]==0){
				for(int k = 0 ; k < N ; k++){
					dfs(i,j,k);
				}		
			}					
		}
	}	
}
