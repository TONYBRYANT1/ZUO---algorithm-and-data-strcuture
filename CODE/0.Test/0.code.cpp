#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 3000001;
int tree[MAXN][2];
int cnt;
int high;

void build(vector<int>& nums) {
    cnt = 1;
    int maxNum = INT_MIN;
    for (int num : nums) {
        maxNum = max(num, maxNum);
    }
    high = 31 - log2(maxNum);
    for (int num : nums) {
        int cur = 1;
        for (int i = high, path; i >= 0; i--) {
            path = (num >> i) & 1;
            if (tree[cur][path] == 0) {
                tree[cur][path] = ++cnt;
            }
            cur = tree[cur][path];
        }
    }
}

int maxXor(int num) {
    int ans = 0;
    int cur = 1;
    for (int i = high, status, want; i >= 0; i--) {
        status = (num >> i) & 1;
        want = status ^ 1;
        if (tree[cur][want] == 0) {
            want ^= 1;
        }
        ans |= (status ^ want) << i;
        cur = tree[cur][want];
    }
    return ans;
}

int findMaximumXOR(vector<int>& nums) {
    build(nums);
    int maxXorVal = 0;
    for (int num : nums) {
        maxXorVal = max(maxXorVal, maxXor(num));
    }
    return maxXorVal;
}

int main() {
    int maxx=20;
    int i=0;
    while(maxx>1)
    {
        maxx >>= 1;
        i++;
    }
    cout << i << endl;
}
