#include<iostream>
using namespace std;
int n,k,cnt,check,unplug,ans;
int A[101],multi[101],use[101];
int main(){
	cin>>n>>k;
	for(int i = 0 ; i < k ; i++){
		cin>>A[i];
	}
	for(int i = 0 ; i < k ; i++){
		if(multi[A[i]]) // 이미 꼽혀 있으면 
			continue;
		if(cnt < n){ // 멀티탭에 자리가 있으면 
			multi[A[i]]=1;
			cnt++;
			continue;
		}
		for(int j = 1; j <= k ; j++){ // 멀티탭에 꼽혀있는거 use배열에 옮김 
			if(multi[j])
				use[j]=1;
		}
		for(int j = i+1 ; j < k ; j++){ // 남은 꼽을 것들 중 멀티탭에 꼽혀있는게 있는거 체크. 제일 나중에 사용되는걸 찾기위한 for문 
			if(use[A[j]]){
				use[A[j]]= 0;
				unplug = A[j];
				check++;
			}
		}
		for(int j = 1 ; j <= k ; j++){ // use배열에 아직 남아있다는 말은  꼽혀있는 것 중 나중에도 사용되지 않는것을 뜻함 
			if(use[j]){
				unplug = j;
				use[j]=0;
				break;
			}
		}
		if(check==0){ // check == 0 이면 꼽혀 있는 것들중 다시 사용되는게 하나도 없는것이므로 아무거나 뽑음 
			for(int i = 0 ; i < n ; i++){
				if(multi[i]){
					unplug = i;
					break;
				}
			}
		}
		multi[unplug]=0;
		multi[A[i]]=1;
		check=0;
		ans++;
	}
	cout<<ans<<endl; 
}
