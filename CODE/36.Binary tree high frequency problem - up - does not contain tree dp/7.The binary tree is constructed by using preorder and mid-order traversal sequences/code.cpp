// 用递归构建左子树 右子树
// 建立过程主要是依靠先序遍历来创造结点
// 但是为了确定具体的根结点和子根节点，我们需要比对中序遍历来确定是哪个结点

// 在递归的调用中，记得用&，来提高代码的效率

#include<bits/stdc++.h>

using namespace std;

const int N = 3010;

typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
}TreeNode , *P;

class TreeBuilder
{
private:
    int size;
    vector<int> pot; // PreOrdered_Traversal
    vector<int> iot; // InOrdered_Traversal
    unordered_map<int , int> HashMap; // InOrdered_Traversal_Map
private:
    P f(const vector<int>& pot , int l1 , int r1 , const vector<int>& iot , int l2 , int r2 , unordered_map<int , int>& HashMap)
    {
        // 1）大小不一：
        if((l1>r1) || (l2>r2) || ((r1-l1)!=(r2-l2)))
        {
            return nullptr;
        }

        // 2）建 root 
        P root = new TreeNode(pot[l1]);

        // 3）只有 root 没有左右子树
        if(l1==r1)
        {
            return root;
        }

        // 4）建子树
        int cur = HashMap[pot[l1]];

        root->left = f(pot , l1+1 , l1+cur-l2 , iot , l2 , cur-1 , HashMap);
        root->right = f(pot , l1+cur-l2+1 , r1 , iot , cur+1 , r2 , HashMap);

        return root;
    }

public:
    P Build_Tree(const int* pott , const int* iott , int n) // 数组
    {
        // 1）更新 pot , iot , size
        size = n;
        pot.clear();
        for(int i=0 ; i<size ; i++)
        {
            pot.push_back(pott[i]);
        }
        iot.clear();
        for(int i=0 ; i<size ; i++)
        {
            iot.push_back(iott[i]);
        }

        // 2）特判：如果先序和中序的大小不同 或者 为零，则树不存在
        if((pot.size()!=iot.size()) || (pot.size()==0 || iot.size()==0))
        {
            return nullptr;
        }

        // 3）将 iot 中的数据进 HashMap 表，方便查找
        int i=0;
        for(const auto& e : iot)
        {
            HashMap[e] = i++;
        }

        // 4）开始建树
        P root = f(pot , 0 , pot.size()-1 , iot , 0 , iot.size()-1 , HashMap);
        return root;
    }
};

int main()
{
    // 0）添加 先序 中序 的 数组
    int n = 5;
    int pot[N] = {3 , 9 , 20 , 15 , 7};
    int iot[N] = {9 , 3 , 15 , 20 , 7};

    TreeBuilder tb;
    P root = tb.Build_Tree(pot , iot , n);
    cout << root->val << endl;
    cout << root->left->val << endl;
    cout << root->right->val << endl;
    cout << root->right->left->val << endl;
    cout << root->right->right->val << endl;
    return 0;
}