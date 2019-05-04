#include<stdio.h>
#include<stdlib.h>
typedef struct _list{
	int data;
	struct _list *next;
}Node;
int main(void){
	int N;
	int M;
	int numofdata = 0;
	int testcase;
	Node *head;
	Node *cur;
	Node *tmp;
	Node *before;
	scanf("%d",&testcase);
	while(testcase--){
	
	scanf("%d %d",&N,&M);
	numofdata=N;
	tmp = (Node *)malloc(sizeof(Node));
	tmp->next = NULL;
	head = tmp;
	cur = tmp;
	
	tmp->data = 1;
	tmp->next = NULL;
	
	for(int i=2;i<=N;i++){
		tmp = (Node *)malloc(sizeof(Node));
		tmp->data=i;
		cur->next=tmp;
		before=cur;
		cur=cur->next;
	}
	cur->next=head;
	before=cur;
	cur=cur->next;

	while(numofdata>2){	
		before->next = cur->next;
		free(cur);
		cur= before;
		for(int i=0;i<M;i++){			
			before = cur;
			cur=cur->next;			
		}
		
		numofdata--;
	}
	cur->data < cur->next->data? printf("%d %d\n",cur->data,cur->next->data) : 
	printf("%d %d\n",cur->next->data,cur->data);
	}
	return 0;
}
