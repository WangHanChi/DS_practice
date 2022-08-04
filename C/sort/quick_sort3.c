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

int partition(int[], int, int);
void quicksort(int[], int, int);

/*
之前說過軸的選擇是快速排序法的效率關鍵之一，在這邊的快速排序法的軸選擇方式更加快了快速排序法的效率，它是來自演算法名書 Introduction to Algorithms 之中。
先說明這個快速排序法的概念，它以最右邊的值s作比較的標準，將整個數列分為三個部份，一個是小於s的部份，一個是大於s的部份，一個是未處理的部份
在排序的過程中，i 與 j 都會不斷的往右進行比較與交換，最後數列會變為以下的狀態：
然後將s的值置於中間，接下來就以相同的步驟會左右兩邊的數列進行排序的動作


整個演算法的虛擬碼如下:
--------------------------------------------------------
QUICKSORT(A, p, r)
    if p < r
        then q <- PARTITION(A, p, r)
                 QUICKSORT(A, p, q-1)
                 QUICKSORT(A, q+1, r)
end QUICKSORT

PARTITION(A, p, r)
    x <- A[r]
    i <- p-1
    for j <- p to r-1
        do if A[j] <= x
                 then  i <- i+1
                         exchange A[i]<->A[j]
    exchange A[i+1]<->A[r]
    return i+1
end PARTITION
--------------------------------------------------------

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

int partition(int number[], int left, int right)
{
    int i, j, s;

    s = number[right]; //取最右邊的值
    i = left - 1;

    for (j = left; j < right; j++)
    {
        if (number[j] <= s)
        {
            i++;
            SWAP(number[i], number[j]);
        }
    }

    SWAP(number[i + 1], number[right]);
    return i + 1;
}

void quicksort(int number[], int left, int right)
{
    int q;

    if (left < right)
    {
        q = partition(number, left, right);
        quicksort(number, left, q - 1);
        quicksort(number, q + 1, right);
    }
}
