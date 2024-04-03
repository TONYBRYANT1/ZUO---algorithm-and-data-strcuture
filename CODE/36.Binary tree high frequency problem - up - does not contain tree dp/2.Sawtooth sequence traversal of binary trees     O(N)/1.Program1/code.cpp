// 二叉树的锯齿形层序遍历：

// 方法一：收集完一层之后将其 reverse，在加到答案中
// 在 二叉树的层序遍历 的第二种方法基础上，当收集完一层的数据后reverse

// 树的层序遍历：
//
// 方法二：每一次处理一层数据
// 1）自定义队列
// 2）每次获得一个size
// 3）队列弹出数据size遍，每次弹出加入左右孩子(先加左孩子，再加有孩子)

#include<bits/stdc++.h>

using namespace std;

typedef struct TreeNode
{
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : value(x) , left(nullptr) , right(nullptr) {}
}TreeNode , *P;

P arr[2010];
int l , r , sizee;
bool reversee = true; // 正常遍历，不需要reverse

// 树的层序遍历：
vector<vector<int>> Tree_Sawtooth_travel(P H)
{
    // 0）用到的容器：
    vector<vector<int>> ans;
    vector<int> list;        

    // 1）特判：
    if(H == nullptr)
    {
        return ans;
    }

    // 2）更新队列：
    l = r = 0;

    // 3）添加根结点：
    arr[r] = H;
    r++;

    // 4）开始循环，先获取 sizee，然后执行 sizee 遍
    while(l<r) // l==r 默认队列为空
    {      
        // 每一次处理树的一层结点
        //      
        // 清空 list
        list.clear();
        // 获得sizee
        sizee = r-l;
        // 进行 sizee 遍
        while(sizee--)
        {
            // 出队
            P cur = arr[l];
            l++;
            // 记录该层答案：
            list.push_back(cur->value);
            // 左孩子入队：
            if(cur->left != nullptr)
            {
                arr[r] = cur->left;
                r++;
            }
            // 右孩子入队：
            if(cur->right != nullptr)
            {
                arr[r] = cur->right;
                r++;
            }
        }

        // 要不要翻转该层数据：
        if(reversee == false)
        {
            reverse(list.begin() , list.end());
        }
        // 更新 ans
        ans.push_back(list);
        // 更新 reversee
        reversee = !reversee;
    }
    
    return ans;
}

int main()
{
    P H = new TreeNode(1);
    H->left = new TreeNode(2);
    H->right = new TreeNode(3);
    H->left->left = new TreeNode(4);
    H->right->right = new TreeNode(5);

    vector<vector<int>> ans = Tree_Sawtooth_travel(H);

    for(const auto& e1 : ans)
    {
        for(const auto& e2 : e1)
        {
            printf("%d " , e2);
        }
        printf("\n");
    }
    
    return 0;
}