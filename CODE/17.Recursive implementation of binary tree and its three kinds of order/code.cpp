// 二叉树的三种序

//                      1
//                2           3
//             4     5     6     7

// 1) 先序：对于任何一棵子树 按照 中 左 右 的顺序遍历 如：1 2 4 5 3 6 7
// 2) 中序：对于任何一棵子树 按照 左 中 右 的顺序遍历 如：4 2 5 1 6 3 7
// 3) 后序：对于任何一棵子树 按照 左 右 中 的顺序遍历 如：4 5 2 6 7 3 1

#include<bits/stdc++.h>

using namespace std;

typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode() {}
}TreeNode , *PTN;

// 递归基本的样子，用来理解递归序
// 递归序：1[1] 2[1] 4[1] 4[2] 4[3] 2[2] 5[1] 5[1] 5[1] 2[3] 1[2] 3[1] 6[1] 6[2] 6[3] 3[2] 7[1] 7[2] 7[3] 3[3] 1[3]
void Tree_Recursive(PTN H)
{
    if(H == NULL)
    {
        return;
    }
    
    // 1 第一次碰到数 --> 前序遍历 中 左 右
    Tree_Recursive(H->left);
    // 2 第二次碰到数 --> 中序遍历 左 中 右
    Tree_Recursive(H->right);
    // 3 第三次碰到数 --> 后序遍历 左 右 中
}

void Tree_PreOrder_Traversal(PTN H)
{
    if(H==NULL)
    {
        return;
    }

    printf("%d " , H->val);
    Tree_PreOrder_Traversal(H->left);
    Tree_PreOrder_Traversal(H->right);
}

void Tree_MidOrder_Traversal(PTN H)
{
    if(H==NULL)
    {
        return;
    }

    Tree_MidOrder_Traversal(H->left);
    printf("%d " , H->val);
    Tree_MidOrder_Traversal(H->right);
}

void Tree_PostOrder_Traversal(PTN H)
{
    if(H==NULL)
    {
        return;
    }

    Tree_PostOrder_Traversal(H->left);
    Tree_PostOrder_Traversal(H->right);
    printf("%d " , H->val);
}

void InitTree(PTN& H)
{
    H = new TreeNode;
    int x;
    scanf("%d" , &x);
    H->val = x;
    H->left = NULL;
    H->right = NULL;
}

void CreateTree_Left(PTN& H)
{
    PTN P = new TreeNode;
    int x=0;
    scanf("%d" , &x);
    P->val = x;
    P->left = NULL;
    P->right = NULL;
    H->left = P;
}

void CreateTree_Right(PTN& H)
{
    PTN P = new TreeNode;
    int x=0;
    scanf("%d" , &x);
    P->val = x;
    P->left = NULL;
    P->right = NULL;
    H->right = P;
}

int main()
{
    PTN root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Tree_PreOrder_Traversal(root);

    return 0;
}