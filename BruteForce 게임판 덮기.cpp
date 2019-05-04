#include<iostream>
#include<cstdlib> 
using namespace std;
int cnt=0;
int H,W;
void Countway(int **arr){
	int check = 0;
	int check1 =0;
	int i=0; int j=0;
	cout<<endl;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(!arr[i][j])
				check++;
		}
	}
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cout<<arr[i][j]<<' ';
		}
		cout<<endl;
	}
	if(check==0){
		cnt++;
		return;
	}
	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			
			cout<<"---i :"<<i<<"j--- :"<<j<<endl;
			if(arr[i][j]==1)
				continue;
			if(i+1<H && j+1<W){
				cout<<"type1"<<endl;
				if(arr[i][j] == 0 && arr[i][j+1] == 0 && arr[i+1][j+1] == 0){
					arr[i][j]++; arr[i][j+1]++; arr[i+1][j+1]++;
					Countway(arr);
					arr[i][j]--; arr[i][j+1]--; arr[i+1][j+1]--;
					
				}
			}
			if(i+1<H && j+1<W){			
				cout<<"type2"<<endl;
				if(arr[i][j] == 0 && arr[i+1][j] == 0 && arr[i+1][j+1] == 0){
					arr[i][j]++; arr[i+1][j]++; arr[i+1][j+1]++;
					Countway(arr);
					arr[i][j]--; arr[i+1][j]--; arr[i+1][j+1]--;
					
				}
			}
			if(i+1<H && j-1>=0){	
				cout<<"type3"<<endl;
				if(arr[i][j] == 0 && arr[i+1][j] == 0 && arr[i+1][j-1] == 0){
					arr[i][j]++; arr[i+1][j]++; arr[i+1][j-1]++;
					Countway(arr);
					arr[i][j]--; arr[i+1][j]--; arr[i+1][j-1]--;
				
				}
			}
			if(i+1<H && j+1<W){
				cout<<"type4"<<endl;
				if(arr[i][j] == 0 && arr[i][j+1] == 0 && arr[i+1][j] == 0){
					arr[i][j]++; arr[i][j+1]++; arr[i+1][j]++;
					Countway(arr);
					arr[i][j]--; arr[i][j+1]--; arr[i+1][j]--;
				
				}
			}
		if(arr[i][j]==0)
			break;
		}
		if(arr[i][j-1]==0)
			break;
	
	}
	cout<<"i :"<<i<<"j :"<<j<<endl;
	if(i==H && j==W)
		cnt++;
}
int main(void){
	int **arr;
	int testcase;
	
	cin>>testcase;

	while(testcase--){
		cnt =0;
		cin>>H>>W;
		arr = new int*[H];
		for(int i=0;i<W;i++)
			arr[i] = new int[W];
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++)
				cin>>arr[i][j];
		}
		Countway(arr);
		cout<<cnt<<endl;
		for(int i=0;i<H;i++)
			delete []arr[i];
		delete []arr;
		
	}
	return 0;
}
