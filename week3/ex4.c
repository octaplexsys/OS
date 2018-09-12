#include <stdio.h>

void quick_sort(int *a, int *b);
int* partition(int *a, int *b);
void swap(int *a, int *b);

int main() {
    int n;
    printf("Input amount of numbers:\n");
    scanf("%d", &n);
    int a[n];
    int i;
    for(i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }
    quick_sort(a, a+n);
    for(i=0;i<n;i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* partition(int *a, int *b) {
    int *i=a;
    int* pivot = (b-1);
    for(;a<b-1;a++) {
        if(*a < *pivot) {
            swap(i, a);
            i++;
        }
    }
    swap(i, pivot);
    return i;
}

void quick_sort(int *a, int *b) {
    if (a >= b) return;
    int* q = partition(a, b);
    quick_sort(a, q);
    quick_sort(q+1, b);
}