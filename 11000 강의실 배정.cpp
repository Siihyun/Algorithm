#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
typedef struct{
	int s;
	int t;
}time;
bool Compare(const time& x,const time& y){
	if(x.s == y.s)
		return x.t < y.t;
	return x.s < y.s;
	
}
int main(){
	int i;
	priority_queue<int,vector<int>,greater<int> > pq;

	time t;
	vector<time> v;
	scanf("%d",&i);
	for(int j = 0 ; j < i ; j++){
		scanf("%d %d",&t.s,&t.t);
		v.push_back(t);
	}
	sort(v.begin(),v.end(),Compare);

	pq.push(v[0].t);
	for(int j = 1 ; j < i ; j++){
		if(pq.top()>v[j].s){
			pq.push(v[j].t);
		}
		else{
			pq.pop();
			pq.push(v[j].t);
			}	
		}
	printf("%d\n",pq.size());
	return 0;
}
