#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct coin {
    int n;
    int * value;
    double * weight;
    int * available; // 每種硬幣的個數 
    int * number; // 現在我選了幾個硬幣
    int * maxNumber; // 這個過程中，目前最大的組合
    double max; // 最大重量
};

void init (struct coin * x, int n, int *v, double *w, int *a) {
    int i;
    x->n = n;
    x->value = (int *)malloc(sizeof(int) * n);
    x->weight = (double *)malloc(sizeof(double) * n);
    x->available = (int *)malloc(sizeof(int) * n);
    x->number = (int *)malloc(sizeof(int) * n);
    x->maxNumber = (int *)malloc(sizeof(int) * n);
    x->max = 0;

    for(i = 0; i< n ; i++) {
        x->value[i] = v[i];
        x->weight[i] = w[i];
        x->available[i] = a[i];
        x->number[i] = 0;
    }
}

void findSolution( struct coin * x, int target, int from ) {
    int i; 
    if( x->n <= from ) {
        if( target == 0 ) { // found a solution
            // check if this solution has max weight
            double w = 0;
            for( i  = 0 ; i < x->n ; i++ ) {
                w += x->weight[i] * x->number[i];
            }
            if( w > x->max ) {
                x->max = w;
                for( i = 0 ; i < x->n ; i++ ){
                    x->maxNumber[i] = x->number[i];
                }
            }
        }
        return;
    }

    // choose coin from "from" position
    for( i = 0 ; i <= x->available[from] ; i++ ){
        // choose i coin form "from" position
        x->number[from] = i;
        findSolution(x, target - x->value[from] * i, from + 1);
    }
}

int main() {
    double w[] = {10, 7.5, 4.4, 3.8};
    int v[] = {50, 10, 5, 1};
    int a[4];
    int target, i;
    struct coin x;
    scanf("%d", &target);
    for(i = 0 ; i < 4 ; i++) {
        scanf("%d", a+i);
    }
    init(&x, 4, v, w, a);
    findSolution(&x, target, 0);
    printf("%lf %d %d %d %d\n", x.max, x.maxNumber[0], x.maxNumber[1], x.maxNumber[2], x.maxNumber[3]);
}
