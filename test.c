#include<stdio.h>
int main() {
	unsigned char data[4];
	data[0] = 1;
	data[1] = 2;
	data[2] = 5;
	data[3] = 4;
	data[0] += 150;
	puts("==================int==================");
	for (int i = 0; i < 4; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
	puts("==============char===================");
	for (int i = 0; i < 4; i++) {
		printf("%c ", data[i]);
	}
}