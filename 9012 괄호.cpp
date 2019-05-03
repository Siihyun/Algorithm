#include<iostream>
#include<stack>
using namespace std;
int main(){
	int testcase;
	bool check = false;
	stack<char> st;
	cin>>testcase;
	while(testcase--){
		check = false;
		char test[50];
		scanf("%s",test);
		for(int i = 0 ; test[i] ; i++){
			if(test[i] == '(')
				st.push(test[i]);
			else if(test[i] ==')'){
				if(st.empty()){
					printf("NO\n"); // ')' are more than '('
					check = true;
					break;
				}
				st.pop();
			}
		}
		if(!st.empty()){
			while(!st.empty()) 
				st.pop();
			printf("NO\n"); // '(' are more than ')'
			continue;
		}
		if(!check)
			printf("YES\n");
		
	}
	return 0;
}
