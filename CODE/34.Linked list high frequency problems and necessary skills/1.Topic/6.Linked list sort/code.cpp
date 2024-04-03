// 链表排序：
//
// 1）容器：数组 + MergeSort ==> space complexity：O(N)
// 
// 2) 链表 + MergeSort(迭代版)：
//    1）利用结点的跳转结构

#include<bits/stdc++.h>

using namespace std;

typedef struct Node
{
    int val;
    struct Node* next;
    Node(int x) : val(x) , next(nullptr) {}
}Node , *P;

P s , e;

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

P List_Find_Node(P H , int step)
{
    // step = 4 --> 走三步 // 3 2 1 
    while((H->next!=nullptr) && (--step))
    {
        H = H->next;
    }
    return H;
}

void List_RegionSort(P l1 , P r1 , P l2 , P r2)
{
    // 1）找首结点元素
    // 新链表 s -> ... -> e (t为尾插法的工具指针)
    P t;
    if(l1->val <= l2->val)
    {
        s = l1;
        t = l1;
        l1 = l1->next;
    }
    else
    {
        s = l2;
        t = l2;
        l2 = l2->next;
    }

    // 2）链表比较 连接新链表
    while((l1!=nullptr)&&(l2!=nullptr))
    {
        if((l1->val)<=(l2->val))
        {
            t->next = l1;
            t = t->next;
            l1 = l1->next;
        }
        else
        {
            t->next = l2;
            t = t->next;
            l2 = l2->next;
        }
    }
    // l1 or l2 其中一个走完了
    if(l1 == nullptr)
    {
        t->next = l2;
        e = r2;
    }
    else
    {
        t->next = l1;
        e = r1;
    }

}

P List_MergeSort(P H)
{
    // 1）结点个数：
    int n=0;
    P p = H;
    while(p!=nullptr)
    {
        n++;
        p = p->next;
    }

    // 2）迭代 归并 (每一个step 的第一个 RegionSort，因为换头问题，应该特判)
    P l1 , r1 , l2 , r2 , nxt , lte; // lte(Last Team End)
    for(int step=1 ; step < n ; step<<=1)
    {
        // 因为 step < n
        // 所以第一次 RegionSort 肯定有 右段(至少有一个)
        l1 = H;
        r1 = List_Find_Node(l1 , step);
        l2 = r1->next; // 第一次 RegionSort l2肯定存在
        r2 =List_Find_Node(l2 , step); // 第一次 RegionSort r2 肯定存在
        nxt = r2->next; // 记录下一个结点
        
        // 分段：
        r1->next = nullptr; // l1 -> ... -> r1 -> nullptr
        r2->next = nullptr; // l2 -> ... -> r2 -> nullptr

        // RegionSort：
        List_RegionSort(l1 , r1 , l2 , r2); // s -> ... -> e
        
        // 换新的头 
        H = s;
        // 上一队的队尾 作连接使用
        lte = e;

        while(nxt != nullptr)
        {
            // 下一段至少有一个结点不为空
            l1 = nxt;
            r1 = List_Find_Node(l1 , step);
            l2 = r1->next;
            // 只有左段，没有有段
            if(l2 == nullptr)
            {
                lte->next = l1;
                break;
            }
            // 有右段
            r2 = List_Find_Node(l2 , step);

            // 又开始 RegionSort
            nxt = r2->next;
            
            r1->next = nullptr;
            r2->next = nullptr;

            List_RegionSort(l1 , r1 , l2 , r2);

            lte->next = s;
            lte = e;
        }
    }
    return H;
}

int main()
{
    P H1 , T1;
    List_Creation(H1 , T1);
    List_Print(H1);
    P H = List_MergeSort(H1);
    List_Print(H1);
    return 0;
}
