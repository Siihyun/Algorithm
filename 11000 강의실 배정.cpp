#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct{
	int s;
	int t;
}time;
bool Compare(const time& x,const time& y){
	if(x.t == y.t)
		return x.s < y.s;
	return x.t < y.t;
	
}
int main(){
	int i,cnt=1,lec_cnt=1;
	int lecture[200000]={0};
	time t;
	vector<time> v;
	scanf("%d",&i);
	for(int j = 0 ; j < i ; j++){
		scanf("%d %d",&t.s,&t.t);
		v.push_back(t);
	}
	sort(v.begin(),v.end(),Compare);

	lecture[0] = v[0].t;
	for(int j = 1 ; j < i ; j++){
		for(int k = 0 ; k < 200000; k++){
			if(lecture[k]==0 || lecture[k] <= v[j].s){
				if(lecture[k]==0)
					lec_cnt++;
				lecture[k] = v[j].t;
				break;
			}
		}
	}

	printf("%d\n",lec_cnt);
	return 0;
}
