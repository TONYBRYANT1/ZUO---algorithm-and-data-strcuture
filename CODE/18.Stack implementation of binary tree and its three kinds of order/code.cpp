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
}TreeNode , *PTN;

// 先序：中 左 右
// 1) 创造以二叉树指针为元素的栈 stk
// 2) 先将二叉树根结点放在 stk 中
// 3）然后弹出top，然后先搜索根结点的右结点，再搜索左结点，如果有 非nullptr 的结点，就放入 stk
// 4) 然后以 stk 的 新top 作为 新根结点，如此往复
void PreOrder(PTN H)
{
    if(H != nullptr)
    {
        // 用栈存储数节点指针
        stack<PTN> stk;
        stk.push(H);
        while(!stk.empty())
        {
            H = stk.top();
            printf("%d " , H->val);
            stk.pop(); 

            // 要想从右到左，先要从左到右
            if(H->right != nullptr)
            {
                stk.push(H->right);
            }
            if(H->left != nullptr)
            {
                stk.push(H->left);
            }
        }
        printf("\n");
    }
}

// 中序：左 中 右 (对于树和子树的根节点，先处理完所有左数，在处理自己，在处理右数)
// 1) 先以根节点及其所有左结点放入 stk
// 2) 弹出top，以弹出的top 为新根结点重复 1)
void MidOrder1(PTN H)
{
    if(H == nullptr)
    {
        return;
    }
    else
    {
        stack<PTN> stk;
        // 一直重复将左数入栈，直到最底层的根结点没有左数需要处理，在开始处理自己
        while(H != nullptr)
        {
            stk.push(H);
            H = H->left;
        }

        // 开始处理自己
        while(!stk.empty())
        {
            printf("%d " , stk.top()->val);
            // 处理右数
            H = stk.top()->right;
            stk.pop();

            // 以右数作为新的根结点继续处理左数
            while(H!=nullptr)
            {
                stk.push(H);
                H = H->left;
            }
        }
    }
    printf("\n");
}

void MidOrder2(PTN H)
{
    if(H == nullptr)
    {
        return;
    }
    else
    {
        stack<PTN> stk;
        while(!stk.empty() || H!=nullptr)
        {
            if(H!=nullptr)
            {
                stk.push(H);
                H = H->left;
            }
            else
            {
                H = stk.top()->right;
                printf("%d " , stk.top()->val);
                stk.pop();
            }
        }
    }
    printf("\n");
}

// 哨兵方法
void EndOrder_single_stack(PTN H)
{
    if (H != nullptr) 
    {
        stack<PTN> stk;
        stk.push(H);
        // 如果始终没有打印过节点，H就一直是头节点
        // 一旦打印过节点，H就变成打印节点
        // 之后H的含义 : 上一次打印的节点
        while (!stk.empty()) 
        {
            PTN cur = stk.top();
            if (cur->left != nullptr && H != cur->left && H != cur->right) 
            {
                // 有左树且左树没处理过
                stk.push(cur->left);
            } 
            else if (cur->right != nullptr && H != cur->right) 
            {
                // 有右树且右树没处理过
                stk.push(cur->right);
            } 
            else 
            {
                // 左树、右树 没有 或者 都处理过了
                printf("%d " , cur->val);
                H = stk.top();
                stk.pop();
            }
        }
        printf("\n");
    }
}

// 后序：左 右 中
// 先序：中 左 右 --(左 右 调换)--> 中 右 左 --(入栈)--> 左 右 中(后序)
void EndOrder_double_stack(PTN H)
{
    if(H == nullptr)
    {
        return;
    }
    else
    {
        stack<PTN> stk , tool_stk;
        stk.push(H);
        while(!stk.empty())
        {
            H = stk.top();
            tool_stk.push(stk.top());
            stk.pop();
            if(H->left != nullptr)
            {
                stk.push(H->left);
            }
            if(H->right != nullptr)
            {
                stk.push(H->right);
            }
        }

        while(!tool_stk.empty())
        {
            printf("%d " , tool_stk.top()->val);
            tool_stk.pop();
        }
        printf("\n");
    }
}
int main()
{
    PTN H = new TreeNode(1);
    H->left = new TreeNode(2);
    H->right = new TreeNode(3);
    H->left->left = new TreeNode(4);
    H->left->right = new TreeNode(5);
    H->right->left = new TreeNode(6);
    H->right->right = new TreeNode(7);
    // PreOrder(H);
    MidOrder1(H);
    // MidOrder2(H);
    // EndOrder_double_stack(H);
    // EndOrder_single_stack(H);
    return 0;
}