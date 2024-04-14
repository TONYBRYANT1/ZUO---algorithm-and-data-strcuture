#include<bits/stdc++.h>

using namespace std;

typedef ListNode* PL;
typedef TreeNode* PT;

class Solution 
{
private:
    // 已经确定从哪个根结点开始逐一比较，开始比较
    bool same(PL& head , PT& root)
    {
        // 恰好都为空，且一路上值都相等 ---> 说明树包含该结构的路径
        if((head==nullptr) && (root==nullptr))
        {
            return true;
        }
        // 链表走完了，且一路上值都相等 ---> 说明树包含该结构的路径
        else if((head==nullptr) && (root!=nullptr))
        {
            return true;
        }
        // 都不为空，比较一下值是否相等，再看看是走左边还是走右边
        else if((head!=nullptr) && (root!=nullptr))
        {
            return (head->val == root->val) && (same(head->next , root->left) || same(head->next , root->right));
        }
        // 树先空 ---> 说明树不包含该结构的路径
        else
        {
            return false;
        }
    }
public:
    // 树中是否包含链表结构的数值
    bool isSubPath(PL& head , PT& root) 
    {
        if((head==nullptr) && (root==nullptr))
        {
            return true;
        }
        else if((head!=nullptr) && (root!=nullptr))
        {
            // 让 链表和树的哪一部分开始作比较：
            //     现在的树根？          树根的左孩子？                    树根的右孩子？          
            return same(head , root) || isSubPath(head , root->left) || isSubPath(head , root->right); 
        }
        else 
        {
            return false;
        }
    }
};