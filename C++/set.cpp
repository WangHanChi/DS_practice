#include <iostream>
using namespace std;
#include <iomanip>

/*
以array(矩陣)來表示set(集合)

Set是不講求順序(order)的資料彙集(collection), 其概念可以使用類似tree的資料結構來實現

*/

int FindSetCollapsing(int *subset, int i)
{
    int root;
    for (root = i; subset[root] >= 0; root = subset[root]) //找到root

        while (i != root) //進行collapsing
        {
            int parent = subset[i];
            subset[i] = root;
            i = parent;
        }

    return root;
}

void UnionSet(int *subset, int x, int y)
{
    int xroot = FindSetCollapsing(subset, x);
    int yroot = FindSetCollapsing(subset, y);

    //用rank比較, 負越多表示set越多element, 所以是值比較小的element比較多
    // xroot, yroot的subset[]一定都是負值

    // x比較多element或是一樣多時候, 以x作為root
    if (subset[xroot] <= subset[yroot])
    {
        subset[xroot] += subset[yroot];
        subset[yroot] = xroot;
    }
    else // subset[xroot] > subset[yroot], 表示y比較多element
    {
        subset[yroot] += subset[xroot];
        subset[xroot] = yroot;
    }
}

void PrintArray(int *array, int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << setw(3) << i;
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

int main()
{
    const int size = 6;
    int array[size] = {-1, -1, -1, -1, -1, -1};
    PrintArray(array, size);

    UnionSet(array, 1, 2);
    cout << "After union(1, 2) : \n";
    PrintArray(array, size);

    UnionSet(array, 0, 2);
    cout << "After union(0, 2) : \n";
    PrintArray(array, size);

    UnionSet(array, 3, 5);
    cout << "After union(3, 5) : \n";
    PrintArray(array, size);

    UnionSet(array, 2, 5);
    cout << "After union(2, 5) : \n";
    PrintArray(array, size);

    cout << "element(5) belongs to Set(" << FindSetCollapsing(array, 5) << ").\n";
    cout << "After collapsing : \n";
    PrintArray(array, size);

    return 0;
}