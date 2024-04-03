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

void CreateList(LinkList& H , LinkList& T)
{
    InitList(H , T);
    
    int n , m=0;
    scanf("%d" , &n);

    while(n--)
    {
        int x=0;
        scanf("%d" , &x);

        if(m++==0)
        {
            H->val = x;
            continue;
        }

        LinkList P = new LNode;
        P->val = x;
        P->next = NULL;
        T->next = P;
        T = P;
    }
    
}

void PrintList(LinkList& H)
{
    LinkList P = H;
    while(P!=NULL)
    {
        printf("%d " , P->val);
        P = P->next;
    }
    printf("\n");
}

LinkList Partition(LinkList& H , int x)
{
    LinkList next = NULL , BH = NULL , BT = NULL , LH = NULL , LT = NULL;
    while(H != NULL)
    {
        next = H->next;
        H->next = NULL;
        if(H->val < x)
        {
            if(LH == NULL)
            {
                LH = H;
            }
            else
            {
                LT->next = H;
            }
            LT = H;
        }
        else
        {
            if(BH == NULL)
            {
                BH = H;
            }
            else
            {
                BT->next = H;
            }
            BT = H;
        }
        
        H = next;
    }

    // LH~~~LT + BH~~~BT
    if(LH == NULL)
    {
        return BH;
    }
    else
    {
        LT->next = BH;
    }

    return LH;
}

int main()  
{
    LinkList H , T;
    CreateList(H , T);
    PrintList(H);
    int x=0;
    scanf("%d" , &x);
    LinkList HH = Partition(H , x);
    PrintList(HH);
    return 0;
}