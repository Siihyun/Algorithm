#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>

// oper '(' have to be treated specially because its priority change from 5 to 0 
//when it goes into stack. It must be in the stack till it meet ')'.
using namespace std;
typedef struct{
	char op;
	int priority;
}oper;
int main(){
	stack<oper>	st;
	char input[1000];
	scanf("%s",input);
	int len = strlen(input);
	for(int i = 0 ; i < len ; i++){
		oper tmp;
		tmp.op = input[i];
		if(tmp.op == '(')
			tmp.priority = 5;
		else if(tmp.op == '+')
			tmp.priority = 1;
		else if(tmp.op == '-')
			tmp.priority = 1;
		else if(tmp.op == '*')
			tmp.priority = 2;
		else if(tmp.op == '/')
			tmp.priority = 2;
		else if(tmp.op == ')')
			tmp.priority = -1;
		else
			tmp.priority = 3; // tmp end
			
		if(st.empty()){
			if(tmp.op == '(')
				tmp.priority = 0;
			st.push(tmp);
		}
		else{ // stack is not empty
			if(tmp.op == ')'){
				while(st.top().op != '('){
					oper t = st.top();
					st.pop();
					printf("%c",t.op);
					if(st.empty())
						break;
				}
				st.pop();
			}
			else{
				if(st.top().priority >= tmp.priority){
					while(st.top().priority >= tmp.priority){
						oper t = st.top();
						if(t.op != '(')
							printf("%c",t.op);
						st.pop();
						if(st.empty())
							break;
						
					}
				}
				if(tmp.op == '(')
					tmp.priority = 0;
				st.push(tmp);
			}
		}
	}
	
	while(!st.empty()){
		oper t = st.top();
		if(t.op != '(')
			printf("%c",t.op);
		st.pop();				
	}
	
	return 0;
}

