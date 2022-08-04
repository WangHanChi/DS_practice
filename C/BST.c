#include <stdio.h>
#include <stdlib.h>

// getch是一個windows系統下才擁有的語法
//而我所使用的為GCC 9.4.0
//因此無法編譯

/*
程式源碼參考自
http://ant.comm.ccu.edu.tw/course/96_Data_Structure/9_Upload/HW4/HW4_495430019.c
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

typedef struct tree //二元樹節點宣告
{
    int data;
    struct tree *left, *right; //分別指向左右樹的子指標
} tn, *bst;

bst root = NULL;
void insert(int d);    //插入新一筆資料
int search(int d);     //搜尋節點
bst deletet(int d);    //刪除節點
void inorder(bst ptr); //中序走訪
int print(bst ptr);    //將樹印出

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
            getch(con); //按任意鍵返回主選單
            break;

        case 2:
            printf("請輸入想要刪除的值 : ");
            scanf("%d", &data);
            deletet(data);
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
            getch(con);
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

int search(int d)
{
    bst ptr = root;
    while (ptr != NULL)
    {
        if (ptr->data == d) //找到所要尋找的值
        {
            return 1;
        }
        else
        {
            if (ptr->data > d) //比較資料
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
    }

    return 0;
}

bst deletet(int d)
{
    bst ptr, ptr_f, ptr_c;
    int find = 0;       //是否找到刪除節點
    ptr_f = ptr = root; //找尋刪除節點和其父節點指標
    while (ptr != NULL && !find)
    {
        if (ptr->data == d)
        {
            find = 1; //找到刪除節點
        }
        else
        {
            ptr_f = ptr;       //保留父節點指標
            if (ptr->data > d) //比較資料
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
    }

    if (ptr == NULL) //沒有找到刪除節點
    {
        printf("\n欲刪除的值不存在");
        return;
    }
    if (ptr->left == NULL && ptr->right == NULL && ptr == root) //只剩根節點, 並且刪掉根節點
    {
        root = NULL;
        ptr = NULL;
        printf("\n欲刪除的值已刪除");
        return;
    }
    if (ptr->left == NULL && ptr->right == NULL && ptr == root) //刪除二元搜尋樹的葉節點
    {
        if (ptr_f->left)
            ptr_f->left = NULL;
        else
            ptr_f->right = NULL;
        ptr = NULL; //釋放記憶體
        printf("\n欲刪除的值已刪除");
        return;
    }
    if (ptr->left == NULL) //沒有左子樹
    {
        if (ptr_f != ptr) //相等為根節點
        {
            if (ptr_f->left == ptr)
            {
                ptr_f->left = NULL;
            }
            else
            {
                ptr_f->right = NULL;
            }
        }
        else
        {
            root = root->right; //根節點指向右子節點
        }
        ptr = NULL;
        printf("\n欲刪除的值已刪除");
        return;
    }
    if (ptr->right == NULL) //  沒有右子樹
    {
        if (ptr_f != ptr) //相等為根節點
        {
            if (ptr_f->right == ptr)
            {
                ptr_f->right = ptr->left;
            }
            else
            {
                ptr_f->left = ptr->left;
            }
        }
        else
        {
            root = root->left; //  根節點指向左子節點
        }
        ptr = NULL;
        printf("\n欲刪除的值已刪除");
        return;
    }
    //有左子樹和右子樹
    ptr_f = ptr;                 //父節點指向刪除節點
    ptr_c = ptr->left;           //設定成左子節點
    while (ptr_c->right != NULL) //找到最右的葉節點
    {
        ptr_f = ptr_c;        //保留父節點指標
        ptr_c = ptr_c->right; //往右子樹走
    }
    ptr->data = ptr_c->data;  //設定成葉節點資料
    if (ptr_f->left == ptr_c) //子節點沒有右子樹
        ptr_f->left = ptr_c->left;
    else
        ptr_f->right = ptr_c->left;
    ptr_c = NULL;
    printf("\n欲刪除的值已刪除");
    return;
}

void inorder(bst ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        printf("%d", ptr->data);
        inorder(ptr->right);
    }
}

int print(bst ptr)
{
    if (ptr == NULL) //若樹為空的
    {
        return 0;
    }
    else
    {
        printf("%d", ptr->data); //走訪到的元素先印出來
                                 //再依照前序走訪的方式加上括號和逗號
        if (ptr->left)           //左邊有元素
        {
            printf("(");
            print(ptr->left);
        }
        else if (ptr->left == NULL) //左邊走到底了, 再往右邊走
        {
            if (ptr->right)
                printf("(");
        }
        if (ptr->right) //右邊有元素
        {
            if (ptr->left)
                printf(",");
            print(ptr->right);
            printf(")");
        }
        else if (ptr->right == NULL) //右邊走到底了, 再往左邊走
        {
            if (ptr->left)
                printf(")");
        }
    }
}
