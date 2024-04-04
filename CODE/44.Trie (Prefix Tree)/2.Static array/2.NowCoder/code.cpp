#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;  // 结点总出现数

int cnt; // 当前结点(第几个结点)
int Tree[N][26]; // 结点路径记录表
int pass[N]; // 该结点的通过数
int endd[N]; // 该结点作为末尾数

// 单词插入:
void word_insert(string word)
{
    int tool=1; // 遍历工具 - 从第 1 个结点开始
    int path=0; // 路径记录

    pass[tool]++; // 第一个结点通过数++

    // 遍历单词 从第二个结点开始记录
    for(const auto& c : word) // 第 1 & 2 结点之间的路径表示单词的第一个字母
    {
        path = c - 'a';  // 第 1 & 2 结点之间的路径

        // 没有该结点:
        if(Tree[tool][path]==0)
        {
            // 添加结点:
            Tree[tool][path] = ++cnt;
            
            // 遍历工具访问下一结点，结点通过数++
            tool = Tree[tool][path];
            pass[tool]++;
        }
        // 有对应结点:
        else
        {
            // 遍历工具访问下一结点，结点通过数++
            tool = Tree[tool][path];
            pass[tool]++;
        }
    }

    // 结点作为末尾数++
    endd[tool]++;
    return;
}   

// 单词查重:
int word_duplicate(string word)
{
    int tool=1; // 遍历工具 - 从第 1 个结点开始
    int path=0; // 路径记录

    // 遍历单词 从第二个结点开始记录
    for(const auto& c : word) // 第 1 & 2 结点之间的路径表示单词的第一个字母
    {
        path = c - 'a';  // 第 1 & 2 结点之间的路径

        // 没有该结点:
        if(Tree[tool][path]==0)
        {
            return 0;
        }
        // 有对应结点:
        else
        {
            // 遍历工具访问下一结点，结点通过数++
            tool = Tree[tool][path];
        }
    }

    // 返回结点作为末尾数:
    return endd[tool];
}

void word_delete(string word)
{
    // 没有该单词
    if(!word_duplicate(word))
    {
        return;
    }
    // 有该单词:
    else
    {
        int tool=1; // 遍历工具 - 从第 1 个结点开始
        int path=0; // 路径记录

        pass[tool]--; // 第一个结点通过数++

        // 遍历单词 从第二个结点开始记录
        for(const auto& c : word) // 第 1 & 2 结点之间的路径表示单词的第一个字母
        {
            path = c - 'a';  // 第 1 & 2 结点之间的路径

            pass[Tree[tool][path]]--;

            // 该路径没被复用过，仅仅记录一次:
            if(pass[Tree[tool][path]]==0)
            {
                Tree[tool][path]=0;
                return;
            }
            // 该路径被复用过:
            else
            {
                tool = Tree[tool][path];
            }
        }

        // 结点作为末尾数--
        endd[tool]--;
        return;
    }
}

int word_pre(string word)
{
    int tool=1; // 遍历工具 - 从第 1 个结点开始
    int path=0; // 路径记录

    // 遍历单词 从第二个结点开始记录
    for(const auto& c : word) // 第 1 & 2 结点之间的路径表示单词的第一个字母
    {
        path = c - 'a';  // 第 1 & 2 结点之间的路径

        // 没有该结点:
        if(Tree[tool][path]==0)
        {
            return 0;
        }
        // 有对应结点:
        else
        {
            // 遍历工具访问下一结点
            tool = Tree[tool][path];
        }
    }
    // 返回结点通过数:
    return pass[tool];
}

void clear()
{
    memset(&Tree[0][0] , 0 , sizeof(int)*26*(cnt+1));
    memset(&pass[0] , 0 , sizeof(int)*(cnt+1));
    memset(&endd[0] , 0 , sizeof(int)*(cnt+1));
    cnt=1;
}

int main()
{
    cnt=1;

    int n;
    cin >> n;

    while(n--)
    {
        int x;
        string word;

        cin >> x >> word;

        if(x==1)
        {
            word_insert(word);
        }
        else if(x==2)
        {
            word_delete(word);
        }
        else if(x==3)
        {
            cout << (word_duplicate(word)>0 ? "YES" : "NO") << endl;
        }
        else
        {
            cout << word_pre(word) << endl;
        }
    }

    clear();

    return 0;
}