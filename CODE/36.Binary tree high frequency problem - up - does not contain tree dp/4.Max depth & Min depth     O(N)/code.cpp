// 二叉树 最大&最小 深度

#include<bits/stdc++.h>

using namespace std;

typedef struct TreeNode
{
    unsigned long long value;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(unsigned long long x) : value(x) , left(nullptr) , right(nullptr) {}
}TreeNode , *P;

int MaxDepth(P H)
{
    // 两棵子树作比较：
    return H == nullptr ? 0 : max(MaxDepth(H->left) , MaxDepth(H->right)) + 1;
}

int MinDepth(P H)
{
    // 空树：
    if(H == nullptr)
    {
        return 0;
    }

    // 叶结点：
    if((H->left == nullptr)&(H->right == nullptr))
    {
        return 1;
    }

    // 非空树、叶结点：
    int L_Min = INT_MAX;
    int R_Min = INT_MAX;

    if(H->left != nullptr)
    {
        L_Min = MinDepth(H->left);
    }

    if(H->right != nullptr)
    {
        R_Min = MinDepth(H->right);
    }

    return min(L_Min , R_Min) + 1;
}

int main()
{
    return 0;
}