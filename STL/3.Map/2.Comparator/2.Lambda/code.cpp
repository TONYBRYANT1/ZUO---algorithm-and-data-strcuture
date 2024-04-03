

#include<bits/stdc++.h>

using namespace std;

int main()
{
    auto Comparator = [](const int& a , const int& b){return a < b;};
    map<int , int , decltype(Comparator)> Map(Comparator);
    Map.insert({1 , 6});
    Map.insert({6 , 1});
    Map.insert({4 , 3});
    Map.insert({3 , 4});
    Map.insert({5 , 2});
    Map.insert({2 , 5});

    for(const auto& pair : Map)
    {
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}