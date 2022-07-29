/*
Stack implementation in C language array

Start in 2022/07/27 by wanghanchi in NCKU.

introduce :
There are some methods in stack.

1) .push()      //將元素放入stack中
2) .pop()       //將最上面的元素取出, 有時候可以依照需要, 回傳最上面的在將其取出
3) .isEmpty()   //判斷stack()是否為空
4) .isFull()    //判斷stack是否為滿
5) .print()     //列印出stack裡面所有的元素，從下而上 (當然也可以依照需求設計從上而下)
6) .top()       //表示最上面元素之索引位置

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int top;        //當前所指的數至(類似下標運算子)
    int maxTop;     //陣列的最大值
    int *data;
} stack_t;
//創建一個struct包住top, maxTop, *data

void create_stack(stack_t *st, int size)
{
    st->top = -1;
    st->maxTop = size - 1;
    st->data = (int *)malloc(sizeof(int) * size);
    //把top設置成-1, 再去配置記憶體(malloc)
    //並且把 *data 設置為這個矩陣的指標
}

int isEmpty(stack_t *st)
{
    if (st->top == -1)
        return 1;
    //查看 *st 裡面所只的top是否為-1, 若為是就代表是空的
    return 0;
}

int isFull(stack_t *st)
{
    if (st->top == st->maxTop)
        return 1;
    //查看top 是否與maxTop一樣, 若是一樣則為滿的
    return 0;
}

void push(stack_t *st, int num)
{
    if (isFull(st) == 1)
        printf("The stack is full\n");
    else
        st->data[++st->top] = num;
        //把*st所指的top+1之後, 把值丟進這個陣列
}

int pop(stack_t *st)
{
    if (isEmpty(st) == 1)
        printf("The stack is empty.\n");
    else
        return (st->data[st->top--]);
        //把*st 所指的top-1, 但其值其實還在
}

void print(stack_t *st)
{
    if (isEmpty(st) == 1)
        printf("The stack is empty.\n");
    else
    {
        int i;
        for (i = 0; i < st->top; i++)
            printf("%d ", st->data[i]);
        printf("\n");
    }
}

int main()
{
    stack_t *s = (stack_t *)malloc(sizeof(stack_t));

    printf("Create a stack which size is 5.\n");
    create_stack(s, 5);
    printf("Push : 1, 2, 3, 4, 5 : \n");
    for(int i = 1; i <=5; i++)
    {
        push(s, i);
    }
    print(s);

    printf("First time pop, the top is %d : \n", pop(s));
    print(s);
    printf("Second time po , the top is %d : \n", pop(s));
    print(s);
    return 0;
}