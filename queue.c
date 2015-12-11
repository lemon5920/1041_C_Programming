#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void create_student(int *number_boy, int *height_boy, int *number_girl, int *height_girl, int *boy_count, int *girl_count, int *n)
{
    int tmp_height, i;
    srand( time(NULL) + getpid() );

    for( i = 1 ; i <= *n ; i++ ) {
        int sex_judge = rand() % 2; // 亂數產生性別
        // 女生的身高是300~400，男生的身高是400~500
        if( sex_judge == 0 ) {
            tmp_height = ( rand() % 100 ) + 300;
            number_girl[ *girl_count ] = i;
            height_girl[ *girl_count ] = tmp_height;
            *girl_count = *girl_count + 1;
        } else {
            tmp_height = ( rand() % 100 ) + 400;
            number_boy[ *boy_count ] = i;
            height_boy[ *boy_count ] = tmp_height;
            *boy_count = *boy_count + 1;
        }
        // printf("%d\n", sex_judge);
        // printf("%d號\n", i);
    }
}

void print_student(int *number, int *height, int *count)
{
    int i;
    for(i = 0 ; i < *count ; i++){
        printf("No.%2d, Height: %d\n", number[i], height[i]);
    }
}

// 利用插入排序法排序身高。因為身高與座號是一組的，所以轉換時，座號也要一起做轉換。
void sort_student(int *number, int *height, int *count)
{
    int i, j, tmp_num, tmp_height;

    for (i = 1 ; i <= *count - 1; i++) {
        j = i;
 
        while ( j > 0 && height[j] < height[j-1]) {
            tmp_height  = height[j];
            tmp_num     = number[j];
            height[j]   = height[j-1];
            number[j]   = number[j-1];
            height[j-1] = tmp_height;
            number[j-1] = tmp_num;
 
            j--;
        }
    }
}

int main() {
    int n, i;
    scanf("%d", &n); // 全班幾個人

    int number_boy [n]; // 男生座號
    int height_boy [n]; // 男生身高
    int number_girl [n]; //女生座號
    int height_girl [n]; // 女生身高    
    int boy_count = 0;
    int girl_count = 0;

    create_student(number_boy, height_boy, number_girl, height_girl, &boy_count, &girl_count, &n);

    printf("男生%d人\n", boy_count);
    printf("女生%d人\n", girl_count);
    
    // 印出未排序的男女生。
    // printf("\nboy\n");
    // print_student(number_boy, height_boy, &boy_count);

    // printf("\ngirl\n");
    // print_student(number_girl, height_girl, &girl_count);

    // 排序，並印出。
    sort_student(number_boy, height_boy, &boy_count);
    sort_student(number_girl, height_girl, &girl_count);

    printf("\n----- Boy -----\n");
    print_student(number_boy, height_boy, &boy_count);
    
    printf("\n----- Girl -----\n");
    print_student(number_girl, height_girl, &girl_count);
}
