// O(1) 时间插入、删除和获取随机元素 - 允许重复

// 因为允许重复 ---> 导致有多个下标 ---> HashMap(key , 下标收集容器)
// 又因为查 HashMap 表的时间复杂度为O(1) ---> 下标收集容器只能为 HashSet 
// ---> 删除元素只能随机删除，不能有序 ---> 有序代表复杂度大于O(1)

#include<bits/stdc++.h>

using namespace std;

class RandomizedCollection
{
public:
    vector<int> arr;
    unordered_map<int , unordered_set<int>> HashMap;
public:
    RandomizedCollection()
    {
        // 设置随机数种子
        srand((unsigned)time(nullptr));
    }

    bool insert(int key)
    {
        // 存过 key
        if(HashMap.find(key) != HashMap.end())
        {
            // 获得 arr 下标
            int index_1 = arr.size();
            // arr 存数
            arr.push_back(key);
            // 更新 HashMap
            HashMap[key].insert(index_1);
            // 存过 key 返回 false
            return false;
        }
        // 没存过 key
        else
        {
            // 获得 arr 下标
            int index_1 = arr.size();
            // arr 存数
            arr.push_back(key);
            // 更新 HashMap
            HashMap[key].insert(index_1);
            // 没存过 key 返回 true
            return true;
        }
    }   

    bool remove(int key)
    {
        // 没存过 key
        if(HashMap.find(key) == HashMap.end())
        {
            return false;
        }
        // 存过 key
        else
        {
            // 特判：如果要删除的元素在 arr 尾巴上有
            if(HashMap[key].find(arr.size()-1) != HashMap[key].end())
            {
                // 直接删除末尾元素
                HashMap[key].erase(arr.size()-1);
                arr.pop_back();
                // 如果数组中该元素的个数为0 ---> 在Map中删除该数据组
                if(HashMap[key].size() == 0)
                {
                    HashMap.erase(key);
                }
                // 存过 key 返回 true
                return true;
            }

            // 获得要删除 key 的下标
            int index_1 = *HashMap[key].begin();
            // 获得 arr 末尾元素下标
            int index_2 = arr.size()-1;
            // 获得 arr 末尾元素值
            int value = arr.back();
            // 删除 arr[index_1] ---> 用 value 填补 arr[index_1]
            arr[index_1] = value;
            arr.pop_back();
            // 更新 HashMap
            HashMap[key].erase(index_1);
            HashMap[value].erase(index_2);
            HashMap[value].insert(index_1);
            // 如果数组中该元素的个数为0 ---> 在Map中删除该数据组
            if(HashMap[key].size() == 0)
            {
                HashMap.erase(key);
            }
            // 存过 key 返回 true
            return true;
        }
    }

    int getRandom()
    {
        return arr[rand()%(arr.size())];
    }
};