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
		if(multi[A[i]]) // �̹� ���� ������ 
			continue;
		if(cnt < n){ // ��Ƽ�ǿ� �ڸ��� ������ 
			multi[A[i]]=1;
			cnt++;
			continue;
		}
		for(int j = 1; j <= k ; j++){ // ��Ƽ�ǿ� �����ִ°� use�迭�� �ű� 
			if(multi[j])
				use[j]=1;
		}
		for(int j = i+1 ; j < k ; j++){ // ���� ���� �͵� �� ��Ƽ�ǿ� �����ִ°� �ִ°� üũ. ���� ���߿� ���Ǵ°� ã������ for�� 
			if(use[A[j]]){
				use[A[j]]= 0;
				unplug = A[j];
				check++;
			}
		}
		for(int j = 1 ; j <= k ; j++){ // use�迭�� ���� �����ִٴ� ����  �����ִ� �� �� ���߿��� ������ �ʴ°��� ���� 
			if(use[j]){
				unplug = j;
				use[j]=0;
				break;
			}
		}
		if(check==0){ // check == 0 �̸� ���� �ִ� �͵��� �ٽ� ���Ǵ°� �ϳ��� ���°��̹Ƿ� �ƹ��ų� ���� 
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
