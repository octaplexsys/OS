#include <stdio.h>

void bubble_sort(int *a, int n);
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
    bubble_sort(a, n);
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

void bubble_sort(int *a, int n) {
    int i,j;
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-i-1;j++) {
            if(a[j] > a[j+1]) {
                swap(&a[j], &a[j+1]);
            }
        }
    }
}