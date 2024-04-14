#include<bits/stdc++.h>

using namespace std;

typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode , *P;

class Solution 
{
private:
	bool same(P& r1 , P& r2)
	{
		if(r1==nullptr && r2==nullptr)
		{
			return true;
		}
		else if(r1!=nullptr && r2!=nullptr)
		{
			return r1->val == r2->val && same(r1.left , r2) && same(l1.right , r2);
		}
		else
		{
			return false;
		}
	}
public:
    bool isSubtree(TreeNode* r1, TreeNode* r2) 
    {
        if(r1==nullptr && r2==nullptr)
		{
			return true;
		}
		else if(r1!=nullptr && r2!=nullptr)
		{
			return same(r1 , r2);
		}
		else
		{
			return false;
		}
    }
};