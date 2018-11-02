/*
https://leetcode.com/problems/invert-binary-tree/description/
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static const auto kSpeedUp = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr){
			return root;
		}
		TreeNode *temp = invertTree(root->left);
		root->left = invertTree(root->right);
		root->right = temp;
		return root;
	}
	void levelTravel(TreeNode* root){
		if (root == nullptr){
			return;
		}
		queue<TreeNode*>Node;
		Node.push(root);
		while (!Node.empty()){
			int size = Node.size();
			for (int i = 0; i < size; i++){
				TreeNode *temp = Node.front();
				cout << temp->val << " ";
				Node.pop();
				if (temp->left != nullptr){
					Node.push(temp->left);
				}
				if (temp->right != nullptr){
					Node.push(temp->right);
				}
			}
			cout << endl;
		}
	}
};

int main(){
	TreeNode Node1(4), Node2(2), Node3(7), Node4(1), Node5(3), Node6(6), Node7(9);
	Node1.left = &Node2;
	Node1.right = &Node3;
	Node2.left = &Node4;
	Node2.right = &Node5;
	Node3.left = &Node6;
	Node3.right = &Node7;
	Solution s;
	s.levelTravel(&Node1);
	TreeNode *root = s.invertTree(&Node1);
	s.levelTravel(root);
	system("pause");
	return 0;
}