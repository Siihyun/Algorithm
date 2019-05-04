#include<stdio.h>
#include<stdlib.h>
void quickSort(int *arr1,int *arr2, int left, int right) {
      int i = left, j = right;
      int pivot = arr1[(left + right) / 2];
      int temp;
      do {
        while (arr1[i] > pivot) 
            i++;
        while (arr1[j] < pivot)
            j--;
        if (i<= j) {
            temp = arr1[i];
            arr1[i] = arr1[j];
            arr1[j] = temp;
            temp = arr2[i];
            arr2[i] = arr2[j];
            arr2[j] = temp;
            i++;
            j--;
        }
	} while (i<= j);

    /* recursion */
    if (left < j)
        quickSort(arr1,arr2, left, j);

    if (i < right)
        quickSort(arr1,arr2, i, right);
}


int main(void){
	int testcase;
	int num; int *eatTime; int *heatTime;
	scanf("%d",&testcase);
	int time=0; int max=0;
	while(testcase--){
		scanf("%d",&num);
		eatTime = (int *)malloc(sizeof(int)*num);
		heatTime = (int *)malloc(sizeof(int)*num);
		
		for(int i=0;i<num;i++)
			scanf("%d",&heatTime[i]);
		for(int i=0;i<num;i++)
			scanf("%d",&eatTime[i]);
		quickSort(eatTime,heatTime,0,num-1);
		time=heatTime[0];
		max=0;

		for(int i=1;i<num;i++){
			time+=heatTime[i];
			for(int j=0;j<i;j++)
				eatTime[j]-=heatTime[i];
			}
		for(int i=0;i<num;i++){
			if(max<eatTime[i])
				max=eatTime[i];
		}		
		free(eatTime);
		free(heatTime);
	printf("%d\n",time+max);
	}
	return 0;
}
