/* #3986 좋은단어 */
#include<iostream> 
#include<stack>
#include<cstring> 
using namespace std;
int main(){
	stack<int> st;
	char word[100001];
	int testcase,cnt = 0;
	cin>>testcase;
	while(testcase--){
		scanf("%s",word);
		int len = strlen(word);
		for(int i = 0 ; i < len ; i++ ){
			if(st.empty())
				st.push(word[i]);
			else if(st.top() == word[i] )
				st.pop();
			else
				st.push(word[i]);
		}
		if(st.empty())
			cnt++;
		while(!st.empty()) // clear stack for new case
			st.pop();	
	}
	cout<<cnt<<endl;
}
