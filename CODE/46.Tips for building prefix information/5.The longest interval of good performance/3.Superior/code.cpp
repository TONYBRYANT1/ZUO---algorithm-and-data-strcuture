// 走一步看一步，不像 common 方法 直接先遍历一遍求 sum[] 和 hashmap

class Solution
{
private:
    unordered_map<int , int> hashmap;
    vector<int> arr;
    int n;

private:
    int f()
    {
        int sum=0 , aim=0 , l=0 , length=0;

        hashmap.clear();
        
        for(int r=0 ; r<n ; r++)
        {
            sum += arr[r];

            if(sum >= 1)
            {
                length = (r+1);
            }
            else
            {
                if(hashmap.find(sum-1) != hashmap.end())
                {
                    l = hashmap[sum-1];
                    length = max(length , r-l);
                }
            }

            if(hashmap.find(sum) == hashmap.end())
            {
                hashmap.insert({sum , r});
            }
        }

        return length;
    }

public:
    int longestWPI(vector<int>& hours) 
    {
        n = hours.size();
        arr.clear();
        arr.assign(n , 0);

        for(int i=0 ; i<n ; i++)
        {
            arr[i] = hours[i]>8 ? 1 : -1;
        }

        return f();
    }   
};