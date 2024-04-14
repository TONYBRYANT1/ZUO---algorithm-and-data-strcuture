#include<bits/stdc++.h>

using namespace std;

typedef struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}TreeNode , *P;

class Solution 
{
private:
    bool same(const P& t1 , const P& t2)
    {
        if((t1==nullptr) && (t2==nullptr))
        {
            return true;
        }
        else if((t1!=nullptr) && (t2!=nullptr))
        {
            return t1->val == t2->val && same(t1->left , t2->left) && same(t1->right , t2->right);
        }
        else
        {
            return false;
        }
    }

public:
    bool isSubtree(P root , P subRoot) 
    {
        // 四种情况：
        // 1）root == nullptr && subroot == nullptr
        // return true;
        //
        // 2）root == nullptr && subroot != nullptr
        // return false;
        //
        // 3）root != nullptr && subroot == nullptr
        // return false;
        //
        // 4）root != nullptr && subroot != nullptr
        // 讨论

        if((root==nullptr) && (subRoot==nullptr))
        {
            return true;
        }
        else if((root!=nullptr) && (subRoot!=nullptr))
        {
            return same(root , subRoot) || isSubtree(root->left , subRoot) || isSubtree(root->right , subRoot);
        }
        else
        {
            return false;
        }
    }
};