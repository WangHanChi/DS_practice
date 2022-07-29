#include <stdio.h>
#include <stdlib.h>

/*
1) 程式名稱說明  : 二元搜尋樹
2) 參數說明     :

    data: 操作各種功能時需要的節點資料
    td: 樹的節點資料
    sel: 選擇各種功能
    con: 使程式返回主選單
    tn: 二元樹節點的新型態
    *bst: 二元樹鏈結的新型態
    root: 根節點指標
    ptr: 操作各種功能時的暫存指標
    newtn: 樹的新節點
    now: 目前二元樹的指標
    ptr_f: 父節點指標
    ptr(副函式deletet): 刪除節點指標
    ptr_c: 子節點指標



*/

typedef struct tree
{
    int data;
    struct tree *left, *right;
} tn, *bst;

bst root = NULL;
void insert(int d);
int search(int d);
bst delete (int d);
void inorder(bst ptr);
int print(bst ptr);

int main(int argc, char *argv[])
{
    int data, sel, td;
    char con;
    while (1)
    {
        printf("請選擇所需要執行的動作\n\n");
        printf("(1) 新增一筆資料\n(2) 刪除一筆資料\n(3) 查詢某筆資料\n");
        printf("(4) 印出整棵樹\n(5) 印出前序走訪結果\n(0)結束\n\n");
        printf("所要執行操作 : ");
        scanf("%d", &sel);
        printf("\n");

        switch (sel)
        {
        case 1:
            printf("請輸入想增加的值 : ");
            scanf("%d", &data);

            if (search(data))
                printf("資料重複");
            else
            {
                insert(data);
                printf("\n\n按任意鍵返回主選單");
            }
            getch(con);
            break;

        case 2:
            printf("請輸入想要刪除的值 : ");
            scnaf("%d", &data);
            delete (data);
            printf("\n\n按任意鍵返回主選單");
            getch(con);
            break;
        case 3:
            printf("請輸入想要查詢的值 : ");
            scanf("%d", data);
            if (search(data))
                printf("該值存在\n\n");
            else
                printf("乾值不存在\n\n");
            printf("\n\n按任意鍵返回主選單");
            getch(con);
            break;
        case 4:
            printf("(");
            print(root);
            printf(")\n\n");
            printf("\n\n按任意鍵返回主選單");
            break;
        case 5:
            inorder(root);
            printf("\n\n");
            printf("\n\n按任意鍵返回主選單");
            getch(con);
            break;
        default:
            if (sel != 0)
            {
                printf("輸入指令錯誤\n");
                printf("\n\n按任意鍵返回主選單");
                getch(con);
            }
            break;
            if (sel == 0)
            {
                printf("程式結束");
                break;
            }

            system("cls");
        }

        system("pause");

        return 0;
    }
}

void insert(int d)
{
    bst newtn, now;
    int insert = 0;                  //是否插入新節點
    newtn = (bst)malloc(sizeof(tn)); //配置新節點記憶體
    newtn->data = d;                 //建立節點內容
    newtn->left = newtn->right = NULL;
    if (root == NULL)
    {
        root = newtn; //建立根節點
    }
    else
    {
        now = root;
        while (!insert) //比較節點值
        {
            if (now->data > newtn->data)
            {
                if (now->left == NULL)
                {
                    now->left = newtn; //建立鏈結
                    insert = 1;
                }
                else
                {
                    now = now->left; //左子樹
                }
            }
            else
            {
                if (now->right == NULL) //是否是最右節點
                {
                    now->right = newtn; //建立鏈結
                    insert = 1;
                }
                else
                {
                    now = now->right; //右子樹
                }
            }
        }
    }
}
