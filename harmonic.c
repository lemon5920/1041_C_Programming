#include <stdio.h>
int main() {
    int n;
    float sum = 0;
    scanf("%d", &n);
    for(float i = 1; i <= n; i++) {
        sum += (1/i);
    }
    printf("%f\n", sum);
    return 0;
}