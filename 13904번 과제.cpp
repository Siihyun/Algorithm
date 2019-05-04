#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct{
	int day;
	int score;
}as;

bool Compare(const as &a,const as &b){
	return a.score > b.score;
}
int main(){
	int N;
	int day[1001]={0};
	cin>>N;
	vector<as> v;
	as tmp;
	for(int i = 0 ; i < N ; i++){
		scanf("%d %d",&tmp.day,&tmp.score);
		v.push_back(tmp);
	}
//	printf("aaaa");
	sort(v.begin(),v.end(),Compare);
	
	
	int ans = 0;
	for(int i = 0 ; i < N ; i++){
		for(int j = v[i].day; j > 0; j--){
			if(day[j]==0){
				day[j]=1;
				ans+=v[i].score;
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
