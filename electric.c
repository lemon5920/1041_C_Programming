#include<stdio.h>

int main()
{
    float month, kwh, money = 0; // 月份, 度數, 電費
    int i;
    printf("輸入月份、用電度數：");
    scanf("%f %f", &month, &kwh);
    float price[6];
    float interval[] = {120, 210, 170, 200, 300, 9999999}; // 每一段電費的間隔
    float summer[] = {2.1, 3.02, 4.39, 5.44, 6.16, 6.71};
    float winter[] = {2.1, 2.68, 3.61, 4.48, 5.03, 5.28};
    for (int i = 0; i < 6; i++)
    {
        if(month >= 6 && month <= 9) // 夏月
            price[i] = summer[i];
        else
            price[i] = winter[i];
    }
    // 判斷"目前"瓦數是否在區間內。
    // 超出區間表示還要再繼續算money，扣掉該區間最大瓦數後continue。
    // 包含在該區間內則算完money後break。
    for (int i = 0; i < 6; i++)
    {
        if(kwh <= interval[i]){
            money = money + (kwh * price[i]);
            break;
        }else{
            money += (interval[i] * price[i]);
            kwh -= interval[i];
        }
    }
    printf("價錢為：%f\n\n", money);
    return 0;
}
