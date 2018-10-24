#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i;
	printf("Input number N: ");
	scanf("%d", &n);
	int *ptr=malloc(n*sizeof(int));
	for(i=0;i<n;i++) {
		*(ptr+i)=i;
	}
	printf("The array:\n");
	for(i=0;i<n;i++) {
		printf("%d\n", *(ptr+i));
	}
	free(ptr);
	return 0;
}
