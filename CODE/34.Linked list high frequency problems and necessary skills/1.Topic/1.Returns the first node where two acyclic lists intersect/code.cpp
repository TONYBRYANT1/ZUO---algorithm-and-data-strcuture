// 返回两个无环链表相交的第一个节点

// 1）判断两个链表 是否 相交
//    eg: 
//          H1 -------> E1         H2 -------> E2
//
//    if: E1 == E2 --> 有交点
//    if: E1 != E2 --> 无交点

// 2）解决方案：
//      1）不用额外空间：
//              1）计算链表长度，算差值delta：H1(10)、H2(7) delta = 10 - 7 = 3
//              2）先让短链表走 delta 步，再共同走，如果有交点，则一定会相遇
//      2）利用额外空间：HashSet
//              1）将其中一条链表的所有结点的地址放入 HashSet
//              2）遍历另外一条链表，查询当前节点是否存在，如果存在，则为交点，若都不存在，则没有交点

#include<bits/stdc++.h>

using namespace std;

typedef struct Node
{
    int val;
    struct Node* next;
    Node(int x) : val(x) , next(nullptr) {}
}Node , *P;

void List_Initialization(P& H , P& T)
{
    int x;
    scanf("%d" , &x);
    H = new Node(x);
    T = H;
}

void List_Creation(P& H , P& T)
{
    int n=0 , i=0;
    scanf("%d" , &n);
    if(n==0)
    {
        return;
    }

    List_Initialization(H , T);

    n--;
    while(n--)
    {
        int x=0;
        scanf("%d" , &x);
        P p = new Node(x);
        T->next = p;
        T = p;
    }
}

void PrintList(P H)
{
    while(H!=nullptr)
    {
        printf("%d " , H->val);
        H = H->next;
    }
    cout << endl;
}

P Get_Intersection_Node(P& H1 , P& H2)
{
    int count_1=0 , count_2=0;
    P p1=H1 , p2=H2;
    while(p1!=nullptr)
    {
        count_1++;
        p1 = p1->next;
    }
        
    while(p2!=nullptr)
    {
        count_2++;
        p2 = p2->next;
    }

    if((count_1==0) | (count_2==0) | (p1!=p2))
    {
        return nullptr;
    }
    else
    {
        // p1 p2 指向头
        p1 = H1;
        p2 = H2;

        // 保证 p1 指向长链表
        if(count_1 < count_2)
        {
            P p = p1;
            p1 = p2;
            p2 =p;

            int temp = count_1;
            count_1 = count_2;
            count_2 = temp;
        }

        int delta = count_1 - count_2;

        // 长链表先走 delta 步
        while(delta--)
        {
            p1 = p1->next;
        }

        while(count_2--)
        {
            if(p1 == p2)
            {
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return nullptr;
}

int main()
{
    P H1=nullptr , H2=nullptr , T1=nullptr , T2=nullptr;
    List_Creation(H1 , T1); // 1 2 3 4 
    P t = H1;
    t = t->next;
    t = t->next;

    P p = new Node(5);
    p->next = t;


    // PrintList(H1);
    // PrintList(H2);

    P N = Get_Intersection_Node(H1 , p);
    if(N == nullptr)
    {
        printf("nullptr");
    }
    else
    {
        printf("%d" , N->val);
    }

    return 0;
} 