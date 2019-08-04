#include <bits/stdc++.h>
using namespace std;

class BinaryTree {
  public:
    int value;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int value);
    void insert(vector<int> values, int i = 0);
};

int solve(BinaryTree *root, int &ans){
		if(root == NULL){
			return 0;
		}
		
		int l = solve(root->left,ans);
		int r = solve(root->right,ans);
		
		int ancestor_sum = max(max(l,r)+root->value,root->value);
		int branch_sum = root->value+l+r;
		ans = max(ans,max(ancestor_sum,branch_sum));
		
		return ancestor_sum;
		
}

int maxPathSum(BinaryTree tree) {
  // Write your code here.
	int ans = INT_MIN;
	int max_sum_till_root = solve(&tree,ans);
	return ans;
}