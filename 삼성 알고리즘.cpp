#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {  
    vector<char> arr;
    char c[100000];
    int testcase;
    int N;
    char ch;
    char temp;
    string str;
    vector<char> v;
    cin>>testcase;
    getchar();
    for(int k = 0 ; k < testcase; k++){
        cin>>N;
    	fflush(stdin);
     // getchar();
      scanf("%c",&ch);
      //getchar();
      //fflush(stdin);
      v.push_back(ch);
   //   printf("v[0] = %c\n",v[0]);
        for(int i = 1 ; i < N ; i++ ){
            scanf("%c",&c[i]);
      //      printf("c[i] = %c\n",c[i]);
            if(c[i]==' '){
          //  	printf("space\n");
            	i--;
            	continue;
			}
            //getchar();
      //      printf("front : %c\n",v.front());
            if(v.front()>c[i]){
	//			printf("here1\n");
            	v.push_back(c[i]);
            }
            else{
	//			printf("here2\n");
            	v.insert(v.begin(),c[i]);
            }
     //       for(int i = 0 ; i < v.size() ; i++)
    //        	printf("%c",v[i]);
        }
       
        /*
            if(c[i]==' '){
            	i--;
            	continue;
            }
            getchar();
    	}
    	
    	getchar();

    	str+=c[0];
    	temp = c[1];
    //	cout<<"new str : "<<str<<endl<<endl;
    	
    	for(int i = 1 ; i < N ; i++){
    //		printf("%d %d",temp,c[0]);
			if(temp>c[i]){
				temp = c[i];
                str = c[i] + str;
       //         cout<<"1 : "<<str<<endl;
            }
            else{
                str+= c[i];
       //         cout<<"2 : "<<str<<endl;
            }
        }
        */
        printf("#%d ",k);
        for(int i = 0 ; i < N ; i++)
        	printf("%c",v[i]);
        cout<<endl;
    	v.clear();
    }
        
    return 0;
}

