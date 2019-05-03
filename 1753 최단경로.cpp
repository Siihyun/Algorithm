#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>
 
#define MAX_SIZE 16
#define INF 0x7fffffff
#define MAX_V 20000
using namespace std;
typedef pair<int,int> P;
int v,e,k;
int dist[MAX_V];
bool visited[MAX_V]={0};
priority_queue<P,vector<P>,greater<P>> PQ;
int main{
	vector<P> adj[MAX_V];
	cin>>v>>e>>k;
	k--;
	//pair<int,int>(v-1,w);
	for(int i = 0 ; i < e ; i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u-1].push_back(P(v-1,w));
	}
	fill(dist, dist+MAX_V, INF);
	
	disk[k] = 0;
	PQ.push(P(0,K));
	while(!PQ.empty()){
		int cur;
		do{
			cur = PQ.top().second; // Á¤Á¡
			PQ.pop();
		}while(!PQ.empty() && visited[curr]);
		
		if(visited[curr]) break;
		for(vector<P> p = adj[cur]; p!=p.end(); p++){
			int next = p.first; int d = p.second;
			if(dist[next] > dist[cur] + d){
				dist[next] = dist[cur] + d;
			}
		}
	}
	for(int i = 0 ; i < V ; i++){
		if(dist[i] == INF) puts("INF");
		else cout<<dist[i]<<endl;
	}
}


