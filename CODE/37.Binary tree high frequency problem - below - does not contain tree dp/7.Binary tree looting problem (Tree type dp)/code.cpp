// 二叉树打家劫舍问题(树型dp沾边)
//
// 修剪搜索二叉树
// [low , high]
//
// 方法：
// 1）当 cur->val < low：自己 和 自己的左子树 都不能要了，去修剪右子树
// 2）当 cur->val > high：自己 和 自己的右子树 都不能要了，去修建左子树
// 3）当 low <= cur->val <= high：链接左右两边
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 1e4+10;

typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
}TreeNode , *P;

class Rob
{
private:
    int y , n;

private:
    void f(const P& cur)
    {
        // 一）呈上：
        // 到叶结点的左右孩子
        if(cur==nullptr)
        {
            y = 0;
            n = 0;
            return;
        }

        // 二）普通情况：
        //      对于 cur 来说有两种情况：
        //          1）偷cur：偷了cur，就不能偷 左子树树根 和 右子树树根
        //             总收益：Y(cur) + N(左) + N(右)
        //          2）不偷cur：不偷cur，左右子树树根可偷可不偷，关键看利益最大化
        //             总收益：N(cur) + max( Y(左),N(左) ）+ max( Y(右),N(右) )
        //
        // 1）先判断 cur  收益 Y(cur) & N(cur)
        int cur_y = cur->val; // cur_y ---> Y(cur)
        int cur_n = 0; // cur_n ---> N(cur)

        // 2）再判断 左子树 收益 ：Y(左) & N(左)
        f(cur->left); // y - Y(左) / n - N(左)
        cur_y += n;
        cur_n += max(y , n);

        // 3）再判断 右子树 收益 ：Y(右) & N(右)
        f(cur->right); // y - Y(右) / n - N(右)
        cur_y += n;
        cur_n += max(y , n);

        // 4）最后更新 cur 偷与不偷的总收益：Y(总) / N(总)
        y = cur_y;
        n = cur_n;

        // 三）启下：
        return;
    }

public:
    int rob(const P& root)
    {
        y=0 , n=0;
        if(root == nullptr)
        {
            return 0;
        }

        f(root); 
        // 此时的 y ---> 偷root的最大收益
        // 此时的 n ---> 不偷root的最大收益
        return max(y , n);
    }
};

int main()
{

    P root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    Rob rb;
    printf("%d" , rb.rob(root));

    return 0;
}