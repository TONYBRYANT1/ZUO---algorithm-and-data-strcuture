#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution 
{
private:
    vector<ll> xs;
    vector<ll> ys;
    vector<vector<int>> matrix; // 差分 + 前缀和 数组
    int row , col; // 差分 + 前缀和 数组的规模
private:
    // 升序比较器：
    class MyComparator
    {
    public:
        bool operator()(const ll& a , const ll& b) const 
        {
            return a < b; // priority : a > b
        }
    };

private:    
    // 排序 + 去重：
    void vector_renew(vector<ll>& arr)
    {
        // 排序：
        sort(arr.begin() , arr.end() , MyComparator());
        // 去重：
        // std::unique(nums.begin(), nums.end())：
        // 这个函数的第一个参数是指向容器的起始位置的迭代器，第二个参数是指向容器的结束位置的迭代器。
        // 该函数的作用是将容器中连续的相同元素去重，只保留一个，并将重复的元素移动到容器的末尾，返回一个指向第一个重复元素的迭代器。
        arr.erase(unique(arr.begin() , arr.end()) , arr.end());

        return;
    }

    int xy_find(const vector<ll>& arr , const ll value)
    {
        int l=0 , r=(arr.size()-1);
        int ans=0;
        while(l<=r)
        {
            int mid = (l+r)/2; // l + (r-l)/2;
            if(arr[mid] >= value)
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        
        return ++ans; // 因为 差分 + 前缀和 数组加了一圈0，所以要加1
    }

    // 差分：
    void matrix_set(int a , int b , int c , int d)
    {
        matrix[a][b] += 1;
        matrix[c+1][b] -= 1;
        matrix[a][d+1] -= 1;
        matrix[c+1][d+1] += 1;
        return;
    }

    // 前缀和：
    void matrix_build()
    {
        for(int i=1 ; i<=row ; i++)
        {
            for(int j=1 ; j<=col ; j++)
            {
                matrix[i][j] += matrix[i][j-1] + matrix[i-1][j] - matrix[i-1][j-1];
            }
        }
        return;
    }

public:
    int fieldOfGreatestBlessing(vector<vector<int>>& forceField) 
    {
        // 一、为了规避 0.5 的问题，我们将场区扩大一倍：
        // 坐标系上图像扩大一倍的方法：
        // 原：X左 = (x - r/2)   --->   现：X左 = 2*(x - r/2) = (2*x - r)
        // 原：X右 = (x + r/2)   --->   现：X右 = 2*(x + r/2) = (2*x + r)
        // 原：Y上 = (y + r/2)   --->   现：Y上 = 2*(y + r/2) = (2*y + r)
        // 原：Y下 = (y - r/2)   --->   现：Y下 = 2*(y - r/2) = (2*y - r)

        // 二、离散化：
        // 因为坐标跨度太大 原：(0 <= wide <= 1e9) ---> 现：(0 <= wide <= 2e9)
        // 会浪费很多空间，所以进行离散化处理
        
        // 1）分别将 所有 X(X左、X右) 和 所有 Y(Y上、Y下) 分别放入集合中 xs 和 ys
        xs.clear() , ys.clear();
        for(const auto& field : forceField)
        {
            ll x = field[0] , y = field[1] , r = field[2];
            xs.push_back((x<<1) - r); // X左
            xs.push_back((x<<1) + r); // X右
            ys.push_back((y<<1) + r); // Y上
            ys.push_back((y<<1) - r); // Y下
        }

        // 2）排序 和 去重：
        vector_renew(xs);
        vector_renew(ys);

        // 三、差分 + 前缀和：
        // 1）处理前缀和数组的相关信息：
        row = xs.size();
        col = ys.size();
        matrix.clear();
        matrix.resize((row+2) , vector<int>((col+2) , 0));

        // 2）遍历 field , 进行差分处理：
        for(const auto& field : forceField)
        {
            ll x = field[0] , y = field[1] , r = field[2];
            // 通过 X(X左、X右) 和 所有 Y(Y上、Y下) 的值找到下标对应：
            int a = xy_find(xs , ((x<<1) - r)); // X左
            int b = xy_find(ys , ((y<<1) - r)); // Y下
            int c = xy_find(xs , ((x<<1) + r)); // X左
            int d = xy_find(ys , ((y<<1) + r)); // Y下
            // 差分：
            matrix_set(a , b , c , d);
        }

        // 前缀和
        matrix_build();

        int maxx=0;
        for(int i=1 ; i<=row ; i++)
        {
            for(int j=1 ; j<=col ; j++)
            {
                maxx = max(maxx , matrix[i][j]);
            }
        }
        
        return maxx;
    }
};

int main()
{
    vector<vector<int>> arr = {
        {0 , 0 , 1},
        {1 , 0 , 1}
    };
    Solution slt;
    cout << slt.fieldOfGreatestBlessing(arr);
    return 0;
}