#include <stdio.h>
int main() {
    int n, i, max = 0, tmp;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if(tmp > max) {
            max = tmp;
        }
    }
    printf("%d\n", max);
    return 0;
}