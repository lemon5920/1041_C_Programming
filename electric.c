#include<stdio.h>

void main()
{
    float month; // 月份
    float kwh; // 度數
    float money = 0;    

    printf("輸入月份、用電度數：");
    scanf("%f %f", &month, &kwh);
    float interval[] = {120, 210, 170, 200, 300, 200000000}; // 每一段電費的間隔
    float price[6]; // 邏輯來說，在if內宣告就好，但是編譯又不給過，所以這裡先宣告一個假的
    int i;
    
    if(month >= 6 && month <= 9){ // 夏月
        float price[] = {2.1, 3.02, 4.39, 5.44, 6.16, 6.71}; // 夏月價格陣列
    }else{ // 非夏月
        float price[] = {2.1, 2.68, 3.61, 4.48, 5.03, 5.28}; // 非夏月價格陣列
    }
    // 判斷"目前"瓦數是否在區間內。
    // 超出區間表示還要再繼續算money，扣掉該區間最大瓦數後continue。
    // 包含在該區間內則算完money後break。
    if(kwh <= interval[i]){
        money = money + (kwh * price[i]);
        break;
    }else{
        money = money + (interval[i] * price[i]);
        kwh = kwh - interval[i];
    }
    printf("價錢為：%f\n\n", money);
}
