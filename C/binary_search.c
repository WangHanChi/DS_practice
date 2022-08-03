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

void quickSort(int[], int, int);
int binarySearch(int[], int);

int main(void)
{
    srand(time(NULL));

    int number[MAX] = {0};

    int i;
    for (i = 0; i < MAX; i++)
    {
        number[i] = rand() % 100; //隨機產生10個亂數
    }

    quickSort(number, 0, MAX - 1); //由小而大排序
    //傳參為(array, min, max)

    printf("數列：");
    for (i = 0; i < MAX; i++)
        printf("%d ", number[i]); //將其印出來

    int find;
    printf("\n輸入尋找對象:");
    scanf("%d", &find);

    if ((i = binarySearch(number, find)) >= 0)
        printf("找到數字於索引 %d ", i);
    else
        printf("\n找不到指定數");

    printf("\n");

    return 0;
}

int binarySearch(int number[], int find)
{
    int low = 0;         //宣告上限
    int upper = MAX - 1; //宣告下限
    while (low <= upper)
    {
        int mid = (low + upper) / 2;
        //搜尋策略-> 先把陣列切一半, 如果陣列一半的值小於要搜索的值的話
        //就把下限變成中間的那個數值, 也就是對半切完之後中間值+1變成下限
        //反之亦然, 若直接找到的話就回傳中間值
        if (number[mid] < find)
            low = mid + 1;
        else if (number[mid] > find)
            upper = mid - 1;
        else
            return mid;
    }
    return -1;
}

void quickSort(int number[], int left, int right)
{
    if (left < right)
    {
        int s = number[(left + right) / 2];
        int i = left - 1;
        int j = right + 1;

        while (1)
        {
            while (number[++i] < s)
                ; // 向右找
            while (number[--j] > s)
                ; // 向左找
            if (i >= j)
                break;
            SWAP(number[i], number[j]);
        }

        quickSort(number, left, i - 1);  // 對左邊進行遞迴
        quickSort(number, j + 1, right); // 對右邊進行遞迴
    }
}