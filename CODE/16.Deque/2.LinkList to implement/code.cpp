#include<bits/stdc++.h>

using namespace std;

typedef struct Node
{
    int val;
    struct Node* front;
    struct Node* next;
}Node , *PNode;

void CreateDeque(PNode& H , PNode& T , int& sum)
{
    int n=0 , i=0;
    scanf("%d" , &n);

    while(n--)
    {   
        int x=0;
        scanf("%d" , &x);

        if(i++==0)
        {
            H = new Node;
            H->next = NULL;
            H->front = NULL;
            H->val = x;
            T = H;

            continue;
        }

        PNode P = new Node;
        P->val = x;
        P->front = NULL;
        P->next = NULL;

        T->next = P;
        P->front = T;
        
        T = T->next;
    }
}

void PrintDeque_H(PNode& H)
{
    PNode P = H;
    while(P != NULL)
    {
        printf("%d " , P->val);
        P = P->next;
    }
    printf("\n");
}

void PrintDeque_T(PNode& T)
{
    PNode P = T;
    while(P != NULL)
    {
        printf("%d " , P->val);
        P = P->front;
    }
    printf("\n");
}

void Add_H(PNode& H , int x)
{
    PNode P = new Node;
    P->val = x;
    P->front = NULL;
    P->next = NULL;
    
    H->front = P;
    P->next = H;

    H = H->front;
}

void Add_T(PNode& T , int x)
{
    PNode P = new Node;
    P->val = x;
    P->front = NULL;
    P->next = NULL;

    P->front = T;
    T->next = P;
    T = T->next;
}

void Pop_H(PNode& H)
{
    if(H->next == NULL)
    {
        delete H;
    }
    else
    {
        H = H->next;
        delete H->front;
        H->front = NULL;
    }
    
}

void Pop_T(PNode& T)
{
    if(T->front == NULL)
    {
        delete T;
    }
    else
    {
        T = T->front;
        delete T->next;
        T->next = NULL;
    }
}

int main()
{
    PNode H , T;
    int sum=0;
    CreateDeque(H , T , sum);
    PrintDeque_H(H);

    int x;
    scanf("%d" , &x);
    Add_H(H , x);
    scanf("%d" , &x);
    Add_T(T , x);
    PrintDeque_H(H);

    Pop_H(H);
    PrintDeque_H(H);
    Pop_T(T);
    PrintDeque_H(H);

    return 0;
}