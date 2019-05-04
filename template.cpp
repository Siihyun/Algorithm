#include<iostream>
using namespace std;
template<typename T>
void Copy(T* arr1, T* arr2, int num){
	for(int i=0;i<num;i++){
		arr1[i]=arr2[i];
	}
}
template<typename T1,typename T2>
struct Pair{
	T1 t1;
	T2 t2;
	Pair(const T1 &t1, const T2 &t2) : t1(t1) , t2(t2){
	}
	void print(){
		cout<<t1<<','<<t2<<endl;
	}
};
template<typename T>
class Stack{
	T* arr;
	int top = -1;
	public:
	Stack(){
		arr = new T(100);
	}
	void Push(T num){
		arr[++top] = num;
	}
	T pop(){
		return arr[top--];
	}
};
int main(){
	float arr1[5] = {10.4,20,30,40,50};
	float arr2[5];
	
	Pair <int,char> pair1(520,'a');
	//cout<<pair1.t1<<','<<pair1.t2<<endl;
	pair1.print();
	Copy(arr2,arr1,5);
	//for(int i = 0;i<5;i++)
	//	cout<<arr2[i]<<' ';
	Stack<int> st;
	
	st.Push(10);
	st.Push(20);
	st.Push(30);
	
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	return 0;
}

