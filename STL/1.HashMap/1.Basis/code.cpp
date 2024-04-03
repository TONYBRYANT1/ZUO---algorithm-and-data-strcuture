// C++ STL 中的 HashMap 被称为 unordered_map，是一个用于存储键-值对的数据结构，
// 其中键和值可以是任意类型。HashMap 使用哈希表来实现，因此查找、插入和删除操作的平均时间复杂度为 O(1)。

// 以下是 unordered_map 的一些基本操作：

// 插入键-值对：使用 insert() 方法或者使用下标操作符 []。
// 删除键-值对：使用 erase() 方法。
// 查找键对应的值：使用 find() 方法，如果键存在则返回一个指向该键的迭代器，否则返回 end()。
// 访问键对应的值：可以使用下标操作符 [] 或者 at() 方法。
// 遍历：使用迭代器或者范围-based for 循环进行遍历。
// 以下是 unordered_map 的简单示例代码：

#include <iostream>
#include <unordered_map>

int main() {
    // 创建一个 unordered_map
    std::unordered_map<std::string, int> umap;

    // 插入键-值对
    umap.insert({"apple", 10});
    umap["banana"] = 20;

    // 访问和修改值
    umap["apple"] = 15;

    // 删除键-值对
    umap.erase("banana");

    // 查找键
    auto it = umap.find("apple");
    if (it != umap.end()) 
    {
        std::cout << "apple 的值为: " << it->second << std::endl;
    } else {
        std::cout << "未找到 apple" << std::endl;
    }

    // 遍历 unordered_map
    for (const auto& pair : umap) // 直接引用键值对 
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}