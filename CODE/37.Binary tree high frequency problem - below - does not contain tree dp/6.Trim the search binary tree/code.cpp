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

class Trimmer
{
private:
    int low , high;    
    int l , r;
    P que[N];
    vector<vector<int>> ans;
    vector<int> list;

private:
    P f1(const P& cur)
    {
        // 呈上：
        if(cur==nullptr)
        {
            return nullptr;
        }

        // 主体：
        // 1）cur->val < low
        if(cur->val < low)
        {
            return f1(cur->right);
        }
        // 2）cur->val > high
        if(cur->val > high)
        {
            return f1(cur->left);
        }
        // 3）low <= cur->val <= high
        cur->left = f1(cur->left);
        cur->right = f1(cur->right);

        // 启下：
        return cur;
    }

    void f2(const P& cur)
    {
        l = 0 , r = 0;
        int size=0;
        ans.clear();
        list.clear();

        que[r++] = cur;

        while(l<r)
        {
            size = r-l;
            while(size--)
            {
                P cur = que[l++];
                list.push_back(cur->val);
                if(cur->left!=nullptr)
                {
                    que[r++] = cur->left;
                }

                if(cur->right!=nullptr)
                {
                    que[r++] = cur->right;
                }
            }

            ans.push_back(list);
            list.clear();
        }
    }
public:
    P trim(const P& root , int low , int high)
    {
        this->low = low;
        this->high = high;
        if(root==nullptr)
        {
            return nullptr;
        }
        else
        {
            return f1(root);
        }
    }

    void Print_Tree_By_Layer(const P& cur)
    {
        f2(cur);
        for(const auto& e : ans)
        {
            for(const auto& c : e)
            {
                printf("%d " , c);
            }
            printf("\n");
        }
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

    Trimmer tmr;
    tmr.Print_Tree_By_Layer(tmr.trim(root , 0 , 9));
    return 0;
}