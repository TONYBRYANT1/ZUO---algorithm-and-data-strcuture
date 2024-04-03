// 验证平衡二叉树(树型dp沾边)

#include<bits/stdc++.h>

using namespace std;

typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
}TreeNode , *P;

class Verifier
{
private:
    bool Balance;

private:
    // 求树的最大高度 + 平衡二叉树特判
    int f(const P& root)
    {
        // 呈上：
        if(root==nullptr)
        {
            return 0;
        }

        // 主体：
        int lh = f(root->left);
        int rh = f(root->right);
        //      平衡二叉树的特判：发现左右子树高度相差大于等于1
        if(abs(lh-rh)>1)
        {
            Balance = false;
            return 666; // 并不在乎
        }

        // 启下：
        return max(lh , rh) + 1;
    }

public:
    bool verify(const P& root)
    {
        // 0）更新：
        Balance = true;

        // 1）特判：
        if(root==nullptr)
        {
            return true;
        }
        // 2）一般情况：
        else
        {
            f(root);
            return Balance;
        }
    }
};

int main() 
{
    // P root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(2);
    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(3);
    // root->left->left->left = new TreeNode(4);
    // root->left->left->right = new TreeNode(4);

    P root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Verifier vrf;
    cout << vrf.verify(root) << endl;;
    return 0;
}