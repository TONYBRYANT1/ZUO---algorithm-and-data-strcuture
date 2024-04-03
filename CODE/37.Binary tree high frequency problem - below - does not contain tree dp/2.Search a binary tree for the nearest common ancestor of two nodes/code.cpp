// 搜索二叉树上寻找两个节点的最近公共祖先
//
// 搜索二叉树：
//
//      左树任意一结点->val < cur->val < 右树任意一结点->val
// 
// 方法：
// 1）root 从上到下
// 2）如果先遇到 p ---> p 就是答案
// 3）如果先遇到 q ---> q 就是答案
// 4）如果 min(p , q) < root->val < max(p , q) ---> root 就是答案
// 5）如果 root < min(p , q) ---> root 往右走
// 6）如果 root > max(p , q) ---> root 往左走

// 普通二叉树上寻找两个结点(p、q)的最近公共祖先
//
// 1）p、q 相包含 (p包q or q包p)
// 2）p、q 分属于两棵子树

#include<bits/stdc++.h>

using namespace std;

typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
}TreeNode , *P;

class Ancestor_Finder
{
private:
    // root 从上到下
    P f(P root , const P& p , const P& q)
    {
        while((root!=p) && (root!=q))
        {
            // 如果 min(p , q) < root->val < max(p , q) ---> root 就是答案
            if((root->val > min(p->val , q->val)) && (root->val < max(p->val , q->val)))
            {
                return root;
            }

            // 如果 root < min(p , q) ---> root 往右走
            if(root->val < min(p->val  , q->val))
            {   
                root = root->right;
            }

            // 如果 root > max(p , q) ---> root 往左走
            if(root->val > max(p->val , q->val))
            {
                root = root->left;
            }
        }

        // 如果先遇到 p ---> p 就是答案
        // 如果先遇到 q ---> q 就是答案
        return root == p ? p : q;
    }

public:
    P Finder(P root , P p , P q)
    {
        if(root==nullptr)
        {
            return nullptr;
        }
        return f(root , p , q);
    }
};

int main()
{
    P root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    P p = root->left->left;
    P q = root->right->right;

    Ancestor_Finder af;
    P ancestor = af.Finder(root , p , q);
    printf("%d" , ancestor->val);
    return 0;
}