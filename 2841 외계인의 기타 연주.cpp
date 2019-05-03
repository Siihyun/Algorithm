/* 2841 외계인의 기타연수 */
#include<iostream> 
#include<stack>
using namespace std;
int main(){
	stack<int> st[7];
	int N,P,cnt = 0;
	int line,outside;
	bool empty_check = false;
	int popnum;
	cin>>N>>P;
	while(N--){
		empty_check = false;
		scanf("%d %d",&line,&outside);
		if(st[line].empty()) // if there isn't any pushed note at line _line
			st[line].push(outside);	// just push
		else if(st[line].top() == outside) // same pitch's note is already played
			continue;  // no need to push
		else if(st[line].top() < outside) // if it is possible to push that note without pop
			st[line].push(outside);
		else{  // if pop is needed
			while(st[line].top() > outside){
				popnum = st[line].top();
				st[line].pop();
				cnt++;
				if(st[line].empty()){
					empty_check = true;
					break;
				}
			}
			if(!empty_check){
				if(st[line].top() == outside)
					continue;
			}
			st[line].push(outside);
		}
		cnt++;
	}
	cout<<cnt<<endl;
}
