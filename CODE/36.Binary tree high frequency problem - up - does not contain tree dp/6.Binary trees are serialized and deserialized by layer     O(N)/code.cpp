// 二叉树按层序列化和反序列化

#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+10;

typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
}TreeNode , *P;

// 编码解码器：
class Codec
{
private:
    P que[N];
    size_t l=0 , r=0 , index=0; // 跳转答案容器内容;

private:
    string f(const P& root)
    {
        // 0）特判：
        if(root == nullptr)
        {
            return "#,";
        }

        // 2）更新：
        l=0 , r=0;
        string ans; // 每个元素入队时记录答案
        ans.clear();

        // 1）现将 root 放进 que 并 更新 ans
        que[r++] = root;
        ans.append(to_string(root->val) + ","); // "a,"

        // 2）只要队中有元素，就出队，并入队左右孩子 (入队时记录答案)
        while(l<r)
        {
            P cur = que[l++]; // 出队当前队头结点
            
            // 左孩子：
            if(cur->left != nullptr)
            {
                que[r++] = cur->left;
                ans.append(to_string(cur->left->val) + ",");
            }
            else
            {
                ans.append("#,");
            }

            // 右孩子：
            if(cur->right != nullptr)
            {
                que[r++] = cur->right;
                ans.append(to_string(cur->right->val) + ",");
            }
            else
            {
                ans.append("#,");
            }
        }

        return ans;
    }

    vector<string> split(const string& str , const char& delimiter)
    {
        vector<string> ans;
        size_t start = 0 , end = 0;
        while((end = str.find(delimiter , start)) != string::npos)
        {
            string substrr = str.substr(start , end-start);
            ans.push_back(substrr);
            start = end+1;
        }

        // 最后一部分：
        ans.push_back(str.substr(start));

        return ans;
    }

    P g(vector<string> ans)
    {
        // 0）特判：
        if(ans[index++] == "#")
        {
            return nullptr;
        }

        // 1）更新：
        l=0 , r=0 , index=0;
        P root = nullptr;
        root = new TreeNode(stoi(ans[index++]));

        // 2）将 root 入队
        que[r++] = root;

        // 3）只要有元素，出队时直接创造左右孩子，如果孩子不为空，则入队
        while(l<r)
        {
            // 出队：
            P root = que[l++];
            
            // 创造左孩子：如果左孩子不为空，则入队
            if(ans[index] != "#")
            {
                root->left = new TreeNode(stoi(ans[index++]));
                que[r++] = root->left;
            }
            else
            {
                index++;
            }

            // 创造右孩子：如果右孩子不为空，则入队
            if(ans[index] != "#")
            {
                root->right = new TreeNode(stoi(ans[index++]));
                que[r++] = root->right;
            }
            else
            {
                index++;
            }
        }

        return root;
    }

public: 
    string serialize(const P& root)
    {   
        string str;
        str = f(root);
        return str.substr(0 , str.size()-1);
    }

    P deserialize(const string& str)
    {
        vector<string> ans = split(str , ',');
        return g(ans);
    }
};

int main()
{
    P root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    string str = codec.serialize(root);
    cout << str << endl;

    P root2 = codec.deserialize(str);
    cout << root2->val << endl;
    cout << root2->left->val << endl;
    cout << root2->right->val << endl;
    cout << root2->right->left->val << endl;
    cout << root2->right->right->val << endl;

    return 0;
}