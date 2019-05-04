#include<iostream>
using namespace std;
int n,A[100001];
int get_ans(int left,int right){
	int small,large,M=0,height,mid_sum,left_sum,right_sum,left_idx,right_idx,length=2;
	int mid = (left+right)/2;
	if(left == right)	
		return A[left];
	if(right-left == 1){
		small = min(A[right],A[left]);
		large = max(A[right],A[left]);
		return max(small*2,large);
	}
	left_sum = get_ans(left,mid);
	right_sum = get_ans(mid+1,right);
	mid_sum = A[mid];
	
	left_idx = mid-1; right_idx = mid+1; height = A[mid];
	
	while(1){
		if(left_idx < left || right_idx > right)
			break;
		if(A[left_idx] >= A[right_idx]){
			if(A[left_idx]<height)
				height = A[left_idx];
			mid_sum = height*length;
			left_idx--;
		}
		else{
			if(A[right_idx]<height)
				height = A[right_idx];
			mid_sum = height * length;
			right_idx++;
		}
		if(M < mid_sum)
			M = mid_sum;
		length++;
	}
	
	
	while(left_idx >= left){
		if(A[left_idx]<height)
			height = A[left_idx];
		mid_sum = height*length;	
		left_idx--;
		
		if(M < mid_sum)
			M = mid_sum;
		length++;
	}
	while(right_idx <= right){
		if(A[right_idx]<height)
			height = A[right_idx];
		mid_sum = height * length;
		right_idx++;
		
		if(M < mid_sum)
			M = mid_sum;
		length++;
	}
	return max(max(left_sum,right_sum),M);
}
int main(){
	cin>>n;
	for(int i = 0 ; i < n ; i++)
		cin>>A[i];
	cout<<get_ans(0,n-1)<<endl;
}
