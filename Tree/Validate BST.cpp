#include <bits/stdc++.h>
class BST {
  public:
    int value;
    BST* left;
    BST* right;
  
    BST(int val);
    BST& insert(int val);
};

bool solve(BST *root, int minm, int maxm){
		if(root == NULL)
			return true;
		
		if((minm != INT_MAX && root->value < minm)  || (maxm != INT_MIN && root->value >= maxm))
			return false;
			
		return (solve(root->left,minm,root->value) && solve(root->right, root->value, maxm));
}

// O(n) time | O(d) space
bool validateBst(BST* tree) {
  // Write your code here.
	return solve(tree,INT_MAX,INT_MIN);
}