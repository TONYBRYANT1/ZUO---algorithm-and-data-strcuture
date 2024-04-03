// 环形链表 找第一个 入环结点

// 方案：
//
// 1）容器：HashSet
//          1）依次遍历每一个结点，如果没有放入 HashSet，则放入
//          2）当发现当前要放入的结点，再 HashSet 中已经有了，则返回该节点
//          3）若一直遍历，直到nullptr，则返回 nullptr

// 2）快慢指针：
//          1）将 p_fast 指向 H->next->next (步长为 2)
//             将 p_slow 指向 H->next       (步长为 1)
//          2）当 p_fast 与 p_slow 相遇时，slow 停下，p_fast回到 H (步长从新设置为 1)
//             若 一直不相遇 直到 p_fast 到 nullptr，则返回 nullptr
//          3）p_slow 不动，p_fast(步长为 1)，一直走，直到二者相遇，当相遇时，该指针指向的结点为入环的第一个结点

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

void List_Print(P H)
{
    while(H!=nullptr)
    {
        printf("%d " , H->val);
        H = H->next;
    }
    cout << endl;
}

P List_First_Entry_Loop_Node(P H)
{
    // 为了保证 fast 和 slow 所指向的结点不为空，进行特判
    // 0）特判：
    //    1）无结点
    if(H==nullptr)
    {
        return nullptr;
    }
    //    2）单结点无环
    if(H->next == nullptr)
    {
        return nullptr;
    }    
    //    3）双结点无环
    if(H->next->next == nullptr)
    {
        return nullptr;
    }

    P fast = H->next->next , slow = H->next;

    while(fast!=slow)
    {
        if((fast->next == nullptr) || (fast->next->next == nullptr))
        {
            return nullptr;
        }
        fast = fast->next->next; // 步长为 2
        slow = slow->next;       // 步长为 1
    }

    // fast == slow
    fast = H;
    while(fast != slow)
    {
        fast = fast->next; // 步长为 1
        slow = slow->next; // 步长为 1
    }

    return fast;
}

int main()                  //         ----------------
{                           //         |              ^
    P H1 , T1;              //         v              |
    List_Creation(H1 , T1); //    1 -> 2 -> 3 -> 4 -> 5

    P p1 = H1->next;
    P p2 = H1->next->next->next->next;

    p2->next = p1;

    P H = List_First_Entry_Loop_Node(H1); 
    printf("%d" , H->val);
    return 0;
}