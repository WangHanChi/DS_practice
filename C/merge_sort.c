#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX1 10
#define MAX2 10
#define SWAP(x, y) \
    {              \
        int t;     \
        t = x;     \
        x = y;     \
        y = t;     \
    }

int partition(int[], int, int);
void quicksort(int[], int, int);
void mergesort(int[], int, int[], int, int[]);

/*
說明:
之前所介紹的排序法都是在同一個陣列中的排序，考慮今日有兩筆或兩筆以上的資料，它可能是不同陣列中的資料，或是不同檔案中的資料，如何為它們進行排序？

解法:
可以使用合併排序法，合併排序法基本是將兩筆已排序的資料合併並進行排序，如果所讀入的資料尚未排序，
可以先利用其它的排序方式來處理這兩筆資料，然後再將排序好的這兩筆資料合併。
有人問道，如果兩筆資料本身就無排序順序，何不將所有的資料讀入，再一次進行排序？
排序的精神是儘量利用資料已排序的部份，來加快排序的效率，小筆資料的 排序較為快速，
如果小筆資料排序完成之後，再合併處理時，因為兩筆資料都有排序了，所有在合併排序時會比單純讀入所有的資料再一次排序來的有效率。
那麼可不可以直接使用合併排序法本身來處理整個排序的動作？而不動用到其它的排序方式？答案是肯定的，
只要將所有的數字不斷的分為兩個等分，直到最後剩一個數字為止，然後再反過來不斷的合併，
不過基本上分割又會花去額外的時間，不如使用其它較好的排序法來排序小筆資料，再使用合併排序來的有效率。

下面這個程式範例，我們使用快速排序法來處理小筆資料排序，然後再使用合併排序法處理合併的動作。
*/
int main(void)
{
    int number1[MAX1] = {0};
    int number2[MAX1] = {0};
    int number3[MAX1 + MAX2] = {0};
    int i, num;

    srand(time(NULL));

    printf("排序前：");
    printf("\nnumber1[]:");
    for (i = 0; i < MAX1; i++)
    {
        number1[i] = rand() % 100;
        printf("%d ", number1[i]);
    }

    printf("\nnumber2[]:");
    for (i = 0; i < MAX2; i++)
    {
        number2[i] = rand() % 100;
        printf("%d ", number2[i]);
    }

    // 先排序兩筆資料
    quicksort(number1, 0, MAX1 - 1);
    quicksort(number2, 0, MAX2 - 1);
    //關於quick_sort可以參考quick_sort3.c

    printf("\n排序後:");
    printf("\nnumber1[]:");
    for (i = 0; i < MAX1; i++)
        printf("%d ", number1[i]);
    printf("\nnumber2[]:");
    for (i = 0; i < MAX2; i++)
        printf("%d ", number2[i]);

    // 合併排序
    mergesort(number1, MAX1, number2, MAX2, number3);

    printf("\n合併後:");
    for (i = 0; i < MAX1 + MAX2; i++)
        printf("%d ", number3[i]);

    printf("\n");

    return 0;
}

int partition(int number[], int left, int right)
{
    int i, j, s;

    s = number[right];
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

void mergesort(int number1[], int M, int number2[],
               int N, int number3[])
{
    int i = 0, j = 0, k = 0;

    while (i < M && j < N)
    {
        //判斷number1[i]跟number2[i], 誰小就把誰放進number3[k]
        if (number1[i] <= number2[j])
            number3[k++] = number1[i++];
        else
            number3[k++] = number2[j++];
    }

    while (i < M)
        number3[k++] = number1[i++];
    while (j < N)
        number3[k++] = number2[j++];
}