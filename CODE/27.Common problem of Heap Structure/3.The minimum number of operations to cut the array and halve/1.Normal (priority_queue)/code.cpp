// double + priority_queue

// Time Complexity：O(N * log2(N))

// Space Complexity：O(N)

#include<bits/stdc++.h>

using namespace std;

int HalveArray(vector<int>& v) 
{
    auto f = [](const auto& a , const auto& b)
    {
        return a < b;
    };  

    priority_queue<double , vector<double> , decltype(f)> MaxHeap(f);

    double sum=0;

    for(const auto& e : v)
    {
        int i=e;
        double x = double(i);
        MaxHeap.push(x);
        sum += x;
    }

    double goal = sum/2;
    double add = 0;
    double cur = 0; 
    int ans = 0;

    while(add < goal)
    {
        double t = MaxHeap.top();
        MaxHeap.pop();
        t = t/2;
        add += t;
        MaxHeap.push(t);
        ans++;
    }
    
    return ans;
}


int main()
{
    vector<int> v;
    int n=0 , x=0;
    scanf("%d" , &n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &x);
        v.push_back(x);
    }

    printf("%d" , HalveArray(v));

    return 0;
}