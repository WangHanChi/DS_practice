/*
Stack implementation in C language linked list
與array實做的最大不同是它不需要須告stack的大小
可以動態的新增或是刪除

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
    int data;
    struct stack *next;
} stack_t;
//宣告一個struct包住data跟指向下一個struct位置的指標

stack_t *head;

void create_stack()
{
    head = NULL;
}

int isEmpty()
{
    if (head == NULL)
        return 1;
    return 0;
}

void push(int num)
{
    stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));
    new_node->data = num;
    new_node->next = NULL;

    if (isEmpty() == 1)
        head = new_node;
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

int pop()
{
    if (isEmpty() == 1)
    {
        printf("The stack is empty.\n");
    }
    else
    {
        stack_t *temp = head;
        head = head->next;
        return temp->data;
    }
}

void print()
{
    if (isEmpty() == 1)
    {
        printf("The stack is empty.\n");
    }
    else
    {
        stack_t *curr = head;
        while (curr != NULL)
        {
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}
int main()
{
    head = (stack_t *)malloc(sizeof(stack_t));
    printf("Create a stack which size is 5.\n");
    create_stack();
    printf("Push : 1,2,3,4,5 : \n");
    for(int i = 1; i <= 5; i++)
    {
        push(i);
    }

    print();
    printf("First time pop, the top is %d : \n", pop());
    print();
    printf("Second time pop, the top is %d : \n", pop());
    print();


    return 0;
}
