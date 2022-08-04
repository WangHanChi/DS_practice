#include <stdio.h>
#include <stdlib.h>

/*
說明:
在之前所介紹過的排序方法，都是屬於「比較性」的排序法，也就是每次排序時 ，都是比較整個鍵值的大小以進行排序。
這邊所要介紹的「基數排序法」（radix sort）則是屬於「分配式排序」（distribution sort），
基數排序法又稱「桶子法」（bucket sort）或bin sort，顧名思義，它是透過鍵值的部份資訊，
將要排序的元素分配至某些「桶」中，藉以達到排序的作用，基數排序法是屬於穩定性的排序，
其時間複雜度為O (nlog(r)m)，其中r為所採取的基數，而m為堆數，在某些時候，基數排序法的效率高於其它的比較性排序法。

Radix sort 基本特性如下：

整數排序法：以整數作為排序的鍵值。
分配式排序法：不透過兩兩比較，而是分析鍵值分佈來排序。特定情況下可達線性執行時間。
穩定性：採用 LSD 的 Radix sort 屬穩定排序法（Stable sort）；透過優化，採用 MSD 也可以是穩定排序法。


步驟:
常見的 Radix sort 依據整數的每個位數來排序，依照位數排序的先後順序，可分為兩種：

    1.Least significant digit (LSD)：從最低有效鍵值開始排序（最小位數排到大）。
    2.Most significant digit (MSD)：從最高有效鍵值開始排序（最大位數排到小）。
簡單的 LSD Radix sort 步驟如下：
    1.LSD of each key：取得每個資料鍵值的最小位數（LSD）。
    2.Sorting subroutine：依據該位數大小排序資料。
    3.Repeating：取得下一個有效位數，並重複步驟二，至最大位數（MSD）為止。
而 MSD Radix sort 的步驟相似，但取得資料鍵值的方向相反。
    1.MSD of each key：取得每個資料鍵值的最大位數（MSD）。
    2.Sorting subroutine：依據該位數大小排序資料。
    3.Repeating：取得下一個有效位數，並重複步驟二，至最小位數（LSD）為止。


注意!!!!
由於 MSD Radix sort 先排序最大位數，會出現 8 > 126 的結果，這種順序通常稱為 Lexicographical order，
有如字典一般，越前面的字母排序權重越重，也因此，基本版的 MSD Radix sort 並非穩定排序法。
*/
int main(void)
{
    int data[10] = {73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
    int temp[10][10] = {0};
    int order[10] = {0};
    int i, j, k, n, lsd;

    k = 0;
    n = 1;

    printf("\n排序前: ");
    for (i = 0; i < 10; i++)
        printf("%d ", data[i]);

    putchar('\n');

    while (n <= 10)
    {
        for (i = 0; i < 10; i++)
        {
            lsd = ((data[i] / n) % 10);
            temp[lsd][order[lsd]] = data[i];
            order[lsd]++;
        }

        printf("\n重新排列: ");
        for (i = 0; i < 10; i++)
        {
            if (order[i] != 0)
                for (j = 0; j < order[i]; j++)
                {
                    data[k] = temp[i][j];
                    printf("%d ", data[k]);
                    k++;
                }
            order[i] = 0;
        }

        n *= 10;
        k = 0;
    }

    putchar('\n');
    //關於putchar可以參考 https://zhuanlan.zhihu.com/p/161237789
    printf("\n排序後: ");
    for (i = 0; i < 10; i++)
        printf("%d ", data[i]);

    return 0;
}