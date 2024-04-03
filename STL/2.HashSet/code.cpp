// unordered_set 是 C++ STL 提供的一个无序集合容器，内部基于哈希表实现。unordered_set 的特点是快速查找元素，插入和删除操作的时间复杂度接近常数时间。以下是 unordered_set 的一些常用操作：

// 插入元素 insert(key)：向无序集合中插入一个元素 key。

// 删除元素 erase(key)：从无序集合中删除指定元素 key。

// 查找元素 find(key)：在无序集合中查找指定元素 key，返回一个迭代器指向该元素，如果未找到，则返回 end()。

// 访问元素：可以通过迭代器进行元素的访问和遍历，例如：

// unordered_set<int> mySet = {1, 2, 3};
// for (auto it = mySet.begin(); it != mySet.end(); ++it) {
//     cout << *it << " ";
// }
// 获取元素个数 size()：返回无序集合中元素的个数。

// 判断集合是否为空 empty()：如果无序集合为空，则返回 true，否则返回 false。

// 清空集合 clear()：清空无序集合中的所有元素。

// 下面是一个简单示例，展示了如何使用 unordered_set 进行插入、删除和遍历操作：

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> mySet;

    // 插入元素
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);

    // 删除元素
    mySet.erase(2);

    // 查找元素
    auto it = mySet.find(3);
    if (it != mySet.end()) {
        cout << "Element found: " << *it << endl;
    } else {
        cout << "Element not found" << endl;
    }

    // 遍历集合
    for (auto ele : mySet) {
        cout << ele << " ";
    }
    cout << endl;

    // 获取集合大小
    cout << "Size of set: " << mySet.size() << endl;

    // 判断集合是否为空
    if (mySet.empty()) {
        cout << "Set is empty" << endl;
    } else {
        cout << "Set is not empty" << endl;
    }

    // 清空集合
    mySet.clear();

    return 0;
}
