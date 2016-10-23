#include <stdio.h>
#include <limits.h>
#include <math.h>
int isPrime(int x) {
    int i;
    if (x == 1) {
        return 0;
    } else if (x == 2) {
        return 1;
    }
    for (i = 2; i <= (int)sqrt(x); i++) {
        if(x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, x, i;
    int min = INT_MAX;
    int max = INT_MIN;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        if (isPrime(x) == 1) {
            if (x > max) {
                max = x;
            }
            if (x < min) {
                min = x;
            }
        }
    }

    // 避免沒有任何質數
    if (min == INT_MAX) {
        printf("min: null\n");
        printf("max: null\n");
    } else {
        printf("min: %d\n", min);
        printf("max: %d\n", max);
    }

    return 0;
}
