// 计算等位时间
// 给定一个数组arr长度为n，表示n个服务员，每服务一个人的时间
// 给定一个正数m，表示有m个人等位，每个人按有空就插的方式选择服务窗口
// 如果你是刚来的人，请问你需要等多久？
// 假设m远远大于n，比如n <= 10^3, m <= 10^9，该怎么做是最优解？
// 谷歌的面试，这个题连考了2个月
// 找不到测试链接，所以用对数器验证

// m 确定时，不论前面的人怎么选，只要是按照有空就插的方式选择服务窗口，排队时间都一样

#include<bits/stdc++.h>

using namespace std;

class Solution
{
private:
	class MyComparator
	{
	public:
		bool operator() (const int& a , const int& b) const
		{
			return a < b;	
		}	
	};	

private:
    // map({处理时间，服务速度})
	multimap<int , int , MyComparator> map;
	
public:
    // 堆方法：
    // 时间复杂度：O(m * log2(N))       N - 服务员数量
    // 空间复杂度：O(N)
	int Waiting_for_service1(vector<int>& arr , int m)
	{
        // arr - 服务生		arr[i] - 服务速度
	    // m - 前方还有 m 人未被服务 
		map.clear(); 
		// 将服务生放入堆区 
		for(const auto& e : arr)
		{
			map.insert({0 , e}); 
		}
		
		while(m--)
		{
			// 服务生开始服务 

            int x = (*map.begin()).first; // 处理时间
            int y = (*map.begin()).second; // 服务速度
			
			// 更新 map
			map.erase(map.begin());
			map.insert({x+y , y}); 
		
		}
		
		return (*map.begin()).first;
	}

private:
    // 所用服务员共同工作 mid 时间，看看共能接待多少顾客(接待，但业务可以刚刚开始)
    int f(const vector<int>& arr , int mid)
    {
        int anss=0;
        for(const auto& e : arr)
        {
            anss += (1 + (mid/e));
        }

        return anss;
    }

public:
    // 二分：
    // 时间复杂度：O(log2(min(arr)*m) * N)      N --- 服务员人数
    // 额外空间复杂度：O(1)
    int Waiting_for_service2(vector<int>& arr , int m)
    {
        // 找等待时间的范围：[0 , min(arr)*m]
        int minn=arr[0];
        for(const auto& e : arr)
        {
            minn = min(minn , e);
        }

        int l=0 , r=(minn*m);
        int ans=0;

        while(l<=r)
        {
            int mid = l + ((r-l)>>1);

            // 看看 服务员服务mid 时间 共可以接待多少个客户(接待，但业务可以刚刚开始)
            // 1）可以接待 m+1 个人，说明等待 mid 时间 自己可以被接待
            //    记录答案，往左走，看看等待更少时间 自己能否被接待
            if(f(arr , mid) >= (m+1))
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }

        return ans;
    }
};

int main()
{
    // 对数器：
    int n;
    vector<int> arr;
    int m;

    scanf("%d" , &n);

    // n 组测试数据：
    printf("测试开始：\n");
    for(int i=0 ; i<n ; i++)
    {
        // 测试数据准备阶段：
        arr.clear();

        // int t = rand()%1001;
        int t = 2000 + rand()%50;
        while(t--)
        {
            int x = 200+rand()%5;
            arr.push_back(x);
        }

        m = 50000+rand()%5;

        // 测试答案：
        Solution slt;
        int x = slt.Waiting_for_service1(arr , m);
        int y = slt.Waiting_for_service2(arr , m);
        if(x != y)
        {
            cout << "出现问题!" << endl;
        }
        
    }
    printf("测试结束：\n");
	return 0;
}