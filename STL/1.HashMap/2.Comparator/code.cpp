// 对于无序的 unorderd_map来说，不能用比较器对其进行排序，因为它本身就是无序的

#include<bits/stdc++.h>

using namespace std;

struct Comparator
{
    bool operator() (const string& a , const string& b) const
    {
        return a < b;
    }
};

int main()
{
    map<string , int , Comparator> HashMap;
    HashMap.insert({"A" , 50});
    HashMap.insert({"B" , 10});
    HashMap.insert({"C" , 30});
    HashMap.insert({"D" , 10});
    HashMap.insert({"E" , 20});
    HashMap.insert({"F" , 90});
    for(const auto& pair : HashMap)
    {
        cout << pair.first << " " << pair.second << endl;
    }
    return 0;
}