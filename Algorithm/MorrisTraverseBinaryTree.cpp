#include <iostream>
#include <cstdlib>


using namespace std;




//how to traverse a binary search tree with O(1) space complexity
//here is a solution called Morris TraverseBinaryTree Algorithm
//it traverse by using BinaryThreadTree


struct TreeNode
{
	int val;
	TreeNode* pLeft;
	TreeNode* pRight;
	TreeNode(int value){
		val = value;
		pLeft = NULL;
		pRight = NULL;
	}
};


void morrisTraverseInOrder(TreeNode* root){
	TreeNode* cur = root;
	while(cur){
		if ( cur->pLeft == NULL ){
			cout<<cur->val<<" ";
			cur = cur->pRight;
		}else{
			TreeNode* lastTraverseNode = cur->pLeft;
			while(lastTraverseNode->pRight != NULL && lastTraverseNode->pRight != cur){
				lastTraverseNode = lastTraverseNode->pRight;
			}
			if (lastTraverseNode->pRight == NULL){
				lastTraverseNode->pRight = cur;
				cur = cur->pLeft;
			}else{  //  lastTraverseNode->pRight == cur
				lastTraverseNode->pRight = NULL;
				cout<<cur->val<<" ";
				cur = cur->pRight;
			}
		}
	}
}



void morrisTraversePreOrder(TreeNode* root){
	TreeNode* cur = root;
	while(cur){
		if (cur->pLeft == NULL){
			cout<<cur->val<<" ";
			cur = cur->pRight;
		}else{
			TreeNode* lastTraverseNode = cur->pLeft;
			while(  lastTraverseNode->pRight != NULL && lastTraverseNode->pRight != cur ){
				lastTraverseNode = lastTraverseNode->pRight;
			}
			if ( lastTraverseNode->pRight == NULL){
				cout<<cur->val<<" ";
				lastTraverseNode->pRight = cur;
				cur = cur->pLeft;
			}else{
				lastTraverseNode->pRight = NULL;
				cur = cur->pRight;
			}
		}
	}
}
















int main(){
TreeNode* a = new TreeNode(10);
TreeNode* b = new TreeNode(6);
TreeNode* c = new TreeNode(14);
TreeNode* d = new TreeNode(3);
TreeNode* e = new TreeNode(8);
TreeNode* f = new TreeNode(11);
TreeNode* g = new TreeNode(16);

a->pLeft = b;
a->pRight = c;
b->pLeft = d;
b->pRight = e;
c->pLeft = f;
c->pRight = g;

morrisTraverseInOrder(a);
cout<<endl;
morrisTraversePreOrder(a);




}