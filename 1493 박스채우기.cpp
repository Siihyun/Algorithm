#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
using namespace std;
vector< pair<int,int> > v;
int N,a,b,cnt=0;
long long x,y,z;
bool Compare(const pair<int,int> &a,const pair<int,int> &b){
	return a.first > b.first;
}
int main(){
	scanf("%lld%lld%lld",&x,&y,&z);
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++){
		scanf("%d%d",&a,&b);
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(),v.end(),Compare);
//	for(int i = 0 ; i < N ; i++)
//		printf("%d %d\n",v[i].first,v[i].second);
	long long volume = x*y*z;
	long long v2;
	for(int i = 0 ; i < N ; i++){
		long long length = pow(2,v[i].first);
//		printf("length : %lld\n",length);
		if(length > x || length > y){
				continue;
		}
		if(length > z)
			continue;
		while(v[i].second>0 && volume>0){
			v2 = pow(length,3);
	//		printf("volume = %lld\n",volume);
			volume-= v2;
			v[i].second--;
			cnt++;
		}
	}
	if(volume==0)
		printf("%d",cnt);
	else
		printf("-1");
	return 0;
}
