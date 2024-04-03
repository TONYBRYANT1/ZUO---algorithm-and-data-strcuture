// 树的层序遍历：
//
// 方法一：每一次处理一个数据
// 1）先将根结点放在队列中
// 2）当元素出队时，如果有左孩子，就将左孩子放在队中，如果有右孩子，就将右孩子放在队中 (先放左孩子，再放右孩子，如果有的话)
// 3）依次弹出元素
// 4）如此往复

#include<bits/stdc++.h>

using namespace std;

typedef struct TreeNode
{
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : value(x) , left(nullptr) , right(nullptr) {}
}TreeNode , *P;

// 树的层序遍历：
vector<vector<int>> Tree_Level_Order_Traversal(P H)
{
    // 1）存储准备
    //      1）树表：每个结点所对应的层数
    unordered_map<P , int> HashMap;
    //      2）队列：便于实现层序遍历
    queue<P> que;
    //      3）记录答案，按照每一层存储
    vector<vector<int>> ans;

    // 2）特判：如果 H 为空，就退出
    if(H == nullptr)
    {
        return ans;
    }

    // 3）H不为空：
    // 准被工作，将根结点放入队列，并更新 HashMap
    que.push(H);
    HashMap[H] = 0;
    // 只要que中还有元素就继续出队和入队：
    //出队时记录答案，入队时更新 que 和 HashMap
    while(!que.empty())
    {
        // 出队：记录答案
        P cur = que.front(); // 记录当队的首结点
        que.pop(); // 首结点弹出
        int level = HashMap[cur];
        // 如果该层没有对应的vector<int>：要添加一个vector<int>
        if(ans.size() == level)
        {
            ans.push_back(vector<int>());
        }
        // 有该level所对应的vector<int>：直接添加
        ans[level].push_back(cur->value);

        // 入队：
        //如果有左孩子，就将左孩子放在队中，如果有右孩子，就将右孩子放在队中 (先放左孩子，再放右孩子，如果有的话)
        //
        // 有左孩子：
        if(cur->left != nullptr)
        {
            // 入队 + 更新 HashMap
            que.push(cur->left); // 入队
            HashMap[cur->left] = level+1;
        }

        // 有右孩子：
        if(cur->right != nullptr)
        {
            // 入队 + 更新 HashMap
            que.push(cur->right); // 入队
            HashMap[cur->right] = level+1;
        }

    }

    return ans;

}

int main()
{
    P H = new TreeNode(1);
    H->left = new TreeNode(2);
    H->right = new TreeNode(3);
    H->left->left = new TreeNode(4);
    H->left->right = new TreeNode(5);
    H->right->left = new TreeNode(6);
    H->right->right = new TreeNode(7);

    vector<vector<int>> ans = Tree_Level_Order_Traversal(H);

    for(const auto& e1 : ans)
    {
        for(const auto& e2 : e1)
        {
            printf("%d " , e2);
        }
        printf("\n");
    }
    
    return 0;
}