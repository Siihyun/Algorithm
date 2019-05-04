#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int cnt = 0,N,M,K;
const int MAX = 100+1;
bool possible = true;
string word;
int cache[MAX][MAX];

int get_comb(int A,int Z){
	if(A==0 || Z==0)
		return 1;
	int &result = cache[A][Z];
	if(result != -1)
		return result;
	result= min(get_comb(A-1,Z)+get_comb(A,Z-1),1000000000 + 1);
	return result;
}

void get_answer(int A,int Z,int K){
	if (A == 0){
      	for (int i = 0; i < Z; i++)
			word += 'z';
		return;
    }
    if (Z == 0){
 		for (int i = 0; i < A; i++)
 			word += 'a';
		return;
	}
	
	int idx = get_comb(A-1,Z);
	if(K<idx){
		word+="a";
		get_answer(A-1,Z,K);
	}
	else if(K<=1000000000){
		word+="z";
		get_answer(A,Z-1,K-idx);
	}
	else{
		possible=false;
	}
}

int main(){
	memset(cache,-1,sizeof(cache));
	scanf("%d%d%d",&N,&M,&K);
	int num = get_comb(N,M);
	if(num < K){
		printf("-1");
		return 0;
	}
	get_answer(N,M,K-1);
	if(possible)
		cout<<word<<endl;
	else
		cout<<"-1"<<endl;
	return 0;
}
