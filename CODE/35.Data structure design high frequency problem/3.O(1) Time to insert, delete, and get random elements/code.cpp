// O(1) 时间插入、删除和获取随机元素

// 对于一个动态数组 vector<int> arr 来说：
// 插入元素：O(1)   --->   但是不能在O(1)的时间内保证元素仅有一个   ---> 用 HashMap 来配合查表
// 删除元素(给数值)：O(N)   ---> 用 HashMap 来配合查表
// 随机数：O(1)
//
// ==> 数据结构：1.vector<int> arr  2.HashMap

#include<bits/stdc++.h>

using namespace std;

class O_1_Insert_Delete_Random
{
private:
    unordered_map<int , int> HashMap;
    vector<int> arr;

public: 
    O_1_Insert_Delete_Random()
    {
        srand((unsigned)time(nullptr));
    }

    bool insert(int key)
    {
        // HashMap中有key对应的数据组
        if(HashMap.find(key) != HashMap.end())
        {
            return false;
        }
        // HashMap中没有key对应的数据组
        //      HashMap中加入数据
        HashMap[key] = arr.size(); // 新增数值所对应的下标 就是数组当前的大小
        //      arr中加入数据
        arr.push_back(key);
        return true;
    }

    bool remove(int key)
    {
        // HashMap中没有key对应的数据组
        if(HashMap.find(key) == HashMap.end())
        {
            return false;
        }

        // 当要删除时，虽然可以快速的找到元素的下标，但是会有问题：
        // 1）对于普通数组 arr[]  ：
        //          会导致找到了下标但是值为空的情况
        // 2）对于vector<int> arr：
        //          会导致元素和下标错位的情况

        // 解决方案：
        //      用当前数组中最后一个数填补空缺
        // 1）通过key值找到下标
        int index = HashMap[key];
        // 2）得到arr中最后一个值
        int last_value = arr.back();
        // 3）填补arr中的空缺
        arr[index] = last_value;
        // 4）更新HashMap
        HashMap[last_value] = index;
        // 5）删除HashMap中key对应的数据组
        HashMap.erase(key);
        // 6）删除arr的末端元素
        arr.pop_back();

        return true;
    }

    int getRandom()
    {
        return  arr[rand()%arr.size()];
    }
};

int main()
{
    return 0;
}