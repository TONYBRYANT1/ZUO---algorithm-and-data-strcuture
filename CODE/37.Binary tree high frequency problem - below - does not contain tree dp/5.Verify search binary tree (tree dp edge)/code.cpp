// 验证搜索二叉树(树型dp沾边)
//
// 验证方法：二叉树的中序遍历为升序

#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

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
    // verify1
    bool Search;
    vector<int> arr;
    // verify2
    stack<P> stk;
    // verify3
    LL maxx;
    LL minn;
private:
    void f1(const P& root)
    {
        // 呈上
        if(root == nullptr)
        {
            return;
        }

        // 主体
        f1(root->left);
        //      特判
        arr.push_back(root->val);
        if(arr.size() > 1)
        {
            if(arr[arr.size()-2] >= arr[arr.size()-1])
            {
                Search = false;
                return ;
            }
        }
        //
        f1(root->right);
    }

    void f2(P root)
    {
        // 非递归方法实现二叉树的中序遍历：
        // 1）将所有左结点入栈：
        while(root!=nullptr)
        {
            stk.push(root);
            root = root->left;
        }

        // 只要 stk 有元素，就持续的 pop 旧元素 和 push 新的元素
        while(!stk.empty())
        {
            // 将 top 元素弹出 stk，将其右侧的最外侧的所有左结点持续入栈
            P cur = stk.top();
            // 本题特性：将元素进 arr，并判断是否升序
            arr.push_back(cur->val);
            if(arr.size() > 1)
            {
                // 作比较，看看是否升序
                if(arr[arr.size()-2] >= arr[arr.size()-1])
                {
                    // 如果不满足升序，则立刻退出
                    Search = false;
                    return;
                }
            }
            cur = cur->right;
            stk.pop();

            // 将其右侧的最外侧的所有左结点持续压栈
            while(cur!=nullptr)
            {
                stk.push(cur);
                cur = cur->left;
            }
        }
    }

    // 看看当前这棵树是不是搜索二叉树
    bool f3(const P& cur)
    {
        // 呈上：
        // 当走到叶结点的左右孩子时：为了不影响判断，将 maxx = 最小，minn = 最大
        if(cur==nullptr)
        {
            minn = LONG_MAX;
            maxx = LONG_MIN;
            return true;
        }

        // 主体：
        // 1）看看左子树是否是搜索二叉树：
        bool l_ok = f3(cur->left);
        //    并刷新了左子树的最大值和最小值
        LL l_maxx = maxx;
        LL l_minn = minn;

        // 2）看看右子树是否是搜索二叉树：
        bool r_ok = f3(cur->right);
        //    并刷新了右子树的最大值和最小值
        LL r_maxx = maxx;
        LL r_minn = minn;

        // 3）总结作用：
        //    将 左子树 和 右子树 和 当前结点 得出这棵树的 最小值 和 最大值
        maxx = max(max(l_maxx , r_maxx) , (LL)cur->val);
        minn = min(min(l_minn , r_minn) , (LL)cur->val);
        
        // 启下：
        // 当 左 和 右 子树是搜索二叉树，并且 l_max < cur->val < r_min ---> 当前这棵树是搜索二叉树
        return (l_ok) && (r_ok) && (l_maxx < cur->val) && (r_minn > cur->val);
    }
public:
    // 递归方法(按递归序：先序遍历)：
    bool verify1(const P& root)
    {
        // 更新：
        Search = true;
        arr.clear();
        // 特判：
        if(root == nullptr)
        {
            return true;
        }

        // 一般情况：
        f1(root);
        return Search;
    }

    // 非递归(栈实现)：
    bool verify2(const P& root)
    {
        // 更新：
        Search = true;
        arr.clear();
        //      stk的清空：
        //          1) while pop
        while(!stk.empty())
        {
            stk.pop();
        }

        //          2）创建新的栈，倒垃圾
        // stack<int> rubbishbin;
        // stk.swap(rubbishbin);

        // 特判：
        if(root==nullptr)
        {
            return 1;
        }

        // 普通情况：
        // 检测中序遍历是否符合升序排列
        f2(root);
        return Search;
    }

    // 递归方法(按搜索二叉树性质)：
    bool verify3(const P& root)
    {
        // 更新
        Search = true;
        
        // 特判：
        if(root == nullptr)
        {
            return true;
        }

        // 一般情况：
        return f3(root);
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


    Verifier vrf;
    cout << vrf.verify3(root) << endl;
    return 0;
}