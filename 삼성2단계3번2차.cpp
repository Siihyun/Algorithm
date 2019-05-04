#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct _p{
	int data;
	int id;
}p;

using namespace std;
int main() {
	int N,M,B,testcase;
	p v[20000];
	int x,y,id;
	int max_x = 0;
	int j;
	cin>>testcase;
	for(int k = 1 ; k <= testcase ; k++){
		for(int i = 0 ; i < 20000 ; i++){
			v[i].data = 987654321;
		}
	    scanf("%d",&N);
	    for(int i = 0 ; i < N ; i++){
	    	scanf("%d %d",&x,&y);
	    	if(x > max_x)
	    		max_x = x;
	    	if(v[x].data > y){
	    		v[x].data = y;
	    		v[x].id = i+1;
			}
	    }
	    int min_x,min_y;
	    for(int i = 0 ; i < N; i++){
	    	if(v[i].data != 987654321){
	    		min_x = i;
	    		min_y = v[i].data;
	    		break;
	    	}
		}
		printf("min x min y : %d %d \n",min_x,min_y);
		printf("max x : %d\n",max_x);
		for(int i = min_x+1 ; i <= max_x ; i++){
			printf("compared data : %d\n",v[i].data);
			if(v[i].data == 987654321)
				continue;
			if(v[i].data >= min_y){
				v[i].data = 987654321;
				continue;
			}
			else{
				min_y = v[i].data;
				printf("min_y changed to %d\n",min_y);
			}
		}
		cout<<"#"<<k;
		for(int i = 0 ; i < N; i++){
			if(v[i].data!=987654321)
				cout<<' '<<v[i].id<<' ';
		}
		cout<<endl;
	}
	    
    return 0;
}

