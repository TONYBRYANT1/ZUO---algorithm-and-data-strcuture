// 求完全二叉树的结点个数
// 
// 方案：
//      1）右子树可以扎到最底层：左子树为满二叉树
//      return (左子树 + 根结点 + f(右子树))
//
//      2）右子树不能扎到最底层：右子树为满二叉树
//      return (右子树 + 根结点 + f(左子树))
//
// 满二叉树结点个数：2^h-1 (h 为满二叉树高度)

#include<bits/stdc++.h>

using namespace std;

typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
}TreeNode , *P;

class Counter
{
private:
    int h;
private:
    int MaxDeep(P cur , int level)
    {
        // 当右子树为空时，level不应该+1，所以要-1
        // if(cur == nullptr)
        // {
        //     return level-1;
        // }

        while((cur!=nullptr)&&(cur->left!=nullptr))
        {
            level++;
            cur = cur->left;
        }
        return level;
    }

    int f(P cur , int level)
    {
        // 当前结点来到叶结点
        if(level == h)
        {
            return 1;
        }

        // 右子树的最左结点 可以 扎到最深层：
        // 右子树不空 且 最左结点 能扎到最深层
        if((cur->right!=nullptr)&&(MaxDeep(cur->right , level+1) == h))
        {   
           // 右子树扎到最深层 ==> 左子树满了
           return ((1<<(h-level)) + f(cur->right , level+1)); 
        }   
        else
        {
            // 右子树没扎到最深层，但是因为是完全二叉树，所以右子树是满二叉树
            return ((1<<(h-level-1)) + f(cur->left , level+1));
        }
    }
public:
    int count(const P& root)
    {
        if(root==nullptr)
        {
            return 0;
        }

        h = MaxDeep(root , 1);

        return f(root , 1);
    }
};

int main()
{
    P root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    // root->right->left = new TreeNode(7);
    Counter cnt;
    printf("%d" , cnt.count(root));
    return 0;
}