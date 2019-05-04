#include<iostream>
#include<string>
#include<stack>
#include<string.h>
using namespace std;
int main(){
	char str[256];
	stack<string> st;
	scanf("%[^\n]",str);
	printf("%s\n",str);
	int len = strlen(str);
	int i=0;
	bool pop_mode;
	int j = 0;
	for(i = 0 ; i < len ; i++){
		j = 0;
		pop_mode = false;
		if(str[i] == '<'){
			printf("< detected at %d\n",i);
			char tmp[256];
			if(str[i+1] == '/'){ // if it has closing tag
				pop_mode = true;
			}
			while(str[i] != '>' && i<len){
				if(str[i]=='/' && pop_mode){
					i++; continue;
				}
				tmp[j++] = str[i++];
			}
			tmp[j++] = '>';
			tmp[j] = '\0';
			
			string a = tmp;
			printf("%s\n",tmp);
			if(!pop_mode){
				st.push(a);
			}
			else{ // pop_mode
				if(st.empty()){ // empty
					printf("illegal\n");
					break;
				}
				else if(!st.top().compare(tmp))
					st.pop();
				else{
					printf("illegal\n");
					break;
				}
			}
		}
	}
	if(!st.empty())
		printf("illegal\n");
	else
		printf("legal\n");
	return 0;
}
