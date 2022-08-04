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
說明:
在 快速排序法（一） 中，每次將最左邊的元素設為軸，而之前曾經說過，
快速排序法的加速在於軸的選擇，在這個例子中，只將軸設定為中間的元素，
依這個元素作基準進行比較，這可以增加快速排序法的效率。


解法:
在這個例子中，取中間的元素s作比較，同樣的先得右找比s大的索引 i，然後找比s小的索引 j，
只要兩邊的索引還沒有交會，就交換 i 與 j 的元素值，這次不用再進行軸的交換了，因為在尋找交換的過程中，軸位置的元素也會參與交換的動作，例如：
41　24　76　11　45　64　21　69　19　36

首先left為0，right為9，(left+right)/2 = 4（取整數的商），所以軸為索引4的位置，比較的元素是45，您往右找比45大的，往左找比45小的進行交換：
41　24　76*　11　[45]　64　21　69　19　*36
41　24　36　11　45*　64　21　69　19*　76
41　24　36　11　19　64*　21*　69　45　76
[41　24　36　11　19　21]　[64　69　45　76]

完成以上之後，再初別對左邊括號與右邊括號的部份進行遞迴，如此就可以完成排序的目的。
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
        s = number[(left + right) / 2];
        i = left - 1;
        j = right + 1;

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

        quicksort(number, left, i - 1);  // 對左邊進行遞迴
        quicksort(number, j + 1, right); // 對右邊進行遞迴
    }
}
