#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Input length of string: ");
    scanf("%d", &n);
    char str[n];
    printf("Input string: ");
    scanf("%s", str);
    int i;
    for (i=(int)strlen(str)-1;i>=0;i--) {
        printf("%c", str[i]);
    }
    return 0;
}
