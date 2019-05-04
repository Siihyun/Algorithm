#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>
#include <functional>
 
#define MAX_SIZE 16
#define INF 0x7fffffff
using namespace std;
long long a,b,c;
int main(){
	cin>>a>>b>>c;
	long long tmp = a%c;
	long long tmp2 = (a*a)%c;
	for(int i = 3 ; i <= b ; i++){
		tmp2 = (tmp*a)%c;
	}
	cout<<tmp2<<endl;
}

