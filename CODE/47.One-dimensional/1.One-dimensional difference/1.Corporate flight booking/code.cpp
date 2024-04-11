// 一股脑将操作都做完，最后总结答案

class Solution 
{
private:
    vector<int> ans;
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
    {
        // 0 1 2 3 ... n n+1
        ans.resize(n+2);

        for(const auto& book : bookings)
        {
            ans[book[0]] += book[2];
            ans[book[1]+1] -= book[2];
        }

        for(int i=1 ; i<=n ; i++)
        {
            ans[i] = ans[i-1] + ans[i];
        }

        ans.erase(ans.begin()); // 删除 [0]
        ans.erase(ans.end()-1); // 删除 [n+1]

        return ans;
    }
};