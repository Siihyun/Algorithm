#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int N,K,tmp,ans=0;
	cin>>N>>K;
	
	vector<int> v;
	for(int i = 0 ; i < N ; i++){
		cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());

	for(int i = 0 ; i < N-1 ; i++){
		v[i] = v[i+1]-v[i];
		ans+=v[i];
	}
	sort(v.begin(),v.end()-1,greater<int>());
	
//	for(int i = 0 ; i < N-1 ; i++)
//		cout<<v[i]<<endl;
	for(int i = 0 ; i < K-1 && i < N ; i++)
		ans-=v[i];
	cout<<ans<<endl;
	return 0;
}
