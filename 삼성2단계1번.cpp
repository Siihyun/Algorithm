#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N,M,B,testcase;
	vector<int> v(20001,0);
	vector<int> check;
	int tmp1,tmp2;
	cin>>testcase;
	while(testcase--){
	    cin>>N>>M>>B;
	    for(int i = 0 ; i < M ; i++){
	    	cin>>tmp1>>tmp2;
	    	v[tmp1] = tmp2;
	    	check.push_back(tmp1);
	    }
	    while(N!=0){
	    	sort(check.begin(),check.end(),greater<int>());
	    	for(int i =0 ; i < check.size(); i++)
	    		cout<<check[i]<<endl;
	    	N = 0;
		}
	    
	}
    return 0;
}

