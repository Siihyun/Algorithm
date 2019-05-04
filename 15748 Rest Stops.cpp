#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct{
	long long height;
	long long score;
}as;

bool Compare(const as &a,const as &b){
	if(a.score == b.score){
		return a.height < b.height;
	}
	return a.score > b.score;
}
long long L,N,rf,rb,res=0,height=0,coin=0;
vector<as> v;
as tmp;

int main() {
    scanf("%lld %lld %lld %lld",&L,&N,&rf,&rb);
	int speed = rf-rb;
	for(int i = 0 ; i < N ; i++){
		scanf("%lld %lld",&tmp.height,&tmp.score);
		v.push_back(tmp);
	}
    sort(v.begin(),v.end(),Compare);
  //	for(int i = 0 ; i < N ; i++){
  //		printf("%d %d\n",v[i].height,v[i].score);
//	}
    for(int i = 0 ; i < N ; i++){
    	if(v[i].height < height)
    		continue;
    	coin = (v[i].height - height)*speed;
    	res+= coin * v[i].score;
    	height = v[i].height;
	}
    printf("%lld", res);
    return 0;
}


