#include<iostream>
#include<vector>
#include<algorithm>
/* first , define structure which can save number and vertax number. 
   Next , count articulation point */
using namespace std;
int cnt = 0;
int max1 = 0;
vector<bool> visited;
typedef struct{
	int num;
	int ver_num;
}Array; 
void dfs(int start,vector<int> graph[],int max);
int main(){
	int n,m,k,testcase;
	visited.clear();
	cin>>n>>m>>k;
	Array arr[n+2][m+2];
//	printf("k = %d\n",k);
	for(int i = 0 ; i < k ; i++)
		visited.push_back(false);
	for(int i = 0 ; i < n+2 ; i++){
		for(int j = 0 ; j < m+2 ; j++){
			arr[i][j].num = 0;
		}
	}

	vector<int> graph[k];
	int row,col;
	for(int i = 0 ; i < k ; i++){
		scanf("%d %d",&row,&col);
		arr[row][col].num = 1;
		arr[row][col].ver_num = i;
//		printf("arr[%d][%d] is vertax %d\n",row,col,i);
	}
//	
//	for(int i = 1 ; i <= n ; i++){
//		for(int j = 1 ; j <= m; j++)
//			printf("%d ",arr[i][j]);
//		printf("\n");
////	}
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
		cnt = 0;
		dfs(i,graph,1);
		if(cnt>max1)
			max1 = cnt;
//		printf("\n\n");
	}
	
	printf("%d\n",max1);	
}
void dfs(int start, vector<int> graph[],int max){
	visited[start]= true;
//	printf("%d is visited!\n",start);
	cnt++;
	if(max > cnt)
		cnt = max;
	for(int i=0; i < graph[start].size(); i++){
		int next = graph[start][i];
		if(visited[next]==false){
			dfs(next, graph,max+1);
		}
	}
}
