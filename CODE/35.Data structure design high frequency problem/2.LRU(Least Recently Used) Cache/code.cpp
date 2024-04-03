// Cache
// LRU (least recently used) 最近最少使用到的
// (HashMap_Put)、(HashMap_Get) 都会影响 最近最少使用的 排列顺序 

// 实现方法：
//
// 1）技术：
//          1）HashMap：1.key 2.Node_Address
//          2）双向链表：(a , value1) <=> (b , value2) <=> (c , value3)
//                          早                中               晚
//
// 2）每次影响 LRU 的操作都会影响双向链表的结构(早中晚结构)

#include<bits/stdc++.h>

using namespace std;

class LRUCache
{
// LRUCache所拥有的部件及其描述
private:
    // 1）LRUCache拥有的部件描述：
    //      1）双向链表结点：
    typedef struct Node
    {
        int key;
        int value;
        struct Node* last;
        struct Node* next;
        Node(int key , int value) : key(key) , value(value) {}
    }Node , *P;

    //      2）双向链表：
    struct List
    {
        P H , T;

        List() : H(nullptr) , T(nullptr) {}

        // 尾插
        void List_AddNode(P New_Node)
        {
            // 1）加入的结点为空
            if(New_Node == nullptr)
            {
                return;
            }
            // 2）链表为空
            if(H == nullptr)
            {
                H = New_Node;
                T = New_Node;
            }
            // 3) 链表不为空
            //    将 结点 加到最后 表示 晚
            else
            {
                T->next = New_Node;
                New_Node->last = T;
                T = T->next;
            }
        }

        // 默认链表有结点
        void List_Move_Node_To_Tail(P Node)
        {
            // 1）结点就在尾巴上
            if(T == Node)
            {
                return;
            }
            // 2）结点在头上
            if(H == Node)
            {
                // 撇清关系
                H = H->next;
                H->last = nullptr;
                Node->next = nullptr;
                // 开始挪动
                Node->last = T;
                Node->next = nullptr;
                T->next = Node;
                T = T->next;
            }
            // 3）结点在非首位的地方
            if((Node!=H)&&(Node!=T))
            {
                // 撇清关系
                Node->last->next = Node->next;
                Node->next->last = Node->last;
                Node->last = nullptr;
                Node->next = nullptr;
                // 开始挪动
                Node->last = T;
                Node->next = nullptr;
                T->next = Node;
                T = T->next;
            }
        }

        // 除去头部
        P List_Remove_Head()
        {
            // 1）链表为空
            if(H == nullptr)
            {
                return nullptr;
            }
            // 2）链表只有一个结点
            if(H == T)
            {
                // 记录当前结点
                P ans = H;
                H = nullptr;
                T = nullptr;
                return ans;
            }
            // 3）链表不止一个结点
            else
            {
                P ans = H;
                H = H->next;
                ans->next = nullptr;
                ans->last = nullptr;
                return ans;
            }
        }
    };

    // 2）LRUCache拥有的具体部件：
    //      1）HashMap
    unordered_map<int , P> HashMap;
    int Capacity;
    List DoubleList;

// LRUCache的具体功能
public:
    // 1）容量：
    LRUCache(int capacity) : Capacity(capacity) {}

    // 2）获得数据组
    int get(int key)
    {
        // 找不到
        if(HashMap.find(key) == HashMap.end())
        {
            return -1;
        }
        // 找得到
        else
        {
            // 记录答案
            P ans = HashMap[key];
            // 更新LRU
            DoubleList.List_Move_Node_To_Tail(ans);
            return ans->value;
        }
    }

    // 3）放数据
    void put(int key , int value)
    {
        // 当已经有了key对应的数据组
        if(HashMap.find(key) != HashMap.end())
        {
            HashMap[key]->value = value;
            DoubleList.List_Move_Node_To_Tail(HashMap[key]);
        }
        // 当前没有key对应的数据组
        else
        {
            // 当前容量满了
            if(HashMap.size() == Capacity)
            {
                HashMap.erase(DoubleList.List_Remove_Head()->key);
            }
            // 增加与key对应的数据组
            // 链表上：
            P p = new Node(key , value);
            DoubleList.List_AddNode(p);
            // HashMap上：
            HashMap[key] = p;
        }
    }
};
