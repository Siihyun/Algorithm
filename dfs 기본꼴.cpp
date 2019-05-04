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
	cin >> n >> m;
	vector<int> adj[n];
	
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
