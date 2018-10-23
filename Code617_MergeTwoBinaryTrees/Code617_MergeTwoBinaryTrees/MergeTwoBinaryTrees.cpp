/*
https://leetcode.com/problems/merge-two-binary-trees/description/
*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
	if (t1 == nullptr&&t2 == nullptr){
		return nullptr;
	}
	if (t1 == nullptr&&t2 != nullptr){
		return t2;
	}
	if (t1 != nullptr&&t2 == nullptr){
		return t1;
	}
	t1->val = t1->val + t2->val;
	t1->left = mergeTrees(t1->left, t2->left);
	t1->right = mergeTrees(t1->right, t2->right);
	return t1;
}

int main(){
	TreeNode Node1(1), Node2(1), Node3(2), Node4(2), Node5(3), Node6(3), Node7(4), Node8(5), Node9(7);
	Node1.left = &Node5;
	Node1.right = &Node4;
	Node5.left = &Node8;
	Node3.left = &Node2;
	Node3.right = &Node6;
	Node2.right = &Node7;
	Node6.right = &Node9;
	TreeNode* t1 = &Node1;
	TreeNode* t2 = &Node3;

	TreeNode* mergeTree = mergeTrees(t1, t2);
	queue<TreeNode*>tree;
	tree.push(mergeTree);
	int preNum = 1;
	int curNum = 0;
	while (!tree.empty()){
		TreeNode* temp = tree.front();
		tree.pop();
		cout << temp->val;
		preNum--;
		if (temp->left != nullptr){
			tree.push(temp->left);
			curNum++;
		}
		if (temp->right != nullptr){
			tree.push(temp->right);
			curNum++;
		}
		if (preNum == 0){
			preNum = curNum;
			curNum = 0;
			cout << endl;
		}
		else{
			cout << " ";
		}
	}
	system("pause");
	return 0;
}