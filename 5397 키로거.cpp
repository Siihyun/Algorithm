#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char Data;
typedef struct _node{
	Data data;
	struct _node * next;
	struct _node * prev;
}Node;

typedef struct _dbDLinkedList{
	Node *head;
	Node *tail;
	Node *cur;
	int numOfData;
}DBDLinkedList;

typedef DBDLinkedList List;

void ListInit(List *plist){
	plist->head = (Node *)malloc(sizeof(Node));
	plist->tail = (Node *)malloc(sizeof(Node));
	
	plist->head->prev = NULL;
	plist->head->next = plist->tail;

	plist->tail->next = NULL;
	plist->tail->prev = plist->head;
	plist->cur=plist->head;
	plist->numOfData = 0;
}
void LInsert(List *plist,Data data){
	
	Node *tmp;
	tmp = (Node *)malloc(sizeof(Node));
	tmp->data = data;
	tmp->prev = plist->tail->prev;
	
	plist->tail->prev->next = tmp;
	tmp->next = plist->tail;
	plist->tail->prev = tmp;

	plist->cur = tmp;
	
	plist->numOfData++;
	
	
}
void CInsert(List *plist,Data data){
	Node *tmp;
	tmp = (Node *)malloc(sizeof(Node));
	tmp->data = data;
	tmp->prev = plist->cur;
	tmp->next = plist->cur->next;
	
	tmp->next->prev=tmp;
	plist->cur->next=tmp;

	plist->numOfData++;
	plist->cur=tmp;
}
int Lfirst(List *plist,Data *pdata){
	if(plist->numOfData == 0){
		return 0;
	}
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;
	return 1;
}
int LNext(List *plist,Data *pdata){
	if(plist->cur->next==plist->tail)
		return 0;
	plist->cur=plist->cur->next;
	*pdata = plist->cur->data;
	
	return 1;
}
int Lleft(List *plist){
	if(plist->cur==plist->head)
		return 0;
	plist->cur = plist->cur->prev;
	return 0;
}
Data LRemove(List *plist){
	if(plist->cur ==plist->head || plist->cur == plist->tail)
		return 0;
	
	Data Rdata;
	Node *rpos = plist->cur;
	Rdata = plist->cur->data;
	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;
	plist->cur = plist->cur->prev;
	free(rpos);
	plist->numOfData--;
	
	return Rdata;
}
int LCount(List *plist){
	return plist->numOfData;
}
int main(void){
	List list;
	ListInit(&list);
	Data a;
	int num; char command;
	char plus;
	char arr[1000001];
	scanf("%d",&num);
	int len;
	
	
	while(num--){
		ListInit(&list);
	
		scanf("%s",arr);
		getchar();
        len = strlen(arr);
		for(int i=0;i<len;i++){
		command=arr[i];
		if(command == '<')
			Lleft(&list); 
		else if(command =='>')
			LNext(&list,&a);
		else if(command == '-')
			LRemove(&list);
		else{
			CInsert(&list,command);
	
		}
	}
	if(Lfirst(&list,&a)){
		printf("%c",a);
		while(LNext(&list,&a)){
			printf("%c",a);
		}
	}
	printf("\n");
}

	return 0;
}


