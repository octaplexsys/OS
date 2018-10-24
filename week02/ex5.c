#include <stdio.h>
#include <string.h>
#include <math.h>
#define min(x, y) (x<y ? x : y)

void func0(int n) {
    int i, j;
    for(i=0;i<n;i++) {
        for(j=0;j<n-i-1;j++) {
            printf(" ");
        }
        for(j=0;j<i;j++) {
            printf("*");
        }
        printf("*");
        for(j=0;j<i;j++) {
            printf("*");
        }
        for(j=0;j<n-i-1;j++) {
            printf(" ");
        }
        printf("\n");
    }
}

void func1(int n) {
    int i, j;
    for(i=0;i<n;i++) {
        for(j=0;j<i+1;j++) {
            printf("*");
        }
        for(j=0;j<n-i;j++) {
            printf(" ");
        }
        printf("\n");
    }
}

void func2(int n) {
    int i, j;
    for(i=0;i<n;i++) {
        for(j=0;j<min(i+1,n-i);j++) {
            printf("*");
        }
        for(j=0;j<n-i;j++) {
            printf(" ");
        }
        printf("\n");
    }
}

void func3(int n) {
    int i, j;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int a, n;
    printf("Which figure to display? Input number from 0 to 3: ");
    scanf("%d", &a);
    printf("Input size of the figure: ");
    scanf("%d", &n);
    switch (a) {
        case 0:
            func0(n);
            break;
        case 1:
            func1(n);
            break;
        case 2:
            func2(n);
            break;
        case 3:
            func3(n);
            break;
        default:
            printf("WRONG choice of figure type.");
    }
    return 0;
}