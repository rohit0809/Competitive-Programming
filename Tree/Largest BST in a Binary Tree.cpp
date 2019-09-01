#include <bits/stdc++.h>
#define ll long long int 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define debug 0

using namespace std;

struct Node{
	struct Node* left;
	struct Node* right;
	int data;
};

struct Node * newNode(int val){
	struct Node *node = new Node;
	node->data = val;
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

struct Node_info{
	int siz;
	int maxm;
	int minm;
	int ans;
	bool isBST;
};

Node_info largestBSTBT(Node *root){
	if(root == NULL){
		return {0,INT_MIN,INT_MAX,0,true};
	}
	
	if(root->left == NULL && root->right == NULL){
		return {1,root->data,root->data,1,true};
	}
	
	Node_info l = largestBSTBT(root->left);
	Node_info r = largestBSTBT(root->right);
	
	Node_info ret;
	
	ret.siz = l.siz + r.siz + 1;
	
	if(l.isBST && r.isBST && l.maxm < root->data && r.minm > root->data){
		ret.minm = min(l.minm,min(r.minm,root->data));
		ret.maxm = max(l.maxm,max(r.maxm,root->data));
		
		ret.ans = ret.siz;
		ret.isBST = true;
		
		return ret;
	}
	
	ret.ans = max(l.ans,r.ans);
	ret.isBST = false;
	
	return ret;
}


int main() {
	
    int n,i,k;
	
	struct Node *root = newNode(60); 
    root->left = newNode(65); 
    root->right = newNode(70); 
    root->left->left = newNode(50);
    
    cout<<largestBSTBT(root).ans<<"\n";
	
	
	return 0;
}