#include<iostream>
#include<deque>
using namespace std;
typedef struct{
	int num;
	bool check;
}check;
int main(){
	int testcase,N,M;
	int sol;
	deque<check> dq;
	cin>>testcase;
	int end_program;
	check temp , print , num;
	while(testcase--){
		sol = 1;
		dq.clear();
		cin>>N>>M;
		for(int i = 0 ; i < N; i ++){
			cin>>temp.num;
			if(i == M)
				temp.check = true;
			else
				temp.check = false;
			dq.push_back(temp);
		}
		print = dq[0];
		while(!dq.empty()){
			for(int i = 1 ; i < dq.size(); i++){
				if(dq[i].num > dq[0].num){
					temp = dq.front();
					dq.pop_front();
					dq.push_back(temp);
					i = 0;
				}
			}
			num = dq.front();
			if(num.check == true){
				break;
			}		
			dq.pop_front();
			sol++;
		}
		cout<<sol<<endl;
	}	
}
