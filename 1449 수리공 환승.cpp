#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;
int main(){
   int N,L;
   int cnt=0, tmp,idx;
   scanf("%d %d",&N,&L);
   
   vector<int> hole;
   vector<int> pipe(10000,0);
   
   if(L==1){
      printf("%d\n",N);
      return 0;
   }

   for(int i = 0 ; i < N ; i++){
      scanf("%d",&tmp);
      hole.push_back(tmp);
   }
   sort(hole.begin(),hole.end());

   for(int i = 0 ; i < N ; i++){
    	if(pipe[hole[i]-1]==0 && pipe[hole[i]]==0){
    		idx = hole[i]-1;
    		for(int j = 0 ; j <= L; j++){
    			pipe[idx]=1;
    			idx++;
    		}
    		cnt++;
		}
		else if(pipe[hole[i]]==0){
			idx = hole[i];
    		for(int j = 0 ; j <= L; j++){
    			pipe[idx]=1;
    			idx++;
    		}
    		cnt++;
    	}
   }
   printf("%d\n",cnt);
}
