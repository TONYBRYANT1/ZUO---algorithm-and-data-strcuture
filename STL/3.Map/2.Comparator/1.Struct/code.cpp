// C++ STL 中的 map 是一个关联容器，它提供了一种键值对的存储方式，并根据键的比较规则对元素进行排序。map 使用红黑树（Red-Black Tree）数据结构来实现，这个数据结构保证了元素在插入时按照键的顺序存储，并且支持高效的查找、插入和删除操作。

// 以下是一些关于 map 的重要特点和用法：

// 有序存储： map 中的元素是按照键的顺序进行存储的，默认情况下按照键的升序进行排序。你也可以通过提供自定义的比较器来指定元素的排序规则。

// 键值对： 每个元素都是一个键值对，其中键是唯一的，且不可重复，值可以重复。

// 动态大小： map 是一个动态大小的容器，它可以根据需要动态增长或缩小，而不需要手动管理内存。

// 高效的操作： map 提供了高效的查找、插入和删除操作，时间复杂度为 O(log n)，其中 n 是容器中元素的数量。

// 迭代器支持： map 支持正向迭代器，可以使用迭代器遍历容器中的元素。

// 以下是一个示例代码，演示了如何使用 map 存储一些字符串和对应的整数值，并按照键的升序顺序输出它们：

#include<bits/stdc++.h>

using namespace std;

struct Comparator
{
    bool operator() (int a , int b) const // 这里的 第二个 const 是 const修饰的成员函数 ---> 函数中的成员变量是不能够被修改的
    {
        return a < b;
    }
};

int main()
{
    map<int , int , Comparator> Map;
    Map.insert({1 , 6});
    Map.insert({6 , 1});
    Map.insert({4 , 3});
    Map.insert({3 , 4});
    Map.insert({5 , 2});
    Map.insert({2 , 5});

    for(const auto& pair : Map)
    {
        cout << pair.first << " " << pair.second << endl;
    }
    
    return 0;
}