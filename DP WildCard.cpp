#include<iostream>
#include<cstring>
using namespace std;
char o_str[101];
char c_str[101];
int check = 0;
int o_len;
int c_len;
void solve(char *O_str,char *C_str,int idx){
	if(idx == o_len && idx == c_len){
      cout<<c_str<<endl;
      return;
  }
//	cout<<"idx ="<<idx<<endl;
   if(idx  == o_len && idx != c_len){
   		cout<<"here"<<endl;
      return;
  }
   if(*O_str != '*' && idx == c_len){
   		cout<<"here2"<<endl;
      return;
  }
   
   cout<<*O_str<<' '<<*C_str<<endl;
   if(*O_str == '*'){
      cout<<c_str<<endl;
      return;
   }
   if(*O_str == *C_str){
   		solve(O_str+1,C_str+1,idx+1);
   	}
   else if(*O_str == '?')
      solve(O_str+1,C_str+1,idx+1);
   else if(*O_str == '*'){
      for(int i = 0;i < strlen(C_str); i++){
         solve(O_str,C_str+i,idx+1);
      }
   }

   return;
   
}
int main(){
   int testcase;
   int num_str;
   cin>>testcase;
   while(testcase--){
      cin>>o_str;
      o_len = strlen(o_str);
      cin>>num_str;
      while(num_str--){
         cin>>c_str;
         c_len = strlen(c_str);
         cout<<o_len<<' '<<c_len<<endl;
         solve(o_str,c_str,0);
      }
   }
}
