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

    int n, i;
    //printf("Type：");
    scanf("%d", &n);
    double w[n];
    int v[n];
    int a[n];
    
    //printf("Denomination：");
    for (i = 0 ; i < n ; i++) {
        scanf("%d", v + i);
    }

    //printf("Weight：");
    for (i = 0 ; i < n ; i++) {
        scanf("%lf", w + i);
    }

    int target;
    struct coin x;

    //printf("Quantity：");
    for(i = 0 ; i < n ; i++) {
        scanf("%d", a+i);
    }
    //printf("Price：");
    scanf("%d", &target);

    init(&x, n, v, w, a);
    findSolution(&x, target, 0);

    printf("%lf\n", x.max);
    //printf("Max weight：%lf\n", x.max);
    //printf("Result quantity：");
    for ( i = 0 ; i < n ; i++ ) {
        printf("%d ", x.maxNumber[i]);
    }
    printf("\n");
}
