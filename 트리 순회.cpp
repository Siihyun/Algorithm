#include <iostream>
#include <fstream> 
#include <vector> 
using namespace std; 
vector<int> preorder;
vector<int> inorder; 
void printPostorder(const int, int&, int, int); 
int main(){
	int C; 
	scanf("%d",&C);
	for (int i = 1; i <= C; i++){ 
		int N; 
		scanf("%d",&N); 
		preorder = vector<int>(N, 0);	//초기화
   		inorder = vector<int>(N, 0); 
   		for (int j = 0; j < N; j++) 
   			cin >> preorder[j]; 
   		for (int j = 0; j < N; j++) 
   			cin >> inorder[j]; 
    int index = 0;
	printPostorder(N, index, 0, N - 1);
	cout << endl;
	} 
	return 0; 
}
void printPostorder(const int n, int& root_index, int left, int right){
	if (left > right){
		--root_index; 
		return; 
	} 
	if (root_index >= n) 
	 	return;
    int index = left; 
	for (; index <= right; index++)
		if (preorder[root_index] == inorder[index])
		  	break;
	printPostorder(n, ++root_index, left, index - 1);	//왼쪽 출력
	printPostorder(n, ++root_index, index + 1, right);	//오른쪽 출력 
	
	cout << inorder[index] << " "; }


