#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long *A;
long long get_answer(int left,int right){
	long long start;
	long long left_sum,right_sum,mid_sum,mid,Min,Max=0;
	mid = (left+right)/2;
//	printf("left : %d mid : %d right : %d\n",left,mid,right);
	if(left==right){
//		printf("return %d\n",A[left]*A[left]);
		return A[left]*A[left];
	}
	left_sum = get_answer(left,mid);
	right_sum = get_answer(mid+1,right);
	if(right-left==1){
		mid_sum = A[left]+A[right];
		Min = min(A[left],A[right]);
		long long tmp = max(left_sum,right_sum);
		return max(tmp,mid_sum * Min);
	}
	long long val = A[mid]+A[mid+1];
	Min = min(A[mid],A[mid+1]);
	Max = val * Min;
	int left_idx = mid-1;
	int right_idx = mid+2;
//	printf("before while , left : %d mid : %d right : %d\n",left,mid,right);
	while(1){
//		printf("left idx : %d , right_idx : %d\n",left_idx,right_idx);
		if(left_idx < left || right_idx > right)
			break;
		if(A[left_idx] >= A[right_idx]){
			val+=A[left_idx];
			if(A[left_idx] < Min)
				Min = A[left_idx];
			if(val * Min > Max)
				Max = val * Min;
			left_idx--;
		}
		else{
			val+=A[right_idx];
			if(A[right_idx] < Min)
				Min = A[right_idx];
			if(val * Min > Max)
				Max = val * Min;
			right_idx++;
		}
	}
	while(left_idx >= left){
		val+=A[left_idx];
		if(A[left_idx] < Min)
			Min = A[left_idx];
		if(val * Min > Max)
			Max = val * Min;
		left_idx--;
	}
	while(right_idx <= right){
		val+=A[right_idx];
		if(A[right_idx] < Min)
			Min = A[right_idx];
		if(val * Min > Max)
			Max = val * Min;
		right_idx++;
	}
	return max(left_sum,right_sum) >= Max ? max(left_sum,right_sum) : Max;
}
int main(){
	int N;
	cin>>N;
	A = new long long[N];
	for(int i = 0 ; i < N ; i++){
		scanf("%lld",&A[i]);
	}
	long long ans = get_answer(0,N-1);
	cout<<ans<<endl;
	return 0;
}
