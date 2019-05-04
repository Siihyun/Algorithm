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
	Node *head;
	Node *cur;
	Node *tmp;
	Node *before;

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
	int cnt=0;
	/*while(cnt<20){
		printf("%d ",before->data);
		before=before->next;
		cnt++;
	} */
	printf("<");
	while(numofdata>0){
		for(int i=0;i<M;i++){
			before = cur;
			cur=cur->next;			
		}
		printf("%d",cur->data);
		before->next = cur->next;
		free(cur);
		cur= before;
		
		numofdata--;
		if(numofdata>0)
			printf(", ");
	}
	printf(">\n");
}
