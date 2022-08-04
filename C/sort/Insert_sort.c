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
insert sort插入排序
像是玩樸克一樣，我們將牌分作兩堆，每次從後面一堆的牌抽出最前端的牌，然後插入前面一堆牌的適當位置
*/

// void selsort(int[]);
void insort(int[]);
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

    printf("\n請選擇排序方式 : \n");
    printf("(1) 插入排序insert sort\n : ");
    scanf("%d", &i);

    switch (i)
    {


    case 1:
        insort(number);
        break;

    default:
        printf("\n選項錯誤");
        break;
    }

    return 0;
}

//插入排序
void insort(int number[])
{
    int i, j, k, tmp;

    for (j = 1; j < MAX; j++)
    {
        tmp = number[j];
        i = j - 1;
        while (tmp < number[i])
        {
            number[i + 1] = number[i];
            i--;
            if (i == -1)
                break;
        }
        number[i + 1] = tmp;

        printf("第 %d 次排序 : ", j);
        for( k = 0 ; k < MAX; ++k)
        {
            printf("%d ", number[k]);
        }

        printf("\n");

    }
}
