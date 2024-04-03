#include<bits/stdc++.h>

using namespace std;

typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode , *LinkList;

LinkList H1 , H2;
int sum , n;

void CreateList(LinkList& H , int n)
{
    LinkList T;
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
    while(n--)
    {
        P = P->next;
    }
    return P->data;
}

LinkList MergeTwoLists(LinkList& H1 , LinkList& H2)
{
    // 其中一个没有数
    if(H1 == NULL || H2 == NULL)
    {
        return H1 == NULL ? H2 : H1;
    }

    // 都有数谁做头
    LinkList H = H1->data <= H2->data ? H1 : H2;

    // pre是大部队 | cur1 cur2 是侦察兵
    LinkList pre , cur1 , cur2;
    pre = H;
    cur1 = H->next;
    cur2 = H == H1 ? H2 : H1;
    
    // 当侦察兵还可以遇到数时
    while(cur1 != NULL && cur2 != NULL)
    {
        if(cur1->data <= cur2->data)
        {
            pre->next = cur1;
            cur1 = cur1->next;
        }
        else
        {
            pre->next = cur2;
            cur2 = cur2->next;
        }
        pre = pre->next;
    }

    // 最后结算
    pre->next = cur1 == NULL ? cur2 : cur1;

    return H;
}

int main()
{
    scanf("%d" , &n);
    // H1
    for(int i=0 ; i<n ; i++)
    {   
        int x;
        scanf("%d" , &x);
        CreateList(H1 , x);
    }
    sum=0;

    for(int i=0 ; i<n ; i++)
    {
        printf("%d " , getval(H1 , i));
    }
    printf("\n"); 

    // H2
    for(int i=0 ; i<n ; i++)
    {   
        int x;
        scanf("%d" , &x);
        CreateList(H2 , x);
    }
    sum=0;

    for(int i=0 ; i<n ; i++)
    {
        printf("%d " , getval(H2 , i));
    }
    printf("\n");

    // Merge
    LinkList H = MergeTwoLists(H1 , H2);
    for(int i=0 ; i<2*n ; i++)
    {
        printf("%d " , getval(H , i));
    }
    printf("\n");
    return 0;
}