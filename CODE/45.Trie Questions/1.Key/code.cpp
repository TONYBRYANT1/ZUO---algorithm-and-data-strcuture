#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+10;

class Solution 
{
private:
    int cnt;
    int Tree[N][13];  //  0   1   2   3   4   5   6   7   8   9  10  11
    int pass[N];      // '0' '1' '2' '3' '4' '5' '6' '7' '8' '9' '-' '#' 
    int endd[N];
    vector<int> ans;

private:
    string vec_to_str(vector<int> arr)
    {
        string ans;
        ans.clear();

        for(int i=1 ; i<=arr.size()-1 ; i++)
        {
            ans.append(to_string(arr[i]-arr[i-1]));
            ans+='#';
        }
        return ans;
    }

    // 12种方向的转化：
    int transform(const char& c)
    {
        // '0' ~ '9' 
        if((c>='0') && (c<='9'))
        {
            return (c-'0');
        }
        // '-'
        else if(c=='-')
        {
            return 10;
        }
        else
        {
            return 11;
        }
    }

    void word_insert(string word)
    {
        int tool=1;
        int path=0;

        pass[tool]++;

        for(const auto& c : word)
        {
            path = transform(c);

            if(Tree[tool][path]==0)
            {
                Tree[tool][path] = ++cnt;
            }

            tool = Tree[tool][path];
            pass[tool]++;
        }

        endd[tool]++;

        return;
    }

    int word_find(string word)
    {
        int tool=1;
        int path=0;

        for(const auto& c : word)
        {
            path = transform(c);
            if(Tree[tool][path]==0)
            {
                return 0;
            }
            else
            {
                tool = Tree[tool][path];
            }
        }

        return pass[tool];
    }

    void word_clear()
    {
        memset(&Tree[0][0] , 0 , sizeof(int)*12*(cnt+1));
        memset(&pass[0] , 0 , sizeof(int)*(cnt+1));
        memset(&endd[0] , 0, sizeof(int)*(cnt+1));
        cnt=1;
    }
public:
    // 求与 b[x] 一致的 a[y] 有几个 ===> 拿着 b[x] 去找 a[y]
    vector<int> countConsistentKeys(vector<vector<int> >& b, vector<vector<int> >& a) 
    {   
        cnt=1;
        // 答案：
        ans.clear();

        // 将 a 作为答案放入 Trie
        for(const auto& e : a) // e 是 a[i]
        {
            word_insert(vec_to_str(e));
        }

        //
        for(const auto& e : b) // e 是 b[i]
        {
            ans.push_back(word_find(vec_to_str(e))); // 在 a 中找 b 为前缀的单词
        }

        word_clear();

        return ans;
    }
};



int main()
{
    return 0;
}