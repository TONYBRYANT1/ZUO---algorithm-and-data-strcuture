#include<bits/stdc++.h>

using namespace std;

class NumMatrix 
{
public:
    vector<vector<int>> matrix;
    int row , col;
public:
    NumMatrix(vector<vector<int>>& arr) 
    {
        row = arr.size();
        col = arr[0].size();
        matrix.resize((row+1) , vector<int>((col+1) , 0));

        // 留出 0行 0列
        for(int i=1 ; i<=row ; i++)
        {
            for(int j=1 ; j<=col ; j++)
            {
                matrix[i][j] = arr[i-1][j-1];
            }
        }
        
        // 计算前缀和：
        for(int i=1 ; i<=row ; i++)
        {
            for(int j=1 ; j<=col ; j++)
            {
                matrix[i][j] = matrix[i][j] + matrix[i][j-1] + matrix[i-1][j] - matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int a, int b, int c, int d) 
    {
        // 下标对应：
        a++ , b++ , c++ , d++;

        // 计算区域和：
        int ans = matrix[c][d] - matrix[c][b-1] - matrix[a-1][d] + matrix[a-1][b-1];

        return ans;
    }
};

int main()
{
    vector<vector<int>> arr;
    vector<int> arr1 = {1 , 2 , 3 , 4 , 5};
    vector<int> arr2 = {4 , 23 , 2 , 3 , 1};
    vector<int> arr3 = {1 , 2 , 3 , 4 , 5};
    vector<int> arr4 = {4 , 23 , 2 , 3 , 1};
    vector<int> arr5 = {1 , 2 , 3 , 4 , 5};

    arr.push_back(arr1);
    arr.push_back(arr2);
    arr.push_back(arr3);
    arr.push_back(arr4);
    arr.push_back(arr5);


    NumMatrix nm(arr);
    for(int i=0 ; i<5 ; i++)
    {
        for(int j=0 ; j<5 ; j++)
        {
            printf("%-2d " , nm.matrix[i][j]);
        }
        cout << endl;
    }

    cout << nm.sumRegion(1 , 1 , 2 , 2) << endl;
    cout << nm.sumRegion(2 , 2 , 1 , 1) << endl;
    cout << nm.sumRegion(2 , 2 , 3 , 3) << endl;
    cout << nm.sumRegion(3 , 3 , 2 , 2) << endl;
    cout << nm.sumRegion(3 , 3 , 4 , 4) << endl;
    cout << nm.sumRegion(4 , 4 , 3 , 3) << endl;


    return 0;
}