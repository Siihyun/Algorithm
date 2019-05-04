#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	vector<int> A;
	vector<int> B;
	int n;
	cin>>n;
	int num;
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&num);
		A.push_back(num);
	}
	sort(A.begin(),A.end(),greater<int>());
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&num);
		B.push_back(num);
	}
	sort(B.begin(),B.end(),less<int>());
	int sum = 0;
	for(int i = 0 ; i < n ; i++)
		sum+= A[i] * B[i];
	cout<<sum<<endl;
}
