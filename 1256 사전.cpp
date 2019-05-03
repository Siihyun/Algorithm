#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int *A;
long long get_answer(int left,int right){
	long long start;
	long long left_sum,right_sum,mid_sum,mid,Min,Max=0;
	mid = (left+right)/2;
	printf("left : %d mid : %d right : %d\n",left,mid,right);
	if(left==right){
	//	printf("return %d\n",A[left]*A[left]);
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
	
	long long test = 0;
	for(int i = mid; i >= left ; i--){
	//	printf("i : %d\n",i);
		if(i==mid){
			mid_sum = A[mid]+A[mid+1];
			Min = min(A[mid],A[mid+1]);
			Max = mid_sum * Min;
	//		printf("max : %d\n",Max);
			test = mid_sum;
		}
		else{
			if(A[i] >= Min){
				mid_sum+=A[i];
				continue;
			}
			else{
				Min = A[i];
				mid_sum+=A[i];
	//			printf("min : %d mid_sum : %d\n",Min,mid_sum);
				if(Max < Min*mid_sum)
					Max = mid_sum*Min;
			}
		}
		for(int j =mid+2; j <=right ; j++){
			if(A[j]<Min){
				Min = A[j];
			}
			mid_sum +=A[j];
			if(mid_sum * Min >Max)
				Max = mid_sum * Min;
		}
		mid_sum = test;
	}
	if(Max < mid_sum * Min)
		Max = mid_sum * Min;
	long long tmp_sum = max(left_sum, right_sum);
	printf("left : %d, right : %d\nleft sum : %d , right_sum = %d, mid_sum = %d\n\n",left,right,left_sum,right_sum,Max);
	return max(Max,tmp_sum);
}
int main(){
	int N;
	cin>>N;
	A = new int[N];
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&A[i]);
	}
	long long ans = get_answer(0,N-1);
	cout<<ans<<endl;
	return 0;
}
