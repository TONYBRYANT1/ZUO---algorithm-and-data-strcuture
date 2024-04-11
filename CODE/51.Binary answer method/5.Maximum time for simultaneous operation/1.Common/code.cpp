// 最长共同使用时间：
// 1）前提：
//          完整电池 --- 单个电池时长 > 同时运行时长  t   的电池
//          这种电池 一个就可以完全支撑一台电脑
//  
//          碎片电池 --- 单个电池时长 <= 同时运行时长 t   的电池
//          这种电池 一个或多个共用才能支撑一台电脑 
//
// 2）条件： 
//          假设 k 台电脑想要共同运行 t(minutes)
//          电池集：batteries:[a , b , c , d , e , f] 
//          其中 max(batteries[i]) = a
//
// 3）结论：如果 a <= t 即电池集中的最大电池容量 <= 单个电脑运行 t时间所需电量
//         ==> 电池集中的所有电池都是碎片电池
//         当 sum_batteries >= k*t 时：能够支撑 k 台电脑想要共同运行 t(minutes)
//         当 sum_batteries <  k*t 时：不能够支撑 k 台电脑想要共同运行 t(minutes)

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution 
{
private:
	// 看看这些电池能不能支撑 k台电脑 同时运行 t (minutes) 
	bool f(const vector<int>& batteries , int k , int t)
	{
		// 完整电池 --- 单个电池时长 > 同时运行时长  t   的电池
		// 这种电池 一个就可以完全支撑一台电脑
		 
		// 碎片电池 --- 单个电池时长 <= 同时运行时长 t   的电池
		// 这种电池 一个或多个共用才能支撑一台电脑 
		
		ll sum=0; // 碎片电池 电量之和 
		
		for(const auto& battery : batteries)
		{
			// 完整电池：
			if(battery > t)
			{
				k--;	
			}	
			// 碎片电池
			else
			{
				sum += battery; 
			} 
		} 
		
		// 看看 碎片电池电量之和 能否支撑 剩下的电脑 同时使用 t(minutes)   
		// 剩下的电脑 --- 每一个完整电池都可以应对一台电脑，其余的电脑为剩下的电脑 
		if(sum >= (ll)((ll)k * (ll)t))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
public:
    long long maxRunTime(int k, vector<int>& batteries) 
	{
        // 二分 + 分析(贪心)
        //
		// 分析：通过  整个电池集是否为碎片电池  来缩短范围
		// 1）整个电池集是碎片电池集：
		//    假定一个 t 表示电池集所能支持 k 台电脑 同时运行 t(minutes) 
		//    ==> t >= maxx		 其中 maxx = max(batteries[i])
		//    (1)如果能够支撑  k 台电脑 同时运行 t(minutes)  
		//    ==> sum >= t * k
		//    (2)==> sum >= maxx * k 
		//	  (1) <==> (2)：(1)、(2)等价
		//    就一定能够求出 t
		// 相关代码：
		ll sum=0;
		int maxx = batteries[0];
		for(const auto& battery : batteries)
		{
			sum += battery;
			maxx = max(maxx , battery);
		}
		
		// 电池集是碎片电池集时
		if(sum >= (ll)((ll)maxx * (ll)k))
		{
			return (ll)(sum/k); // 电池集是碎片电池集时：t 最大能达到 (sum/k)	
		}
		// 2）整个电池集不是碎片电池集：
		//    说明 maxx > t
		//    那我们就可以缩限范围：[0 , maxx] 在此区间上用二分求答案 
		// 
		else
		{
			int l = 0 , r = maxx;
			int ans=0;
			while(l<=r)
			{
				int mid = (l + ((r-l)>>1)) ;
				
				// 看看能否支撑 k 台电脑 mid (minutes) 
				// 1）能够支撑，记录答案，看看能不能撑更久 
				if(f(batteries , k , mid))
				{
					ans = mid;
					l = mid+1;
				}
				// 2）撑不了 mid (minutes)，试试时间短一些能不能撑得住 
				else
				{
					r = mid-1;
				}
			}
			
			return ans; 
		}
    }
};
