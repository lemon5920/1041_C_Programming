#include<stdio.h>
void print(int n, char c) {
    int i;
    for (i = 0 ; i < n ; i++) {
        printf("%c", c);
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    for( i = 1 ; i <= n ; i++) {
        // body
        print(3 * (n - i), ' ');
        print(3 * i, '*');
        print(3 * (i - 1), '*');
        print(3 * (n - i), ' ');

        // tail
        print(n - i, ' ');
        print(i - 1, '*');
        printf("\n");
    }

    for( i = n - 1 ; i > 0 ; i--) {
        // body
        print(3 * (n - i), ' ');
        print(3 * i, '*');
        print(3 * (i - 1), '*');
        print(3 * (n - i), ' ');

        // tail
        print(n - i, ' ');
        print(i - 1, '*');
        printf("\n");
    }
    
}
