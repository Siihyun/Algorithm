#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct _p{
	int x;
	int y;
	int N;
}p;
bool ComparewithX(const p& a,const p& b){
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}
bool ComparewithY(const p& a,const p& b){
	if(a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

using namespace std;
int main() {
	int N,M,B,testcase;
	vector<p> v;
	p tmp;
	int len = 0;
	cin>>testcase;
	for(int k = 1 ; k <= testcase ; k++){
	    cin>>N;
	    for(int i = 0 ; i < N ; i++){
	    	tmp.N = i+1;;
	    	cin>>tmp.x>>tmp.y;
	    	v.push_back(tmp);
	    }
	    len = v.size();
		sort(v.begin(),v.end(),ComparewithX);
		len = v.size();
		int i = 1;
	    for(int j = 1 ; j < len; j++){
			if(v[i-1].y==v[i].y){
				v.erase(v.begin()+i);
			}
			else
				i++;
		}
		int least = v[0].y;
		len = v.size();
		i = 1;
		for(int j = 1 ; j < len; j++){
			if(v[i].y>=v[i-1].y){
				v.erase(v.begin()+i);
				continue;
			}
			else{
				least = v[i].y;
				i++;
			}
		}
		cout<<"#"<<k;
		len = v.size();
		for(int i = 0 ; i < len; i++){
			cout<<' '<<v[i].N<<' ';
		}
		cout<<endl;
		v.clear();
	}
	    
    return 0;
}

