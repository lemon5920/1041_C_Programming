#include <stdio.h> 
#include <limits.h> // 取得型態邊界值用 lib
#include <math.h> // 數學運算用 lib
int isPrime(int x) {
    /* 
     * 取得一個數值後，去算出是否為質數
     * 是：return 1, 否：return 0.
     */
    int i;
    // 例外狀況預先判斷
    if (x == 1) {
        return 0;
    } else if (x == 2) {
        return 1;
    }
    // 例外狀況外之數值判斷。演算法：判斷的數值不超過根號 `x`
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
