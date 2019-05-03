#include<iostream>
#include<stack>
using namespace std;
typedef struct{
	long long int num;
	int idx;
}His;
int main(){
	int N;
	stack<His> s;
	His a,tmp;
	His standard;
	long long int Max = 0;
	cin>>N;
	
	for(int i = 1 ; i <= N ; i++){
		cin>>a.num;
		a.idx = i; // standard element
		if(!s.empty()){
			tmp = s.top();
			while(tmp.num >= a.num && !s.empty()){
				s.pop();
				if(s.empty())
					tmp.idx = 1;
			//	printf("pop %d\n",tmp.num);
				long long int sqr = tmp.num * (i-tmp.idx);
		//		printf(" sqr = %d * %d = %d\n",tmp.num, i-tmp.idx,tmp.num * (i-tmp.idx));
				if(Max < sqr){
					Max = sqr;
					}
				if(!s.empty())
					tmp = s.top();
				}
			}
		s.push(a);
		//printf("push %d\n",a.num);
	}
		
	while(!s.empty()){
		tmp = s.top();
		long long int test;
		s.pop();
		//printf("pop %d\n",tmp.num);
		if(s.empty()){
			test = tmp.num * N;
		//	printf("1test = %d * %d = %d\n",tmp.num,N,tmp.num*N);
		}
		else{
			test = tmp.num * (N-s.top().idx);
		//	printf("test = %d * %d = %d\n",tmp.num,N-s.top().idx,tmp.num * (N-s.top().idx));
		}
		if(Max< test)
			Max = test;
		}
		
	cout<<Max<<endl;
}
