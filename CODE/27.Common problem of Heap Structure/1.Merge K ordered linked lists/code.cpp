// 合并 K 个 有序链表

// 链表数：K
// 总结点数：N

// 方案一：暴力
// 1）方法：
//      1）收集所有结点 Time Complexity：O(N)
//                     Space Complexity：O(N)
//      2）将容器中的结点排序 Time Complexity：O(N * log2(N))
//                          Space Complexity：O(1)
//      3）将排好的结点串起来 Time Complexity：O(N)
//                          Space Complexity：O(1)
//
//  2）复杂度分析：
//      1）Time Complexity：O(N * log2(K))
//      2）Space Complexity：O(N)

// 方案二：小根堆
// 1）方法：
//      1）先把每条链表的首结点放在小根堆中并排序 Time Complexity：O(k) or O(k * log2(k))
//                                            Space Complexity：O(k)
//      2）弹出小根堆堆顶元素作为合并头部，并将其所在链表的下一个结点放在小根堆中   Time Complexity：O(k) or O(k * log2(k))
//                                                                            Space Complexity：O(k)      
//
//      3）依次循环，直到小根堆中没有结点
//
//  2）复杂度分析：
//      1）Time Complexity：O(N * log2(K))
//      2）Space Complexity：O(K)


#include<bits/stdc++.h>

using namespace std;

typedef struct Node
{
    int val;
    struct Node* next;
    Node(int x) : val(x) , next(nullptr) {}
}Node , *PTR;

// 谁小谁优先级高
// 结果 <0 P1 优先级高
// 结果 >0 P2 优先级高
// 结果 =0 P1 P2 优先级一样高
class ComparePTR
{
public:
    bool operator()(const PTR& P1 , const PTR& P2) const
    {
        return P1->val > P2->val;
    }
};

void CreateList(PTR& L , PTR& T)
{
    int n , i=0;
    scanf("%d" , &n);
    while(n--)
    {
        int x;
        scanf("%d" , &x);
        PTR P = new Node(x);

        if(i++==0)
        {
            L = P;
            T = P;
            continue;
        }

        T->next = P;
        T = T->next;
    }
}

void PrintList(PTR L)
{
    while(L!=nullptr)
    {
        printf("%d " , L->val);
        L = L->next;
    }
    printf("\n");
}

PTR MergeKList(vector<PTR>& v)
{
    // 方案一：另写比较类
    //priority_queue<PTR , vector<PTR> , ComparePTR> MinHeap;

    // 方案二：Lambda函数
    auto f = [](const PTR& P1 , const PTR& P2)
    {
        return P1->val > P2->val;
    };

    priority_queue<PTR , vector<PTR> , decltype(f)> MinHeap(f);
    //'decltype' 是 C++11 中引入的关键字，用于获取表达式的类型

    // 方案三：在类别函数中自己定义比较器
    // 这里不方便写

    for(const auto& P : v)
    {
        // 将几个表头插入到小根堆中
        if(P!=NULL)
        {
            MinHeap.push(P);
        }
    }

    // 创建完整链表
    PTR H = new Node(0);
    PTR T = H;

    // 如果小根堆有数
    while(!MinHeap.empty())
    {
        PTR N = MinHeap.top();
        MinHeap.pop();
        
        T->next = N;
        T = T->next;

        if(N->next != nullptr)
        {
            MinHeap.push(N->next);
        }
    }

    return H->next;
}

int main()
{
    PTR H1=nullptr , T1=nullptr;
    PTR H2=nullptr , T2=nullptr;
    PTR H3=nullptr , T3=nullptr;

    CreateList(H1 , T1);
    CreateList(H2 , T2);
    // CreateList(H3 , T3);

    // PrintList(H1);
    // PrintList(H2);
    // PrintList(H3);

    vector<PTR> v = {H1 , H2};

    PTR H = MergeKList(v);

    PrintList(H);

    return 0;
}

// 一、算法思路：
// 1）建立一个 MinHeap 将首结点放入并排序 priority_queue 排序复杂度 O(log2(K))
// 2）push 最小结点的作为答案链表的开始
// 3）如果 push 的结点 后面还有结点，则继续更新结点，直到 MinHeap.empty() == 1

// 二、Complexity：
// 1）Time Complexity：O(N * log2(N))  (K <= N)
//			1）排首结点：O(K * log2(K))
//			2）所有结点：O(N * log2(N))
//
// 2）Space Complexity：O(K)