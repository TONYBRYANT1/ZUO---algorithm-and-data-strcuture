#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {1 , 4 , 1 , 5};
    string ans;
    ans.clear();
    for(int i=1 ; i<=arr.size()-1 ; i++)
    {
        ans.append(to_string(arr[i]-arr[i-1]));
        ans+='#';
    }
    cout << ans << endl;
}