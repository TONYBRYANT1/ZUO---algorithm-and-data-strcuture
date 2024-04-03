// 每k个节点一组翻转链表

// 1）容器：
//          1）直接用数组就可以

// 2）空间复杂度：O(1)
//          1）链表实现

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

P Team_Exist(P s , int k)
{
    k--;
    while(k--)
    {
        if(s == nullptr)
        {
            return s;
        }
        s = s->next;
    }
    return s;
}

void Team_Reverse(P s , P e)
{
    e = e->next;
    P cur = s , nxt = nullptr , pre = nullptr;
    while(cur != e)
    {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }

    s->next = e;
}

P Reverse_List_Per_K(P H1 , int k)
{
    P s = H1;
    P e = Team_Exist(s , k);
    if(e == nullptr)
    {
        return H1;
    }

    H1 = e;
    Team_Reverse(s , e);
    P LastTeamEnd = s;

    while(LastTeamEnd->next != nullptr)
    {
        s = LastTeamEnd->next;
        e = Team_Exist(s , k);
        if(e == nullptr)
        {
            return H1;
        }
        Team_Reverse(s , e);
        LastTeamEnd ->next = e;
        LastTeamEnd = s;
    }
    return H1;
}

int main()
{
    P H1 = nullptr , T1 = nullptr;
    List_Creation(H1 , T1);
    PrintList(H1);
    P H = Reverse_List_Per_K(H1 , 3);
    PrintList(H);
    return 0;
}