#include<stdio.h>
int main(void){
	char a;
	int i=0; 
	a = getchar();
	while(1){
		if(a==-1)
			break;
		putchar(a);
		a = getchar();

	}
	return 0;
}
