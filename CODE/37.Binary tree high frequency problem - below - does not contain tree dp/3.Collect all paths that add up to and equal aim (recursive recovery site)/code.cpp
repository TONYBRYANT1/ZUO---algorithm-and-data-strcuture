// 收集累加和等于aim的所有路径(递归恢复现场)
#include<bits/stdc++.h>

using namespace std;

typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
}TreeNode , *P;

class Pass_Aim
{
private:
    vector<vector<int>> Ans;
    vector<int> Path;
    int Aim;

private:
    void Renew_Ans(const P& root)
    {
        // 创建临时结点：
        vector<int> List;
        for(const auto& e : Path)
        {
            List.push_back(e);
        }
        List.push_back(root->val);

        // 更新 Ans
        Ans.push_back(List);

    }

    void f(const P& root , const int& sum) // sum - 当前结点之前的路径和
    {
        // 0）特判：叶结点
        if((root->left==nullptr)&&(root->right==nullptr))
        {
            // 看看加上叶结点之后能不能等于 Aim
            if((sum+root->val) == Aim)
            {
                // 更新答案：
                Renew_Ans(root);
            }
        }
        // 1）中间结点：
        else
        {
            // 在 Path 中加入当前结点：
            Path.push_back(root->val);

            // 继续往下走：
            if(root->left!=nullptr)
            {
                f(root->left , sum+root->val);
            }
            if(root->right!=nullptr)
            {
                f(root->right , sum+root->val);
            }

            // 包含当前结点的路径试完了，要回复成上一个结点的现场
            Path.pop_back();
        }
    }

public:
    vector<vector<int>> Pass(P root , int Aim)
    {
        // 0）更新：
        Ans.clear();
        Path.clear();
        this->Aim = Aim;

        // 1）特判：
        if(root==nullptr)
        {
            return Ans;
        }
        else
        {
            f(root , 0);
            return Ans;
        }
    }
};

int main()
{
    P root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Pass_Aim pa;
    vector<vector<int>> ans = pa.Pass(root , 22);
    for(const auto& e : ans)
    {
        for(const auto& c : e)
        {
            printf("%d " , c);
        }
        cout << endl;
    }

    return 0;
}