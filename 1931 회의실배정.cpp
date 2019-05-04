#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct{
	int start;
	int end;
}time;
bool Compare(const time& x,const time& y){
	if(x.end == y.end)
		return x.start < y.start;
	return x.end < y.end;
	
}
int main(){
	int i,cnt=1,end_time = 0;
	time t;
	vector<time> v;
	scanf("%d",&i);
	for(int j = 0 ; j < i ; j++){
		scanf("%d %d",&t.start,&t.end);
		v.push_back(t);
	}
	sort(v.begin(),v.end(),Compare);

	end_time = v[0].end;
	for(int j = 1 ; j < i ; j++){
		if(end_time <= v[j].start){
			end_time = v[j].end;
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
