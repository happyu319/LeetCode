/*
https://leetcode.com/problems/trim-a-binary-search-tree/description/
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static const auto kSpeedUp = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (root == nullptr || L > R){
			return nullptr;
		}
		if (root->val < L){
			return trimBST(root->right, L, R);
		}else if (root->val>R){
			return trimBST(root->left, L, R);
		}
		else{
			root->left = trimBST(root->left, L, R);
			root->right = trimBST(root->right, L, R);
		}
		return root;
	}
	void preOrderTraversal(TreeNode* root){
		if (root == nullptr){
			return;
		}
		cout << root->val << " ";
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
};

int main(){
	TreeNode Node0(0), Node1(1), Node2(2), Node3(3), Node4(4);
	Node3.left = &Node0;
	Node3.right = &Node4;
	Node0.right = &Node2;
	Node2.left = &Node1;
	int L = 1, R = 3;
	Solution s;
	TreeNode *root = s.trimBST(&Node3, L, R);
	s.preOrderTraversal(root);
	cout << endl;
	system("pause");
	return 0;
}