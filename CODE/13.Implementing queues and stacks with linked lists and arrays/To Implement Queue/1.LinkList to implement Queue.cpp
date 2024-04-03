#include<bits/stdc++.h>

using namespace std;

typedef struct LNode
{
    int val;
    struct LNode* next;
}LNode , *LinkList;

void InitList(LinkList& H , LinkList& T)
{
    H = new LNode;
    H->next = NULL;
    T = H;
}

void CreateList(LinkList& H , LinkList& T , int& sum)
{
    InitList(H , T);
    
    int n=0 , i=0;
    scanf("%d" , &n);

    while(n--)
    {
        int x;
        scanf("%d" , &x);

        if(i++==0)
        {
            H->val = x;
            sum++;
            continue;
        }

        LinkList P = new LNode;
        P->val = x;
        P->next = NULL;
        T->next = P;
        T = P;

        sum++;
    }
}

void PrintList(LinkList& H)
{
    LinkList P = H;
    while(P != NULL)
    {
        printf("%d " , P->val);
        P = P->next;
    }
    printf("\n");
}

// 队列

// 判空
bool IsEmpty(LinkList H)
{
    if(H == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 队尾插入
void Offer(LinkList&T , int x , int& sum)
{
    LinkList P = new LNode;
    P->val = x;
    P->next = NULL;
    T->next = P;
    T = P;
    sum++;
}

// 队头取数
int Poll(LinkList& H , int& sum)
{
    int a = H->val;
    LinkList P = H;
    H = H->next;
    delete P;
    sum--;
    return a;
}

// 返回对头的元素的值，但是不删除头元素
int Peek(LinkList& H)
{
    return H->val;
}

// 队列大小
int size(int sum)
{
    return sum;
}

int main()
{
    // 创建链表
    LinkList H = NULL , T = NULL;
    int sum=0;
    CreateList(H , T , sum);
    PrintList(H);

// 队列
    // bool a = IsEmpty(H);
    // cout << a << endl;

    // cout << sum << endl;
    // int x;
    // scanf("%d" , &x);
    // Offer(T , x , sum);
    // cout << sum << endl;
    // PrintList(H);

    // PrintList(H);
    // int a = Poll(H , sum);
    // printf("a = %d\n" , a);
    // printf("sum = %d\n" , sum);
    // PrintList(H);

    // int a = Peek(H);
    // printf("a = %d\n" , a);

    // int a = size(sum);
    // printf("size = %d\n" , a);

    return 0;
}