#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define SWAP(x, y) \
    {              \
        int t;     \
        t = x;     \
        x = y;     \
        y = t;     \
    }

void quicksort(int[], int, int);

/*
這邊所介紹的快速演算如下：
將最左邊的數設定為軸，並記錄其值為 s

廻圈處理：
    1.令索引 i 從數列左方往右方找，直到找到大於 s 的數
    2.令索引 j 從數列左右方往左方找，直到找到小於 s 的數
    3.如果 i >= j，則離開迴圈
    4.如果 i < j，則交換索引i與j兩處的值
    5.將左側的軸與 j 進行交換
    6.對軸左邊進行遞迴
    7.對軸右邊進行遞迴

透過以下演算法，則軸左邊的值都會小於s，軸右邊的值都會大於s，如此再對軸左右兩邊進行遞迴，就可以對完成排序的目的，例如下面的實例，*表示要交換的數，[]表示軸：
    [41]　24　76*　11　45　64　21　69　19　36*
    [41]　24　36　11　45*　64　21　69　19*　76
    [41]　24　36　11　19　64*　21*　69　45　76
    [41]　24　36　11　19　21　64　69　45　76
    21　24　36　11　19　[41]　64　69　45　76

在上面的例子中，41左邊的值都比它小，而右邊的值都比它大，如此左右再進行遞迴至排序完成。
*/
int main(void)
{
    int number[MAX] = {0};
    int i, num;

    srand(time(NULL));

    printf("排序前：");
    for (i = 0; i < MAX; i++)
    {
        number[i] = rand() % 100;
        printf("%d ", number[i]);
    }

    quicksort(number, 0, MAX - 1);

    printf("\n排序後:");
    for (i = 0; i < MAX; i++)
        printf("%d ", number[i]);

    printf("\n");

    return 0;
}

void quicksort(int number[], int left, int right)
{
    int i, j, s;

    if (left < right)
    {
        s = number[left];
        i = left;
        j = right + 1;

        while (1)
        {

            // 向右找
            while (i + 1 < MAX && number[++i] < s)
                ;
            // 向左找
            while (j - 1 > -1 && number[--j] > s)
                ;
            if (i >= j)
                break;
            SWAP(number[i], number[j]);
        }

        number[left] = number[j];
        number[j] = s;

        quicksort(number, left, j - 1);  // 對左邊進行遞迴
        quicksort(number, j + 1, right); // 對右邊進行遞迴
    }
}