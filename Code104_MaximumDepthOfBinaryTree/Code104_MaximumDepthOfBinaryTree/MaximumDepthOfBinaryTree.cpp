/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

void allDepth(TreeNode* root, int depth, vector<int>&Depth) {
	if (root == nullptr) {
		return;
	}
	if (root->left == nullptr&&root->right == nullptr) {
		Depth.push_back(depth + 1);
	}
	allDepth(root->left, depth + 1, Depth);
	allDepth(root->right, depth + 1, Depth);
}

int maxDepth(TreeNode* root) {
	if (root == nullptr)
		return 0;
	vector<int>Depth;
	int depth = 0;
	allDepth(root, depth, Depth);
	vector<int>::iterator maxDepth = max_element(Depth.begin(), Depth.end());
	return *maxDepth;
}

int main() {
	TreeNode Node1(1), Node2(2);
	Node1.left = &Node2;
	cout << maxDepth(&Node1) << endl;
	system("pause");
	return 0;
}