#include <stdio.h>
int main() {
    int n, sum = 0, i, num, power; // n: 初始數, sum: n 次方總和, num: 除數
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        sum += i * i;
    printf("Sum: %d\n", sum);
    for (num = 2; sum != 1; num++) {
        power = 0;
        while (sum % num == 0) { // 將 num 除乾淨
            sum /= num;
            power++;
        }
        if (power != 0)
            printf("(%d ^ %d) ", num, power);
    }
    return 0;
}
