/*
*   輸入值，並印出
*   舉例：整數int、浮點數float
*/

#include<stdio.h>
// 函式庫：https://zh.wikipedia.org/wiki/Stdio.h

void main()
{
    int i;
    float f;
    
    scanf("%d", &i);
    scanf("%f", &f);

    printf("i: %d\n", i);
    printf("f: %f\n", f);
}
