#include<iostream>
using namespace std;
int max(int a,int b,int c) {
	if(a>=b && a>=c)
		return a;
	else if(b>=a && b>=c)
		return b;
	else return c;
}
int len;
int *h;
int find(int start,int end);
int main(){
	int testcase;
	int sol;
	cin>>testcase;
	while(testcase--){
		cin>>len;
		h = new int[len];
		for(int i = 0 ; i < len ; i++)
			cin>>h[i];
		sol = find(0,len-1);
		cout<<sol<<endl;
		delete h;
	}
	return 0;
}
int find(int start,int end){
	int num = 4;
	if(start>end){
		return 0;
	}
	else if(start==end){
		return h[start];
	}
	int middle = (start+end)/2;
	int l_max = find(start,middle);
	int r_max = find(middle+1,end);
	int m_max = 0;
	int least = h[middle] >= h[middle+1] ? h[middle+1] : h[middle];

	int sol = least * 2;
	
	int l_idx,r_idx;
	
	while(least){
		m_max = 0;
		if(least * (end-start+1) <= sol)
			break;
		r_idx = middle+1;
		l_idx = middle;
		
		while(least<=h[r_idx] && r_idx <=end){
			m_max += least;
			r_idx++;
		}
		while(least<=h[l_idx] && l_idx >=start){
			m_max += least;
			l_idx--;
		}
		if(sol < m_max)
			sol = m_max;
		
		least--;
	}
	
	return max(l_max,r_max,sol);
}
