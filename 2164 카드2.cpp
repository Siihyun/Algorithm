#include<iostream>
#include<queue>
using namespace std; 
int main(){
	int N;
	int sol;
	cin>>N;
	queue<int> q;
	for(int i = 1 ; i <= N ; i++){
		q.push(i);
	}
	while(q.size()>1){
		q.pop();
		sol = q.front();
		q.pop();
		q.push(sol);
	}
	cout<<q.front()<<endl;
}
