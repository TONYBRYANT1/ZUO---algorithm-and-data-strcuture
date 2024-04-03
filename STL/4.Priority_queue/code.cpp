// push(): 将元素压入优先级队列。
// std::priority_queue<int> pq;
// pq.push(5);
// pq.push(10);

// top(): 返回优先级队列中优先级最高的元素的引用。
// std::priority_queue<int> pq;
// pq.push(5);
// pq.push(10);
// int highest_priority = pq.top(); // highest_priority 等于 10

// pop(): 弹出优先级队列中优先级最高的元素。
// std::priority_queue<int> pq;
// pq.push(5);
// pq.push(10);
// pq.pop(); // 弹出 10，现在队列中只剩下一个元素 5

// size(): 返回优先级队列中的元素数量。
// std::priority_queue<int> pq;
// pq.push(5);
// pq.push(10);
// int size = pq.size(); // size 等于 2

// empty(): 检查优先级队列是否为空。
// std::priority_queue<int> pq;
// bool is_empty = pq.empty(); // is_empty 为 true，因为队列为空

// emplace(): 在优先级队列中构造新元素。
// std::priority_queue<std::pair<int, int>> pq;
// pq.emplace(5, 10); // 构造一个 pair，第一个元素是 5，第二个元素是 10

// swap(): 交换两个优先级队列的内容。
// std::priority_queue<int> pq1;
// pq1.push(5);
// std::priority_queue<int> pq2;
// pq2.push(10);
// pq1.swap(pq2); // 现在 pq1 中的元素是 10，pq2 中的元素是 5
// 这些是 std::priority_queue 中一些常用的操作。它们使得对于优先级队列的基本操作变得非常方便。