#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next; // point to next node
    struct node *prev; // point to previous node
} Node;

void add_node(Node **start, int value);
void print_list(Node *node);
void insert_node(Node **start, int insert_after_value, int value);
void delete_node(Node **start, int value);
void inverse_print_list(Node *node);
void free_list(Node *node);

int main(int argc, char *argv[])
{
    // create first node "head"
    Node *head = NULL;
    add_node(&head, 5);
    add_node(&head, 128);
    add_node(&head, 41);

    // insert non-exist node, linked list would not have changed
    insert_node(&head, 77, 92);
    // insert after node of data 128
    insert_node(&head, 128, 84);
    // insert after the lst node
    insert_node(&head, 41, 97);

    print_list(head);

    // delete the first node
    delete_node(&head, 5);
    // delete the node of data 41
    delete_node(&head, 41);
    // delete the last node
    delete_node(&head, 97);

    print_list(head);

    Node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    inverse_print_list(last);

    free_list(head);

    return 0;
}

void add_node(Node **start, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*start == NULL)
    {
        *start = new_node;
        //代表這是第一個節點, 接著就把*new_node的值丟給*start, 就可以回傳了
        return;
    }
    else
    {
        Node *current;
        current = *start;
        while (current->next != NULL)
        {
            current = current->next;
            //由於不是一個新的節點, 所以要搜尋雙向鏈結串列之中最後的一個節點
            //*current類似一個計數器, 一個一個往下指到最後一個節點
        }
        current->next = new_node;
        //當找到最後一個節點之後, 就把*current的向前指標連結到*new_node
        new_node->prev = current;
        //然後把*new_node的向後指標往回指到*current
        //也就是說, 目前的這個結點，將會成為*new_node的上一個結點

        return;
    }
}

void insert_node(Node **start, int insert_after_value, int value)
{
    Node *current = *start;

    while (current != NULL)
    {
        if (insert_after_value == current->data) //判斷是否存在要插入的點
        {
            Node *new_node = (Node *)malloc(sizeof(Node));
            new_node->data = value;
            new_node->next = NULL;
            new_node->prev = NULL;
            //先把新的節點設置好(配好記憶體, 指標都先空指, data存入value)
            if (current->next == NULL)
            {
                //假如發現要插入的點為整個串列的最後一個, 那就如同增加節點.add_node()一樣
                //先把 *current的 *next指向新節點*new_node,
                //再把新節點的 *prev指回到 *current
                current->next = new_node;
                new_node->prev = current;
                break;
            }
            else
            {
                //當要插入的點並非是整個串列的最後一個點時
                //所以我們讓 新節點的下一個節點為目前節點的下一個節點
                new_node->next = current->next;
                //接著再把目前節點 *current的下一個節點 *next中往回指的指標 *prev指到新節點 *new_node
                current->next->prev = new_node;
                //接著再把新節點 *new_node成為目前節點 *current的下一個節點 *next
                current->next = new_node;
                //新節點的前一個節點為目前的節點
                new_node->prev = current;
                break;
            }
        }
        current = current->next;
    }
}

void delete_node(Node **start, int value)
{
    Node *current = *start;
    Node *temp;

    if (value == current->data)
    {
        *start = current->next;
        (*start)->prev = NULL;
        free(current);
        return;
    }

    while (current != NULL)
    {
        if (current->next->data == value)
        {
            //如果目前結點的下一個結點的數值等同於我們要刪除的結點的數值，
            //則我們把目前結點的下一個結點先指定給一個 temp 的變數
            temp = current->next;
            //而目前節點的下一個節點就要變成目前節點的下下一個節點
            current->next = current->next->next;

            if (current->next != NULL)
            {
                //!!!特別注意 : 這裡需要多一個判斷, 就是下一個節點不能等同於NULL的情況之下
                //才能讓目前結點等同於下一個結點的前一個結點，這麼做是為了防止當我們刪除最後一個結點的時候，
                // current->next 本來就是 NULL，所以不需要在去設定指定的結點
                current->next->prev = current;
            }
            free(temp);
            return;
        }
        current = current->next;
    }
}

void print_list(Node *node)
{
    printf("List : \n");
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
        //原理非常簡單, 設定一個從頭開始的指標, 當指標不為空時,
        //代表指標還沒走到底, 所以繼續這個while
    }
    printf("\n");
}

void inverse_print_list(Node *node)
{
    printf("Inverse List : \n");
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->prev;
        //這個與print_list的不同之處在於, 我們是從最後一個節點,往回回朔至第一個節點
        //並且印出整個反向的串列數值
        //這裡我們傳進來的 node 已經是整個串列中的最後一個結點了，如果結點不等於 NULL
        //，印出來它的數值，然後再指向前一個結點，直到前一個結點也是指向 NULL 為止
    }
    printf("\n");
}

void free_list(Node *node) //  釋放掉所有的記憶體空間
{
    Node *current, *temp;
    current = node;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
}