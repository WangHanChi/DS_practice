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

/*
Selection sort 選擇排序
將要排序的頓對象分作兩部份,一個是已排序的,一個是未排序的,從後端末排序部份選擇一個最小值
,並放入前端已排序部份的最後一個
*/

void selsort(int[]);
// void insort(int[]);
// void bubsort(int[]);

int main()
{
    int number[MAX] = {0};
    int i;

    srand(time(NULL));

    printf("排序前 : ");
    for (i = 0; i < MAX; i++)
    {
        number[i] = rand() % 100;
        printf("%d ", number[i]);
    }

    printf("\n請選擇排序方式 : ");
    printf("\n(1) 選擇排序selection sort\n : ");
    scanf("%d", &i);

    switch (i)
    {
    case 1:
        selsort(number);
        break;


    default:
        printf("\n選項錯誤");
        break;
    }

    return 0;
}

//選擇排序
void selsort(int number[])
{
    int i, j, k, m;

    for (i = 0; i < MAX - 1; i++)
    {
        m = i;
        for (j = i + 1; j < MAX; j++)
        {
            if (number[j] < number[m])
                m = j;
            //搜尋陣列剩下的元素,並且把最小的值給m
        }
        if (i != m)
            SWAP(number[i], number[m])
        //交換i, m的位子
        printf("第 %d 次排序 : ", i + 1);
        for (k = 0; k < MAX; k++)
        {
            printf("%d ", number[k]);
        }

        printf("\n");
    }
}
