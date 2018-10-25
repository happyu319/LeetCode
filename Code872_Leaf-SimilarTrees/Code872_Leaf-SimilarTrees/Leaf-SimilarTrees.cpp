/*
https://leetcode.com/problems/leaf-similar-trees/description/
*/
#include <iostream>
#include <vector>
#include <stack>
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
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	void preOrder(TreeNode* root, vector<int>&leaf){
		stack<TreeNode*>tree;
		tree.push(root);
		while (!tree.empty()){
			TreeNode* temp = tree.top();
			tree.pop();
			if (temp->left == nullptr&&temp->right == nullptr){
				leaf.push_back(temp->val);
			}
			if (temp->right != nullptr){
				tree.push(temp->right);
			}
			if (temp->left != nullptr){
				tree.push(temp->left);
			}
		}
	}
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr&&root2 == nullptr){
			return true;
		}
		if (root1 == nullptr || root2 == nullptr){
			return false;
		}
		vector<int>leaf1;
		vector<int>leaf2;
		preOrder(root1, leaf1);
		preOrder(root2, leaf2);
		return leaf1 == leaf2;
	}
};

int main(){
	TreeNode Node1(1), Node2(2), Node3(3), Node4(4), Node5(5), Node6(6), Node7(7), Node8(8), Node9(9), Node22(2), Node24(4), Node25(5);
	Node1.left = &Node2;
	Node1.right = &Node3;
	Node3.left = &Node4;
	Node3.right = &Node5;
	Node6.left = &Node7;
	Node6.right = &Node8;
	Node7.right = &Node22;
	Node8.left = &Node9;
	Node9.left = &Node24;
	Node9.right = &Node25;
	Solution s;
	cout << s.leafSimilar(&Node1, &Node6) << endl;
	system("pause");
	return 0;
}