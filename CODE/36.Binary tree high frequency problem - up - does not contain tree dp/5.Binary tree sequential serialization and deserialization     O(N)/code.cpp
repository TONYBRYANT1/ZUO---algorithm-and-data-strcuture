// 二叉树的先序序列化

#include<bits/stdc++.h>

using namespace std;

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
public: 
    size_t countt=0;

public:
    void f(const P& root , string& str)
    {
        if(root == nullptr)
        {
            str.append("#,");
            return;
        }

        str.append(to_string(root->val)+",");
        
        f(root->left , str);

        f(root->right , str);
    }

    vector<string> split(const string& str , const char& delimiter)
    {
        vector<string> ans;
        size_t start = 0 , end = 0;
        while((end = str.find(delimiter , start)) != string::npos)
        {
            // 截取字符串
            string substrr = str.substr(start , end-start); // substr(start , end-1-start+1)
            // 添加到答案中去
            ans.push_back(substrr); 
            // 更新 start
            start = end+1;
        }

        // 最后一段
        ans.push_back(str.substr(start));

        return ans;
    }

    P g(const vector<string>& ans , P& root)
    {
        string cur = ans[countt++];
        
        if(cur == "#")
        {
            return nullptr;
        }

        root = new TreeNode(stoi(cur));

        g(ans , root->left);

        g(ans , root->right);

        return root;
    }

public:
    Codec() {}

    string serialize(const P& root)
    {
        string str;
        f(root , str);
        // 去掉末尾的","
        str = str.substr(0 , str.size()-1);
        return str;
    }

    P deserialize(const string& str)
    {
        vector<string> ans = split(str , ',');
        countt = 0;
        P root = nullptr;
        return g(ans , root);
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

    // str = codec.split(str , ',');
    // cout << str << endl;
    return 0;
}