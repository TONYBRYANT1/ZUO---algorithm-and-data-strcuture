// 复制带随机指针的链表

// 1）容器： HashMap 照镜子
//
//          1）HashMap(key , value)
//          2）key  ：Node_1、Node_2、Node_3、Node_4
//          3）value：Node_1'、Node_2'、Node_3'、Node_4'
//
// 2）链表实现：用特殊的关系
//          
//             |---------|
//             |         |
//             v         v
//          1）a -> b -> c -> d
//
//             |---------------------|
//             |                     |
//             v                     v
//          2）a -> a' -> b -> b' -> c -> c' -> d -> d'
//                  ^                     ^
//                  |                     |
//                  |---------------------|
//
//          3）一组一组地提取出来：1.(a , a') 2.(b , b') 3.(c , c') 4.(d , d')
//          4）(a , a') ==> a'->random = a->random->next
//                              c'            c->next = c'

#include<bits/stdc++.h>

using namespace std;

typedef struct Node
{
    int val;
    struct Node* next;
    struct Node* random;
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

P List_Copy(P H)
{
    // 0）H 为 空
    if(H == nullptr)
    {
        return nullptr;
    }
    
    // 1）添加备份
    // a -> b -> c -> d
    // a -> a' -> b -> b' -> c -> c' -> d -> d'
    P cur = H , nxt , cpy; 
    while(cur!=nullptr)
    {
        nxt = cur->next;
        P p = new Node(cur->val);
        p->next = nxt;
        cur->next = p;
        cur = nxt;
    }

    // 2）random备份
    cur = H;
    while(cur != nullptr)
    {
        nxt = cur->next->next;
        cpy = cur->next;
        cpy->random = cur->random == nullptr ? nullptr : cur->random->next;
        cur = nxt;
    }

    // 3）分离
    cur = H;
    P ans = H->next;
    while(cur!=nullptr)
    {
        nxt = cur->next->next;
        cpy = cur->next;
        cur->next = nxt;
        cpy->next = nxt == nullptr ? nullptr : nxt->next;
        cur = nxt;
    }
    return ans;
}

int main()
{
    P H1 , T1;
    List_Creation(H1 , T1);
    List_Print(H1);
    P H = List_Copy(H1);
    List_Print(H);
    return 0;
}