#include<iostream>
#include<cstring>
#include<vector>
#include<list>
using namespace std;
char o_str[101];
char c_str[101];
int check = 0;
int o_len;
int c_len;
vector<int> v;
list<string> lt;

int solve(char *O_str,char *C_str,int idx,int idx1){
	check = 0;
//	cout<<O_str[0]<<' '<<C_str[0]<<endl;
	if(idx == o_len && idx1 == c_len){
		if(O_str[0] == C_str[0] || O_str[0] == '*' || O_str[0] == '?')
			lt.push_back(c_str);
      	return 1;
  	}

   	else if(idx  != o_len && idx1 == c_len){ // 아래가 먼저 끝 
    	if(O_str[0] == C_str[0] && *(O_str+1) == '*'){
    		lt.push_back(c_str);
    	}
    	else if(O_str[0] == '*' && O_str[1] == '?'){
    		lt.push_back(c_str);
    	}
    	return 1;
	}
    else if(idx == o_len && idx1 != c_len){ // 위에가 먼저 끝 
        if(O_str[0] == '*'){
        	lt.push_back(c_str);
        }
      	return 1;
  	}
  	


    if(*O_str == *C_str){ // 같을때 
          solve(O_str+1,C_str+1,idx+1,idx1+1);
       }
    else if(*O_str == '?') // 다를때 
       solve(O_str+1,C_str+1,idx+1,idx1+1);
    else if(*O_str == '*'){ // 다를떄 
       for(int i = 0;i < strlen(C_str); i++){
          check =solve(O_str+1,C_str+i,idx+1,idx1+i);
          if(check == 1)
          	break;
       }
    }
 	else
    	return -1;
   
}
int main(){
    int testcase;
    int num_str;
    cin>>testcase;
    while(testcase--){
       cin>>o_str;
       o_len = strlen(o_str)-1;
       cin>>num_str;
       while(num_str--){
          cin>>c_str;
          c_len = strlen(c_str)-1;
          solve(o_str,c_str,0,0);
       }
    }
	lt.sort();
    list<string>::iterator iter;
  //  cout<<"sol :";
    for(iter = lt.begin(); iter != lt.end(); ++ iter)
    	cout<< *iter<<endl;

}
