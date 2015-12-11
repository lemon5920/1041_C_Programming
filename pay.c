#include<stdio.h>

int main() {
    int i, j, m ,n;

    int price; // 買東西的價格
    scanf("%d", &price);

    int quantity [4]; // 硬幣數量
    for(i = 0 ; i < 4 ; i++) {
        scanf("%d", &quantity[i]);
    }
    
    // int times = 0; // 累計現有的硬幣，有多少種付款方式？
    // int same_times = 0; // 累計現有硬幣，金額符合價格的次數。
   
    // 各種硬幣在最重的狀況下，每種硬幣的量
    // float coin_max_weight = 0;
    int coin_max_qua = 0;
    int coin_50;
    int coin_10;
    int coin_5;
    int coin_1;

    for(i = 0 ; i <= quantity[0] ; i++) {
        for(j = 0 ; j <= quantity[1] ; j++) {
            for(m = 0 ; m <= quantity[2] ; m++) {
                for(n = 0 ; n <= quantity[3] ; n++) {
                    int money = i * 50 + j * 10 + m * 5 + n * 1; // 當前金額

                    // printf("$50 %d個，$10 %d個，$5 %d個，$1 %d個。共 %d 元\n", i, j, m, n, money);
                    // times++;

                    if(money == price) {
                        // float tmp_weight = 10*i + 7.5*j + 4.4*m + 3.8*n; // 當前硬幣重量
                        int tmp_coin_qua = i + j + m + n;
                        // printf("重量為：%f\n\n", tmp_weight); // 價格符合才印出目前重量
                        // same_times++;


                        // if(tmp_weight > coin_max_weight) { // 當最重的組合出現，儲存
                        if(tmp_coin_qua > coin_max_qua) {
                            //coin_max_weight = tmp_weight;
                            coin_max_qua = tmp_coin_qua;
                            coin_50 = i;
                            coin_10 = j;
                            coin_5 = m;
                            coin_1 = n;
                        }
                    }
                }
            }
        }
    }

    // printf("所有硬幣共有%d種付款方式\n", times);
    // printf("符合$%d 共有%d種付款方式\n", price, same_times);
    //if( coin_max_weight != 0){
    if(coin_max_qua != 0) {
        printf("應付：$50: %d個, $10: %d個, $5: %d個, $1: %d個\n", coin_50, coin_10, coin_5, coin_1);
        printf("重量：%fg\n", 10*coin_50 + 7.5*coin_10 + 4.4*coin_5 + 3.8*coin_1);
    }else{
        printf("沒有錢可以付。\n");
    }
}
