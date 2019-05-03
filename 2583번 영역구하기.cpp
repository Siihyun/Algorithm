#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stack>
int cnt=0;
using namespace std;
char arr[26][26];
int visited[25][25];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int N,M,K;
vector<int> list;
void dfs(int x,int y){
	//printf("visit arr[%d][%d]!\n",x,y);
	visited[x][y]++;
	cnt++;
	int a,b;
	for(int k = 0 ; k < 4 ; k++){
		a = x+dx[k]	, b = y+dy[k];
		if(a >= M || b >= N || a < 0 || b < 0)
			continue;
		if(arr[a][b] == '1' && visited[a][b]==0){
			visited[a][b]++;
			dfs(a,b);
		}
	}
}
int main(){
	int x,y;

	cin>>M>>N>>K;
	for(int i = 0; i < M ; i++){
		for(int j = 0 ; j < N ; j++){
			visited[i][j] = 0;
			arr[i][j] = '1';
		}
	}
	
	int a,b,c,d;
	while(K--){
		scanf("%d %d %d %d",&a,&b,&c,&d);
	//	printf("%d %d %d %d \n",a,b,c,d);
		for(int i = b ; i < d ; i++){
			for(int j = a ; j < c ; j++)
				arr[i][j] = '0';
			}
		}
	for(int i = 0 ; i < M ; i++){
		for(int j = 0 ; j < N ; j++)
			printf("%c ",arr[i][j]);
		printf("\n");
	}
	for(int i = 0; i < M ; i++){
		for(int j = 0 ; j < N ; j++){
			if(arr[i][j] == '1' && visited[i][j]==0){
		//		printf("\n");
				cnt = 0;
				dfs(i,j);
				list.push_back(cnt);
					}					
				}
			}
	int j;
	printf("%d\n",list.size());
	sort(list.begin(), list.end());
	for(j=0; j<list.size()-1; j++)
		printf("%d ",list[j]);
	printf("%d",list[j]);
	
}
