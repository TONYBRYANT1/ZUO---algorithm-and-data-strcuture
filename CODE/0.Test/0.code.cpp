#include<bits/stdc++.h>

using namespace std;

bool f(int energy , const vector<int>& pillars , int maxx)
{
    for(const auto& e : pillars)
    {
        if(e<= energy)
        {
            energy += (energy - e);
        }
        else
        {
            energy -= (e - energy);
        }

        if(energy >= maxx)
        {
            return true;
        }

        if(energy < 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    srand((unsigned int)time(NULL));
    int a = rand();
    int b = rand();
    cout << a << endl;
    cout << b << endl;
    return 0;
}