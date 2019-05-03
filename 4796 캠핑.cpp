#include<stdio.h>
int main(){
	int L,P,V;
	int k = 1;
	while(1){
		scanf("%d %d %d",&L,&P,&V);
		if((L==0 && P == 0) && V ==0) 
			break;
		int num = V/P;
		int num2 = V%P;
		num*=L;
		if(num2>=L)
			num+=L;
		else{
			num+=num2;
		}
		printf("Case %d: %d\n",k++,num);
	}	
	return 0;
}
