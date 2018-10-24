#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, m;
    printf("Input two numbers: ");
    scanf("%d%d", &n, &m);
    printf("Before swap: %d %d\n", n, m);
    swap(&n, &m);
    printf("After swap: %d %d\n", n, m);
    printf("After swap: %d %d\n", n, m);
    return 0;
}