// int arr[] = {1 , 2 , 3 , 4}     int b = new int(5)     
// 堆(内存) : {1 , 2 , 3 , 4}              5
// 栈(变量) : arr                          b

#include<bits/stdc++.h>

using namespace std;

typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode , *LinkList;

LinkList H , T;
int sum;

void CreateList(int n)
{
    LinkList p = new LNode;
    p->data = n;
    p->next = NULL;
    if(sum == 0)
    {
        H = p;
        T = p;
    }
    else
    {
        T->next = p;
        T = p;
    }
    sum++;
}

int getval(LinkList P , int n)
{
    n-=1;
    while(n--)
    {
        P = P->next;
    }
    return P->data;
}

// 单链表反转
LinkList ReverseList_Single(LinkList& H)
{
    LinkList pre = NULL;
    LinkList nxt = NULL;
    while(H != NULL)
    {
        nxt = H->next;
        H->next = pre;
        pre = H;
        H = nxt;
    }
    return pre;
}

// 双链表反转
// LinkList ReverseList_Double(LinkList& H)
// {
//     LinkList pre = NULL;
//     LinkList nxt = NULL;
//     while(H != NULL)
//     {
//         nxt = H->next;
//         H->next = pre;
//         H->last = nxt;
//         pre = H;
//         H = nxt;
//     }
//     return pre;
// }

int main()
{
    CreateList(1);
    CreateList(2);
    CreateList(3);
    printf("%d %d %d\n" , getval(H , 1) , getval(H , 2) , getval(H , 3));
    LinkList HH = ReverseList_Single(H);
    printf("%d %d %d\n" , getval(HH , 1) , getval(HH , 2) , getval(HH , 3));
    return 0;
}