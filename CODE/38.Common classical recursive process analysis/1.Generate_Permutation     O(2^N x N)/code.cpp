// 1.Generate_Permutation
// 要求顺序，并看每个元素出不出现
//
// 返回字符串全部子序列，子序列要求去重。时间复杂度O(2^n * n)
//
// 方法：递归 + 恢复现场

#include<bits/stdc++.h>

using namespace std;

typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
}TreeNode , *P;

class Permutation 
{
private:
    vector<string> ans;
    int size;
    string str;
    string path;
    char arr[20];
    int pointer;
    unordered_set<string> list;

private: 

    // 先加后不加(不会出现问题)，用string解决问题
    void f1(int i)
    {
        // 呈上：
        // 当遍历完 str 的元素时，添加答案 并 退出
        if(i==size)
        {
            ans.push_back(path);
            return;
        }

        // 主体：当前到了 i 位置
        // 1）选择添加 i 位置的字符 并送往下一个字符：
        path.append(1 , str[i]);
        f1(i+1);

        // 2）选择不添加 i 位置的字符 并送往下一个字符：
        // 恢复现场：
        path.pop_back(); // 这里不要用 path.erase(1 , str[i]) ---> 会因为错位导致错误
        f1(i+1);

        return;
    }
    
    // 先不加后加
    void f2(int i)
    {
        // 呈上：
        // 当遍历完 str 的元素时，添加答案 并 退出
        if(i==size)
        {
            ans.push_back(path);
            return;
        }

        // 先不添加：
        f2(i+1);
        // 再走添加：
        path.append(1 , str[i]);
        f2(i+1);

        return;
    }

    // 先加后不加(会出现问题)，用数组解决问题：
    void f3(int i , int pointer)
    {
        // 呈上：
        if(i == size)
        {   
            // pointer --- 要添加几个元素，同时也作为指针，严格控制元素的加减
            string a(arr , pointer); 
            ans.push_back(a); 
            return;
        }

        // 主体：
        // 添加 i 位置的元素
        arr[pointer++] = str[i];
        f3(i+1 , pointer);
        // 不添加 i 位置的元素
        f3(i+1 , pointer-1); // 覆盖元素

        // 启下：
        return;
    }
    
    void Remove_Duplication()
    {
        for(const auto& e : ans)
        {
            list.insert(e);
        }
        ans.clear();
        for(const auto& e : list)
        {
            ans.push_back(e);
        }
    }

public:
    // f1、f2 公用 generatePermutation1
    vector<string> generatePermutation1(string s)
    {
        // 更新：
        size = s.size();
        ans.clear();
        str = s;

        // 特判：
        if(size==0)
        {
            string a = "";
            ans.push_back(a);
            return ans;
        }   

        // 返回答案：
        // f1(0); ---> 先加后不加(不会出现问题)
        // f2(0); ---> 先不加后加(会出现问题)
        f1(0);
        // 去重：
        Remove_Duplication();
        return ans;
    }

    // f3 用 generatePermutation2
    vector<string> generatePermutation2(string s)
    {
        // 更新：
        size = s.size();
        ans.clear();
        pointer = 0;
        str = s;

        // 特判：
        if(size == 0)
        {
            string a = "";
            ans.push_back(a);
            return ans;
        }

        f3(0 , pointer); // 参1：扫描到 str 的第几位了  参2：pointer指向了第几位
        // 去重：
        Remove_Duplication();
        return ans;
    }
};


int main()
{
    string a;
    a.append("aabaac");
    Permutation pmtt;
    vector<string>arr = pmtt.generatePermutation2(a);
    for(const auto& e : arr)
    {
        cout << e << endl;
    }
    cout << arr.size() << endl;
    return 0;
}
