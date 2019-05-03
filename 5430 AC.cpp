#include<cstdio>
#include<deque>
#include<algorithm>
using namespace std;


int main(){
	int testcase,n;
	bool end_program;
	bool rev;
	int multi = 1;
	deque<int> dq;
	deque<int>::iterator iter;
	scanf("%d",&testcase);
	while(testcase--){
		char command[100005];
		dq.clear();
        scanf("%s",command);
        scanf("%d",&n);
        int x = 0;
        while(1){
            char c = getchar();
            if(c >= '0' && c <= '9') x = x*10 + c-'0';
            else{
                if(x > 0) dq.push_back(x);
                x = 0;
                if(c == ']') break;
            }
        }
        
        end_program = false; rev = false;
		for(int i = 0 ; command[i]; i++){
			if(command[i] == 'R')
				rev  = !rev;
			else{
				if(dq.empty()){
					end_program = true;
					break;
				}
				if(rev)
					dq.pop_back();
				else
					dq.pop_front();
			}
		}
		if(end_program)	
			puts("error");
	/*
		else{
            putchar('[');
            // 덱이 뒤집힌 상태면 진짜로 뒤집어 준다.
            if(rev) reverse(dq.begin(), dq.end());
            for(int i=0; i<dq.size(); i++){
                printf("%d", dq[i]);
                if(i < dq.size()-1) putchar(',');
            }
            puts("]");
        }
        */

		else{
			if(rev)
				reverse(dq.begin(),dq.end());
			printf("[");
			for(int i = 0 ; i < dq.size() ; i++){
				printf("%d",dq[i]);
				if(i < dq.size()-1) putchar(',');
			}
			printf("]\n");
			}
		}
		

}
