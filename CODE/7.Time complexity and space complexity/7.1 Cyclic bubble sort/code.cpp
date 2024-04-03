//不要轻易通过层数来判断时间复杂度 如这里的 while : O(N^2)

#include<bits/stdc++.h>

using namespace std;

const int N = 1e4+10;

int n , arr[N];

void swap(int arr[] , int i , int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void CyclicBubbleSort()
{
    int end=n-1 , i=0;
    while(end>0)
    {
        if(arr[i] > arr[i+1])
        {
            swap(arr , i , i+1);
        }
        
        if(i<end-1)
        {
            i++;
        }
        else
        {
            end--;
            i=0;
        }
    }
}

int main()
{
    scanf("%d" , &n);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%d" , &arr[i]);
    }

    clock_t start , end;
    if(n>=2)
    {
        start = clock();
        CyclicBubbleSort();
        end = clock();
    }

    for(int i=0 ; i<n ; i++)
    {
        printf("%d " , arr[i]);
    }
    cout << endl;
    cout << end - start/CLOCKS_PER_SEC << " s" << endl;
    return 0;
}
