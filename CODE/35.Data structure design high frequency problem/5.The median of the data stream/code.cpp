// 用 大根堆 小根堆 将数据流进行维护
// eg：1 2 3 4 5 6 7
// 大根堆维护低段(自顶向下)：3 2 1
// 小根堆维护高段(自顶向下)：4 5 6 7
//
// 大根堆进入条件：1.大小根堆都为空 2.数据流当前数据 小于 or 等于 大根堆堆顶
// 小根堆进入条件：1.数据流当前数据 大于 or 等于 大根堆堆顶

#include<bits/stdc++.h>
using namespace std;

class MedianFinder 
{
public:
    // 大根堆比较器：
    struct Comparator_1
    {
        bool operator() (const double& a , const double& b) const
        {
            return a > b;
        }
    };

    // 小根堆比较器：
    struct Comparator_2
    {
        bool operator() (const double& a , const double& b) const
        {
            return a < b;
        }
    };

public:
    priority_queue<double , vector<double> , Comparator_1> B_Heap;
    priority_queue<double , vector<double> , Comparator_2> S_Heap;
public:
    MedianFinder() 
    {
        ;
    }

    void addNum(double value) 
    {
        // 大根堆进入条件：1.大小根堆都为空 2.数据流当前数据 小于 or 等于 大根堆堆顶
        if( (B_Heap.size()==0) || (value <= B_Heap.top()) )
        {
            B_Heap.push(value);
        }
        // 小根堆进入条件：1.数据流当前数据 大于 or 等于 大根堆堆顶
        else
        {
            S_Heap.push(value);
        }
        // 当 大小根堆 的 大小差距 大于等于 2 时 应作调整
        balance();
    }
    
    double findMedian() 
    {
        // 当 大小根堆的 大小 相等时 ---> 数据流个数为偶数 ---> 平均值
        if(B_Heap.size() == S_Heap.size())
        {
            return double((B_Heap.top() + S_Heap.top())/2);
        }
        else
        {
            return B_Heap.size() > S_Heap.size() ? B_Heap.top() : S_Heap.top();
        }
    }

    int abss(int x)
    {
        if(x < 0)
        {
            x = -x;
        }
        return x;
    }

    void balance()
    {
        // 当 大小根堆 的 大小差距 大于等于 2 时 应作调整
        if(abss(B_Heap.size() - S_Heap.size()) >= 2)
        {
            if(B_Heap.size() > S_Heap.size())
            {
                S_Heap.push(B_Heap.top());
                B_Heap.pop();
            }
            else
            {
                B_Heap.push(S_Heap.top());
                S_Heap.pop();
            }
        }
    }
};