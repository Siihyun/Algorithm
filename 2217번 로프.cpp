#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int num,tmp;
	vector<int> v;
	scanf("%d",&num);
	for(int i = 0 ; i < num; i++){
		scanf("%d",&tmp);
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	int max = v[0]*num;
	for(int i = 1 ; i < num; i++){
		if(v[i]*(num-i) > max)
			max = v[i]*(num-i);
	}

	printf("%d\n",max);
	return 0;
}
