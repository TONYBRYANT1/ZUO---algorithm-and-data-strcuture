// HashMap 的 SetAll

// 用时间戳实现，(SetAll_TimeStamp , SetAll_Value)
// 以 TSP(Time Stamp) 为时间的流动 SetAll_TimeStamp 为时间结点
// 时间结点前的数据组的数值为 同一值 value

// HashMap：1.key 2.pair<value , Time_Stamp>

#include<bits/stdc++.h>

using namespace std;

// 创建一个 HashMap
// 三个参数：1.key 2.value 3.time_stamp
unordered_map<int , pair<int , int>> HashMap;

int SetAll_TimeStamp;
int SetAll_Value;
int TSP; // Time Stamp

// 放一组数据
void HashMap_Put(int key , int value)
{
    // 1）存过数据
    if(HashMap.find(key) != HashMap.end())
    {
        HashMap[key].first = value;
        HashMap[key].second = TSP++;
    }
    // 2）没找到
    else
    {
        HashMap[key] = {value , TSP++};
    }
}

// 将当前时间戳之前的所有 数据组 的 value值 改为 特定值
void HashMap_SetAll(int value) // 这里的 value 是特定值
{
    SetAll_Value = value;
    SetAll_TimeStamp = TSP++;
}

int HashMap_Get(int key)
{
    // 1）之前没有存过这个数据组
    if(HashMap.find(key) == HashMap.end())
    {
        return -1;
    }
    // 2）之前有存过这个数据组
    else
    {
        // 2.1）所查询的数据组的时间戳 小于 SetAll的时间戳
        if(HashMap[key].second < SetAll_TimeStamp)
        {
            return SetAll_Value;
        }
        // 2.2）所查询的数据组的时间戳 大于 SetAll的时间戳
        else
        {
            return HashMap[key].first;
        }
    }
}

int main()
{
    int n , op , a , b;
    SetAll_TimeStamp = 0;
    SetAll_Value = 0;
    TSP = 0;
    cin >> n;
    while(n--)
    {
        cin >> op;
        if(op == 1)
        {
            cin >> a >> b;
            HashMap_Put(a , b);
        }
        else if(op == 2)
        {
            cin >> a;
            cout << HashMap_Get(a) << endl;
        }
        else
        {
            cin >> a;
            HashMap_SetAll(a);
        }
    }
    return 0;
}