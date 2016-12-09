#include <stdio.h>
void sort(int * array, int num) {
    int swap, i, j;
    for (i = 0 ; i < ( num - 1 ); i++) {
        for (j = 0 ; j < num - i - 1; j++) {
            if (array[j] > array[j+1]) { /* For decreasing order use < */
                swap = array[j];
                array[j] = array[j+1];
                array[j+1] = swap;
            }
        }
    }
}

int main() {
    int num, i;
    scanf("%d", &num);
    int arr[num];
    for (i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, num);

    int current_num = -1, current_count = 0, count_max = 0, index = 0;
    // current_num: 當前數字，作為判斷是否改變的依據。
    // current_count: 當前數字出現次數。
    // count_max: 目前眾數出現的次數。
    // index: 眾數數量。
    int answer[num / 2]; // 存放眾數

    // i <= num 目的是最後一個數字也能夠被判斷到。
    // 理論上會出現溢位，但 pointer 的關係，因此不會出現錯誤。
    for (i = 0; i <= num; i++) {
        if (arr[i] == current_num) {
            // 當前數字與前數字相同時，當前次數累加。
            current_count++;
        } else {
            // 當前數字與前數字不同時，判斷「當前次數」比「眾數數量」多或相等。
            // 多：「當前數字」為目前唯一眾數，更新眾數次數，眾數數量歸 1。
            // 相等：「當前數字」加入眾數陣列，眾數數量 +1。
            // 判斷完，更新當前數字、次數。
            if (current_count > count_max) {
                answer[0] = current_num;
                count_max = current_count;
                index = 1;
            } else if (current_count == count_max) {
                answer[index] = current_num;
                index++;
            }
            current_num = arr[i];
            current_count = 1;
        }
    }

    printf("眾數：\n");
    for (i = 0; i < index; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}
