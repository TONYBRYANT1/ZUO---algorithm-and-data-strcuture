// 二叉树最大宽度：
//
// 方法：
// 1）将 结点 和 下标 分别存储：iq[]、vq[]
// 2）按照 层序遍历 每次处理一层
#include<bits/stdc++.h>

using namespace std;

typedef struct TreeNode
{
    unsigned long long value;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(unsigned long long x) : value(x) , left(nullptr) , right(nullptr) {}
}TreeNode , *P;

P vq[3010];
unsigned long long iq[3010];

unsigned long long l , r;

unsigned long long Tree_Max_width(P H)
{
    // 0）特判：
    if(H == nullptr)
    {
        return 0;
    }

    // 1）更新：
    unsigned long long sizee = 0;
    unsigned long long ans = 0;
    l = r = 0;

    // 2）添加根结点：
    vq[r] = H;
    iq[r] = 1;
    r++;

    while(l<r)
    {
        // 1）获取当前层的size , 并更新最大值：
        sizee = (r-1) - l + 1;
        ans = max(ans , iq[r-1] - iq[l] + 1);

        // 2）依次弹出 并 入队：
        while(sizee--)
        {
            // 弹出：
            P cur = vq[l];
            unsigned long long index = iq[l];
            l++;

            // 入队：
            // 左孩子入队：
            if(cur->left != nullptr)
            {
                vq[r] = cur->left;
                iq[r] = index*2;
                r++;
            }
            // 右孩子入队：
            if(cur->right != nullptr)
            {
                vq[r] = cur->right;
                iq[r] = (index*2)+1;
                r++;
            }
        }
    }
    return ans;
}

unsigned long long main()
{
    P H = new TreeNode(1);
    H->left = new TreeNode(2);
    H->right = new TreeNode(3);
    H->left->left = new TreeNode(4);
    H->right->right = new TreeNode(5); 

    unsigned long long ans = Tree_Max_width(H);
    printf("%d" , ans);   

    return 0;
}