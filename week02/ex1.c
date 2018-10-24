#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int val1 = INT_MAX;
	float val2 = FLT_MAX;
	double val3 = DBL_MAX;
	printf("Size of int = %d and value = %d\n", (int)sizeof(val1), val1);
	printf("Size of float = %d and value = %f\n",(int) sizeof(val2), val2);
	printf("Size of double = %d and value = %f\n", (int)sizeof(val3), val3);
	return 0;
}
