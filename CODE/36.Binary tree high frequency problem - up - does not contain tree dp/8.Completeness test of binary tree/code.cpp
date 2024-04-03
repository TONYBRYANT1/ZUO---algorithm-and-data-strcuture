// 检验二叉树的完全性
// 
// 1）完全性：
//          1）除了最后一层之外其他层全满
//          2）最后一层的所有结点全靠左
// 
// 2）完全性的检验：
//          1）结点要么左右孩子全有，要么有左没右边 (出现有又没左 ==> false)
//          2）bfs(breadth first search) 当出现孩子不全的情况时 ==> 剩下的所有结点都是叶结点

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
    P que[110];
    int l=0 , r=0;

private:
    bool f(const P& root)
    {
        // 0）更新：
        l = 0 , r = 0;
        bool vrf = false; // 是否发现有孩子不全的结点

        // 1）空树算完全：
        if(root==nullptr)
        {
            return true;
        }

        // 2）将 root 入队
        que[r++] = root;

        // 3）层序遍历 二叉树
        while(l<r)
        {  
            // 出队：
            P cur = que[l++];
            
            // 发现该结点有右孩子，没有左孩子
            if((cur->right != nullptr) && (cur->left == nullptr))
            {
                return false;
            }

            // 出现不全结点后，后面的结点 不是 叶结点   
            // 叶结点(左右都空) ==> 但凡有一个孩子不空就不是叶结点
            // 后置条件 ==> 
            if((vrf == true) && ((cur->left!=nullptr)||(cur->right!=nullptr)))
            {
                return false;
            }            

            // 左孩子入队：
            if(cur->left != nullptr)
            {
                que[r++] = cur->left;
            }

            // 右孩子入队：
            if(cur->right != nullptr)
            {
                que[r++] = cur->right;
            }

            // 出现不全结点：
            if((cur->left==nullptr) || (cur->right==nullptr))
            {
                vrf = true;
            }
        }   

        return true;
    }

public:
    bool verify(P root)
    {
        return f(root);
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
    root->right->left = new TreeNode(7);

    Verifier vrfr;
    printf("该二叉树是否为完全二叉树：%d（1-是/0-不是）" , vrfr.verify(root));
    return 0;
}