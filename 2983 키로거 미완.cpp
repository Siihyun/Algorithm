
int WhoIsPrecede(int d1, int d2)
{
	if(d1 < d2)
		return 0;    // d1�� ���� ������ �ռ���.
	else
		return 1;    // d2�� ���� ������ �ռ��ų� ����.
}
int main(void){
	int *c,int *d;
	int x,int y;
	int *a,int *b;
	int N; int K;
	char *arr;
	scanf("%d %d",&N,&K);
	arr = (char *)malloc(sizeof(char)*K);
	List list;
	ListInit(&list);
	SetSortRule(&list, WhoIsPrecede);
	for(int i=0;i<k;i++)
		scanf("%c",&arr[i]);
	for(int i=0;i<N;i++){
		scanf("%d %d",&x,&y);
		SInsert(&list,x,y);
	}
	LFirst(&list,&a,&b);
	while(k--){
		
		if(LFirst(&list, &c,&d))
		{
			
			while(LNext(&list, &data)) 
				printf("%d ", data);
		}
	}	
	

int main(void)
{
	// List�� ���� �� �ʱ�ȭ  ////////////
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);

	// 5���� ������ ����  ///////////////
	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);

	// ����� �������� ��ü ��� ////////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data)) 
			printf("%d ", data);
	}
	printf("\n\n");

	// ���� 22�� �˻��Ͽ� ��� ���� ////////////
	if(LFirst(&list, &data))
	{
		if(data == 22)
			LRemove(&list);
		
		while(LNext(&list, &data))
		{
			if(data == 22)
				LRemove(&list);
		}
	}

	// ���� �� ����� ������ ��ü ��� ////////////
	printf("���� �������� ��: %d \n", LCount(&list));

	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}
}
