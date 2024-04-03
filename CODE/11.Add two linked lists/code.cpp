#include<bits/stdc++.h>

using namespace std;

typedef struct LNode
{
    int val;
    struct LNode* next;
}LNode , *LinkList;

void AddElem(LinkList& H , LinkList& T , int x , int& sum)
{
    LinkList P = new LNode;
    P->val = x;
    P->next = NULL;

    if(sum > 0)
    {
        T->next = P;
        T = P;
    }
    else
    {
        H = P;
        T = P;
    }
    sum++;
}

void CreateList(LinkList& H , LinkList& T , int n)
{
    int sum=0;
    for(int i=0 ; i<n ; i++)
    {
        int x;
        scanf("%d" , &x);
        AddElem(H , T , x , sum);
    }
}

int getval(LinkList H , int n)
{
    n -= 1;
    while(n--)
    {
        H = H->next;
    }
    return H->val;
}

LinkList AddTwoNumbers(LinkList H1 , LinkList H2 , int& summ)
{
    LinkList ans = NULL , cur = NULL;
    int carry = 0;
    for(int sum , val ; 
        H1 != NULL || H2 != NULL;
        H1 = H1 == NULL ? NULL : H1->next , H2 = H2 == NULL ? NULL : H2->next)
    {
        sum = (H1 == NULL ? 0 : H1->val) + 
                (H2 == NULL ? 0 : H2->val) + 
                carry;

        val = sum%10;
        carry = sum / 10;
        if(ans == NULL)
        {
            ans = new LNode;
            ans->val=val;
            cur = ans;
            summ++;
        }
        else
        {
            cur->next = new LNode;
            cur->next->val = val;
            cur = cur->next;
            summ++;
        }
    }
    if(carry == 1)
    {
        cur->next = new LNode;
        cur->next->val = 1;
        summ++;
    }
    return ans;
}

int main()
{
    int n1 , n2;
    LinkList H1 , T1 , H2 , T2;

    // 第一个链表 H1
    scanf("%d" , &n1);
    CreateList(H1 , T1 , n1);

    // 第二个链表 H2
    scanf("%d" , &n2);
    CreateList(H2 , T2 , n2);

    // for(int i=1 ; i<=n1 ; i++)
    // {
    //     printf("%d " , getval(H1 , i));
    // }
    // printf("\n");

    // for(int i=1 ; i<=n2 ; i++)
    // {
    //     printf("%d " , getval(H2 , i));
    // }
    // printf("\n");
    
    int summ=0;
    LinkList H = AddTwoNumbers(H1 , H2 , summ);
    for(int i=1 ; i<=summ ; i++)
    {
        printf("%d " , getval(H , i));
    }

    return 0;
}