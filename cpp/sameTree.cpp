// sameTree.cpp

#include <iostream>

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q){
	if(p == NULL && q == NULL) return true;
	else if( (p == NULL && q != NULL) || (p != NULL && q== NULL) ) return false;
	else if((*p).val != (*q).val) return false;
	else if(isSameTree((*p).left,(*q).left) && isSameTree((*p).right, (*q).right) ) return true;
	else return false;
}

