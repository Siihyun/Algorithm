#include<stdio.h>
#include<stdlib.h> 
#define TRUE	1
#define FALSE	0
#define HEAP_LEN	100

typedef char HData;
typedef int Priority;

typedef struct _heapElem
{
	int pr;// ���� �������� ���� �켱����
} HeapElem;

typedef struct _heap
{
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
} Heap;




void HeapInit(Heap * ph)
{
	ph->numOfData = 0;
}

int HIsEmpty(Heap * ph)
{
	if(ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) 
{ 
	return idx/2; 
}

int GetLChildIDX(int idx) 
{ 
	return idx*2; 
}

int GetRChildIDX(int idx) 
{ 
	return GetLChildIDX(idx)+1; 
}

int GetHiPriChildIDX(Heap * ph, int idx)
{
	if(GetLChildIDX(idx) > ph->numOfData)    // �ڽ� ��尡 ���ٸ�
		return 0;

	else if(GetLChildIDX(idx) == ph->numOfData)    // ���� �ڽ� ��尡 ������ �����
		return GetLChildIDX(idx);

	else   // ���� �ڽ� ���� ������ �ڽ� ����� �켱������ ��
	{
		if(ph->heapArr[GetLChildIDX(idx)].pr 
						> ph->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap * ph, int pr)
{
	
	int idx = ph->numOfData+1;
	int nelem = pr;

	while(idx != 1)
	{
		if(pr < (ph->heapArr[GetParentIDX(idx)].pr))
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}
	
	ph->heapArr[idx].pr = nelem;
	ph->numOfData += 1;
}

int HDelete(Heap * ph)
{
	int retData = (ph->heapArr[1]).pr;    // ������ ������ �ӽ� ����
	HeapElem lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;    // ��Ʈ ����� Index
	int childIdx;

	while(childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		if(lastElem.pr <= ph->heapArr[childIdx].pr)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}
int main(void)
{
	int cost;
	int testcase;
	int n; int a=0; int b=0;
	int num;
	Heap *heap;
	int i=0;
	scanf("%d",&testcase);
	heap = (Heap*)malloc(sizeof(Heap)*testcase);
	while(testcase--){
		cost = 0;
		scanf("%d",&num);
		HeapInit(&heap[i]);
		for(int j=0;j<num;j++){				
			scanf("%d",&n);
			HInsert(&heap[i],n);
			}
		
			for(int j=0;j<num-1;j++){
			
				a=HDelete(&heap[i]);
				cost+=a;
				b=HDelete(&heap[i]);
				cost+=b;
				HInsert(&heap[i],a+b);
			}
			printf("%d\n",cost);
			i++;
		}
	
	return 0;
}

