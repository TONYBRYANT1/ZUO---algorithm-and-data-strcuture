// 回文链表

// 方案：
// 1）容器：stack
//          1）将结点放入栈中
//          2）将结点逐个拿出，与链表依次进行比对
//
// 2）快慢指针：

//    1）找中点：
//              1）慢指针一次走 1 结点
//              2）快指针一次走 2 结点      
//      eg:
//          1) Even：
//                  a -> b -> c -> d -> d -> c -> b -> a -> nullptr
//           慢指针：               i 
//           快指针：                              j
//
//          2) Odd ：
//                  a -> b -> c -> d -> c -> b -> a -> nullptr
//           慢指针：               i 
//           快指针：                              j

//    2）将后半段逆序：
//                              nullptr
//      eg:                        ^
//          1) Even:               |
//                  a -> b -> c -> d <- d <- c <- b <- a
//           慢指针：               i 
//           快指针：                              j
//
//                              nullptr
//                                 ^
//          2) Odd ：              |
//                  a -> b -> c -> d <- c <- b <- a
//           慢指针：               i 
//           快指针：                              j
//

//    3）从头到尾一次比对
//                              nullptr
//      eg:                        ^
//          1) Even:               |
//                  a -> b -> c -> d <- d <- c <- b <- a
//                  x ... ---> ... x    y ... <--- ... y
//
//                              nullptr
//                                 ^
//          2) Odd ：              |
//                  a -> b -> c -> d <- c <- b <- a
//                  x ... ---> ... x
//                                 y ... <--- ... y

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

//                      nullptr                    nullptr
//                         ^                          ^
//                         |                          |
//          eg： 1 -> 2 -> 3 <- 2 <- 1      1 -> 2 -> 3 <- 3 <- 2 <- 1
//                        nxt  cur  pre                   nxt  cur  pre
void List_Restore(P T)
{
    P cur = T , pre = nullptr , nxt = nullptr;
    while(cur!=nullptr)
    {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
}

bool List_Palindromic(P H1)
{
    // 0）特判：
    //      1）0个结点
    if(H1 == nullptr)
    {
        return true;
    }
    //      2）1个结点
    if(H1->next == nullptr)
    {
        return true;
    } 
    
    //      3）2个结点 -----------> 这个问题是双向比对时没有检查最后一对结点导致的，修复之后不用特殊考虑两个结点的情况
    // if((H1->next != nullptr) && (H1->next->next == nullptr))
    // {
    //     if((H1->val) == (H1->next->val))
    //     {
    //         return true;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }

    // 1）将慢指针送到中心：
    //          eg： 1 -> 2 -> 3 -> 2 -> 1      1 -> 2 -> 3 -> 3 -> 2 -> 1
    //                         i                          i
    P fast = H1 , slow = H1;
    while( (slow->next != nullptr)  &&  ((fast->next != nullptr) && (fast->next->next != nullptr)) )
    // while( (slow->next != nullptr)  &&  (fast->next->next != nullptr) ) // 当 fast->next==nullptr 时会出现越界问题
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2）逆序后半段，中间指成空
    //                      nullptr                    nullptr
    //                         ^                          ^
    //                         |                          |
    //          eg： 1 -> 2 -> 3 <- 2 <- 1      1 -> 2 -> 3 <- 3 <- 2 <- 1
    //                        per  cur  nxt              per  cur  nxt
    P cur = slow->next , per = slow , nxt = nullptr , T = nullptr;
    slow->next = nullptr;
    while(cur!=nullptr)
    {
        if(cur->next == nullptr)
        {
            T = cur;
        }
        nxt = cur->next;
        cur->next = per;
        per = cur;
        cur = nxt;
    }

    // 3）双向检测
    //
    //                      nullptr                    nullptr
    //                         ^                          ^
    //                         |                          |
    //          eg： 1 -> 2 -> 3 <- 2 <- 1      1 -> 2 -> 3 <- 3 <- 2 <- 1
    //               i                   j      i                        j
    P i = H1 , j = T;
    while((i!=nullptr) && (j!=nullptr))
    {
        if((i->val) != (j->val))
        {
            List_Restore(T);
            return false;
        }
        i = i->next;
        j = j->next;
    }
    return true;
}

int main()
{
    P H1 , T1;
    List_Creation(H1 , T1);
    List_Print(H1);
    printf("是回文链表吗：%s\n" , List_Palindromic(H1) == true ? "YES" : "NO");
    List_Print(H1);
    return 0;
}