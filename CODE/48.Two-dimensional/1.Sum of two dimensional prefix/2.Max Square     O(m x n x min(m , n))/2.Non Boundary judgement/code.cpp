#include<bits/stdc++.h>

using namespace std;

class Solution 
{
private:
	vector<vector<int>> matrix; 
	int row , col;

private:
	void matrix_build()
	{
		for(int i=1 ; i<=row ; i++)
		{
			for(int j=1 ; j<=col ; j++)
			{
				matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
			}	
		}	
	}
	
	int matrix_sum(int a , int b , int c , int d)
	{
		return matrix[c][d] - matrix[c][b-1] - matrix[a-1][d] + matrix[a-1][b-1];
	} 
	
public:
    int largest1BorderedSquare(vector<vector<int>>& g) 
	{
		row = g.size();
		col = g[0].size();
		
		matrix.clear();
		matrix.resize((row+2) , vector<int>((col+2) , 0));
		
		for(int i=0 ; i<row ; i++)
		{
			for(int j=0 ; j<col ; j++)
			{
				matrix[i+1][j+1] = g[i][j];
			}
		}
		
		matrix_build();
		
		if(matrix_sum(1 , 1 , row , col) == 0)
		{
			return 0;
		}
		else
		{
			int ans=1;
			
			for(int a=1 ; a<=row ; a++)
			{
				for(int b=1 ; b<=col ; b++)
				{
					for(int c=(a+ans) , d=(b+ans) , l=ans+1 ; (c<=row)&&(d<=col) ; c++ , d++ , l++)
					{
						if((matrix_sum(a , b , c , d) - matrix_sum(a+1 , b+1 , c-1 , d-1)) == ((l-1)<<2) )	
						{
							ans = l;
						}
					}	
				} 
			}
			
			return pow(ans , 2);
		}
    }
};
