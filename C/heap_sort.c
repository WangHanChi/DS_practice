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
選擇排序法的概念簡單，每次從未排序部份選一最小值，插入已排序部份的後端，
其時間主要花費於在整個未排序部份尋找最小值，如果能讓搜尋最小值的方式加快，
選擇排序法的速率也就可以加快，Heap排序法讓搜尋的路徑由樹根至最後一個樹葉，
而不是整個未排序部份，因而稱之為改良的選擇排序法。
Heap排序法使用Heap Tree（堆積樹），樹是一種資料結構，而堆積樹是一個二元樹，
也就是每一個父節點最多只有兩個子節點（關於樹的詳細定義還請見資料結構書籍），
堆積樹的 父節點若小於子節點，則稱之為最小堆積（Min Heap），父節點若大於子節點，
則稱之為最大堆積（Max Heap），而同一層的子節點則無需理會其大小關係，例如下面就是一個堆積樹：

可以使用一維陣列來儲存堆積樹的所有元素與其順序，為了計算方便，使用的起始索引是1而不是0，
索引1是樹根位置，如果左子節點儲存在陣列中的索引為s，則其父節點的索引為s/2，
而右子節點為s+1，就如上圖所示，將上圖的堆積樹轉換為一維陣列之後如下所示：

建立好堆積樹之後，樹根一定是所有元素的最小值，您的目的就是：
將最小值取出
然後調整樹為堆積樹

不斷重複以上的步驟，就可以達到排序的效果，最小值的取出方式是將樹根與最後一個樹葉節點交換，然後切下樹葉節點，重新調整樹為堆積樹
調整完畢後，樹根節點又是最小值了，於是我們可以重覆這個步驟，再取出最小值，並調整樹為堆積樹

如此重覆步驟之後，由於使用一維陣列來儲存堆積樹，每一次將樹葉與樹根交換的動作就是將最小值放至後端的陣列，
所以最後陣列就是變為已排序的狀態。其實堆積在調整的過程中，就是一個選擇的行為，
每次將最小值選至樹根，而選擇的路徑並不是所有的元素，而是由樹根至樹葉的路徑，因而可以加快選擇的過程，
所以Heap排序法才會被稱之為改良的選擇排序法。
*/
void createheap(int[]);
void heapsort(int[]);

int main(void)
{
    int number[MAX + 1] = {-1};
    int i, num;

    srand(time(NULL));

    printf("排序前：");
    for (i = 1; i <= MAX; i++)
    {
        number[i] = rand() % 100;
        printf("%d ", number[i]);
    }

    printf("\n建立堆積樹:");
    createheap(number);
    for (i = 1; i <= MAX; i++)
        printf("%d ", number[i]);
    printf("\n");

    heapsort(number);

    printf("\n");

    return 0;
}

void createheap(int number[])
{
    int i, s, p;
    int heap[MAX + 1] = {-1};

    for (i = 1; i <= MAX; i++)
    {
        heap[i] = number[i];
        s = i;
        p = i / 2;
        while (s >= 2 && heap[p] > heap[s])
        {
            SWAP(heap[p], heap[s]);
            s = p;
            p = s / 2;
        }
    }

    for (i = 1; i <= MAX; i++)
        number[i] = heap[i];
}

void heapsort(int number[])
{
    int i, m, p, s;

    m = MAX;
    while (m > 1)
    {
        SWAP(number[1], number[m]);
        m--;

        p = 1;
        s = 2 * p;

        while (s <= m)
        {
            if (s < m && number[s + 1] < number[s])
                s++;
            if (number[p] <= number[s])
                break;
            SWAP(number[p], number[s]);
            p = s;
            s = 2 * p;
        }

        printf("\n排序中:");
        for (i = MAX; i > 0; i--)
            printf("%d ", number[i]);
    }
}