#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<bool> visited;
void dfs(int start, vector<int> graph[]){
	visited[start]= true;
//	printf("%d ", start);

	for(int i=0; i < graph[start].size(); i++){
		int next = graph[start][i];
		if(visited[next]==false){
			dfs(next, graph);
		}
	}
}

int main(){
	int n,m;
	int num_of_vertax;
	int num_of_edge;
	int testcase;
	cin>>testcase;
	while(testcase--){		
		cin >> m >> n >> num_of_vertax;
		int arr[n+1][m+1];
		for(int i = 0 ; i <= n ; i++){
			for(int j = 0 ; j <=m; j++)
				arr[i][j] = 0;
		} // array initialize
		
		vector<int> adj[num_of_vertax];
		while(num_of_vertax--){
			scanf("%d %d",&n,&m);
			arr[n][m] = 1;
		}
		
		int check = 0; bool check1 = true;
		
		for(int i = 1 ; i < n ; i++){ // make graph
			for(int j = 1 ; j < m ; j++){
				check1 = false;
				if(arr[i][j+1]){
					adj[check].push_back(check+1);
	      			adj[check+1].push_back(check);
	      			check1 = true;
				}
				if(arr[i+1][j]){
					adj[check].push_back(check+1);
	      			adj[check+1].push_back(check);
	      			check1 = true;
				}
				if(check1)
					check++;
			}
		}
		
		
		int cnt = 0;
		
		for(int i = 0 ; i < n ; i++)
			visited.push_back(false);
		
		for(int i=0; i<m; i++){
	        int u,v;
	        scanf("%d %d", &u, &v);
	        adj[u-1].push_back(v-1);
	        adj[v-1].push_back(u-1);
	    }
	    for(int i=0; i<n; i++)
	            sort(adj[i].begin(), adj[i].end());
	    
	    
		while(1){
			int check,i;
			for(i = 0 ; i < n; i++){
				if(visited[i] == false)
					break;
			}
			if(i == n)
				break;
			cnt++;
			dfs(i,adj);	
		}
	
		printf("%d\n",cnt);
}
}
