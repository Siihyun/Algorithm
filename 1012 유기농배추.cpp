#include<iostream>
#include<vector>
#include<algorithm>
/* first , define structure which can save number and vertax number. 
   Next , count articulation point */
using namespace std;
vector<bool> visited;
typedef struct{
	int num;
	int ver_num;
}Array; 
void dfs(int start,vector<int> graph[]);
int main(){
	int n,m,k,testcase;
	cin>>testcase;
	while(testcase--){
		visited.clear();
		cin>>m>>n>>k;
		Array arr[n+2][m+2];
		for(int i = 0 ; i < k ; i++)
			visited.push_back(false);
		for(int i = 0 ; i < n+2 ; i++){
			for(int j = 0 ; j < m+2 ; j++){
				arr[i][j].num = 0;
			}
		}
		vector<int> graph[k];
		int row,col;
		int cnt = 0;
		for(int i = 0 ; i < k ; i++){
			scanf("%d %d",&col,&row);
			arr[row+1][col+1].num = 1;
			arr[row+1][col+1].ver_num = i;
		}
		for(int i = 1 ; i <= n; i++){
			for(int j = 1 ; j <= m ; j++){
				if(arr[i][j].num){
					if(arr[i][j+1].num){
						graph[arr[i][j].ver_num].push_back(arr[i][j+1].ver_num);
						graph[arr[i][j+1].ver_num].push_back(arr[i][j].ver_num);
					}
					if(arr[i+1][j].num){
						graph[arr[i][j].ver_num].push_back(arr[i+1][j].ver_num);
						graph[arr[i+1][j].ver_num].push_back(arr[i][j].ver_num);
					}
				}
			}
		}
		for(int i=0; i<k; i++){
			sort(graph[i].begin(), graph[i].end());
		}
		
		while(1){
			int check,i;
			for(i = 0 ; i < k; i++){
				if(visited[i] == false)
					break;
				}
			if(i == k)
				break;
			cnt++;
			dfs(i,graph);
		}
	
		printf("%d\n",cnt);
	}
	
	
}
void dfs(int start, vector<int> graph[]){
	visited[start]= true;
	for(int i=0; i < graph[start].size(); i++){
		int next = graph[start][i];
		if(visited[next]==false){
			dfs(next, graph);
		}
	}
}
