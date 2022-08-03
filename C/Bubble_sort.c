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
Bubble sort泡沫排序
顧名思義，就是排序時，最大的元素會如同氣泡一樣移至右端，
其利用比較相鄰元素的方法，將大的元素交換至右端，所以大的元素會不斷的往右移動，直到適當的位置為止。
基本的氣泡排序法可以利用旗標的方式稍微減少一些比較的時間，當尋訪完陣列後都沒有發生任何的交換動作，
表示排序已經完成，而無需再進行之後的迴圈比較與交換動作
*/

// void selsort(int[]);
//void insort(int[]);
void bubsort(int[]);

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
    printf("(1) 氣泡排序bubble sort\n : ");
    scanf("%d", &i);

    switch (i)
    {

    case 1:
        bubsort(number);
        break;

    default:
        printf("\n選項錯誤");
        break;
    }

    return 0;
}

//氣泡排序法
void bubsort(int number[])
{
    int i, j, k, flag = 1;

    for(i = 0 ; i < MAX - 1 && flag == 1; i++)
    {
        flag = 0;
        for(j = 0 ; j < MAX - i - 1; j++)
        {
            if(number[j+1] < number[j])
            {
                SWAP(number[j+1], number[j]);
                flag = 1;
            }
        }

        printf("第 %d 次排序 : ", i+1);
        for(k = 0 ; k < MAX; ++k)
        {
            printf("%d ", number[k]);
        }

        printf("\n");
    }
}
