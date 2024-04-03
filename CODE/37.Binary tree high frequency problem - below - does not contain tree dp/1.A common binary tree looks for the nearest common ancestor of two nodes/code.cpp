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
    // 原 f() --> 安全性不高，不能保证都有返回值(其实每种情况都包括了)
    // P f(const P& root , const P& p , const P& q)
    // {   
    //     // 1）呈上
    //     //      1）找到p、q or 为空 return root：
    //     if((root==p) || (root==q) || (root==nullptr))
    //     {
    //         return root;
    //     }
    //
    //     // 2）主体
    //     //      1）左右子树搜索 p、q：
    //     P l = f(root->left , p , q);
    //     P r = f(root->right , p , q);
    //
    //     // 3）启下
    //     //      1）左右子树都没找到：return nullptr;
    //     if((l==nullptr) && (r==nullptr))
    //     {
    //         return nullptr;
    //     }
    //     //      2）左右子树找到一个：返回找到的那一个 return l or r;
    //     //          可能情况：
    //     //              1）p、q 相包含 (p包q or q包p)
    //     //              2）p、q 分属于两棵子树
    //     if((l!=nullptr)&&(r==nullptr))
    //     {
    //         return l;
    //     }
    //     if((r!=nullptr)&&(l==nullptr))
    //     {
    //         return r;
    //     }
    //
    //     //      3）左右子树都找到了：return root;
    //     if((r!=nullptr)&&(l!=nullptr))
    //     {
    //         return root;
    //     }
    //
    //      return nullptr // 为了满足什么情况下都有返回值，临时添加(没用，只是为了过编译)
    //
    // }

    // 优化f()' ---> 比 f() 少了判断，而且不管怎样都有返回值
    P f(const P& root , const P& p , const P& q)
    {   
        // 1）呈上
        //      1）找到p、q or 为空 return root：
        if((root==p) || (root==q) || (root==nullptr))
        {
            return root;
        }

        // 2）主体
        //      1）左右子树搜索 p、q：
        P l = f(root->left , p , q);
        P r = f(root->right , p , q);

        // 3）启下
        //      1）左右子树都没找到：return nullptr;
        if((l==nullptr) && (r==nullptr))
        {
            return nullptr;
        }
        
        //      2）左右子树都找到了：return root;
        if((r!=nullptr)&&(l!=nullptr))
        {
            return root;
        }
        
        //      3）左右子树找到一个：返回找到的那一个 return l or r;
        //          可能情况：
        //              1）p、q 相包含 (p包q or q包p)
        //              2）p、q 分属于两棵子树
        return l==nullptr ? r : l;
    }
public:
    P Finder(P root , P p , P q)
    {
        return f(root , p , q);
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
    root->right->right = new TreeNode(7);

    P p = root->left->left;
    P q = root->left->right;

    Ancestor_Finder af;
    P ancestor = af.Finder(root , p , q);
    printf("%d" , ancestor->val);
    return 0;
}