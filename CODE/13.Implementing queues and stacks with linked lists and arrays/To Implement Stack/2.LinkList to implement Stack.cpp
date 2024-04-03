#include<bits/stdc++.h>

using namespace std;

typedef struct LNode
{
    int val;
    struct LNode* next;
}LNode , *LinkList;

void InitList(LinkList& H , LinkList& T , LinkList& cur)
{
    H = new LNode;
    H->next = NULL;
    T = H;
    cur = H;
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

bool IsEmpty(LinkList& H)
{
    if(H == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    // return H == NULL ? true : false;
}

void Offer(LinkList& T , int x)
{
    LinkList P = new LNode;
    P->val = x;
    P->next = NULL;
    T->next = P;
    T = P;
}


int Pop(LinList& T)
{
    int a = T->val;
    
}

int main()
{
    LinkList H = NULL , T = NULL , cur = NULL;
    int sum=0;
    CreateList(H , T , cur , sum);
    PrintList(H);

    // printf("IsEmpty = %d\n" , IsEmpty(H));

    // int x=0;
    // scanf("%d" , &x);
    // Offer(T , x);
    // PrintList(H);




    return 0;
}