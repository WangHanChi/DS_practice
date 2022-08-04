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

void shakersort(int[]);

/*
方括號括住的部份表示已排序完畢，Shaker排序使用了這個概念，如果讓左邊的元素也具有這樣的性質，
讓左右兩邊的元素都能先排序完成，如此未排序的元素會集中在中間，由於左右兩邊同時排序，中間未排序的部份將會很快的減少。
方法就在於氣泡排序的雙向進行，先讓氣泡排序由左向右進行，再來讓氣泡排序由右往左進行，
如此完成一次排序的動作，而您必須使用left與right兩個旗標來記錄左右兩端已排序的元素位置。

*/

int main(void)
{
    int number[MAX] = {0};
    int i;

    srand(time(NULL));

    printf("排序前：");
    for (i = 0; i < MAX; i++)
    {
        number[i] = rand() % 100;
        printf("%d ", number[i]);
    }

    shakersort(number);

    printf("\n");

    return 0;
}

void shakersort(int number[])
{
    int i, left = 0, right = MAX - 1, shift = 0;

    while (left < right)
    {
        // 向右進行氣泡排序
        for (i = left; i < right; i++)
        {
            if (number[i] > number[i + 1])
            {
                SWAP(number[i], number[i + 1]);
                shift = i;
            }
        }
        right = shift;

        printf("\n往右排序:");
        for (i = 0; i < MAX; i++)
            printf("%d ", number[i]);

        // 向左進行氣泡排序
        for (i = right; i > left; i--)
        {
            if (number[i] < number[i - 1])
            {
                SWAP(number[i], number[i - 1]);
                shift = i;
            }
        }
        left = shift;

        printf("\n向左排序:");
        for (i = 0; i < MAX; i++)
            printf("%d ", number[i]);
    }
}